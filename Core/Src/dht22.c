/*******************************************************************************
* @file    dht22.c
* @author  Naufal Faqiih
* @version 1.0.0
* @date    23 April 2024
* @brief   Driver for DHT22 temperature and humidity sensor
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "dht22.h"
#include "stm32f4xx_hal.h"

/* Private defines -----------------------------------------------------------*/
#define DHT22_START_DELAY_MS       (1U)      /* Start signal duration in ms */
#define DHT22_WAIT_DELAY_US        (20U)     /* Wait time after start in us */
#define DHT22_BIT_READ_DELAY_US    (30U)     /* Delay for bit reading in us */
#define DHT22_DATA_BITS            (40U)     /* Total data bits to read */
#define DHT22_BYTES_TO_READ        (5U)      /* 5 bytes (40 bits) */
#define DHT22_BITS_PER_BYTE        (8U)      /* Bits per byte */

/* Private function prototypes -----------------------------------------------*/
static void DHT22_SetPinOutput(GPIO_TypeDef* port, uint16_t pin);
static void DHT22_SetPinInput(GPIO_TypeDef* port, uint16_t pin);
static void DHT22_DelayMicroseconds(uint32_t us);
static uint8_t DHT22_ValidateChecksum(const uint8_t data[]);

/* Function implementations --------------------------------------------------*/

/**
  * @brief  Initialize DHT22 sensor
  * @param  port: GPIO port where sensor is connected
  * @param  pin: GPIO pin number where sensor is connected
  * @retval None
  */
void DHT22_Init(GPIO_TypeDef* port, uint16_t pin)
{
    /* MISRA Rule 17.2 - Parameter validation */
    if ((port != NULL) && (pin != 0U))
    {
        DHT22_SetPinOutput(port, pin);
    }
    /* No else - intentional for MISRA compliance */
}

/**
  * @brief  Read temperature and humidity from DHT22
  * @param  port: GPIO port where sensor is connected
  * @param  pin: GPIO pin number where sensor is connected
  * @param  temperature: Pointer to store temperature value
  * @param  humidity: Pointer to store humidity value
  * @retval DHT22_OK if successful, DHT22_ERROR otherwise
  */
uint8_t DHT22_Read(GPIO_TypeDef* port, uint16_t pin)
{
    uint8_t data[DHT22_BYTES_TO_READ] = {0U};
    uint8_t i = 0U;
    uint8_t j = 0U;
    uint8_t status = DHT22_ERROR;
		
		float temperature = 0.0f;
		float humidity = 0.0f;
    
    /* MISRA Rule 17.2 - Parameter validation */
    if ((port == NULL) || (pin == 0U) || (temperature == NULL) || (humidity == NULL))
    {
        return DHT22_ERROR;
    }
    
    /* Start communication */
    DHT22_SetPinOutput(port, pin);
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
    HAL_Delay(DHT22_START_DELAY_MS);
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
    DHT22_DelayMicroseconds(DHT22_WAIT_DELAY_US);
    
    /* Set pin as input */
    DHT22_SetPinInput(port, pin);
    
    /* Wait for sensor response */
    while (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET) 
    {
        /* MISRA Rule 14.1 - No empty while loops */
        __NOP(); /* Intentional no-operation */
    }
    
    while (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_RESET) 
    {
        __NOP();
    }
    
    while (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET) 
    {
        __NOP();
    }
    
    /* Read 40 bits of data */
    for (j = 0U; j < DHT22_BYTES_TO_READ; j++)
    {
        for (i = 0U; i < DHT22_BITS_PER_BYTE; i++)
        {
            while ((HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_RESET))
            {
                __NOP();
            }
            
            DHT22_DelayMicroseconds(DHT22_BIT_READ_DELAY_US);
            
            if (HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET)
            {
                data[j] |= (uint8_t)(1U << (7U - i));
            }
            
            while ((HAL_GPIO_ReadPin(port, pin) == GPIO_PIN_SET))
            {
                __NOP();
            }
        }
    }
    
    /* Convert and validate data */
    humidity = ((float)data[0] * 256.0F + (float)data[1]) / 10.0F;
    temperature = ((float)data[2] * 256.0F + (float)data[3]) / 10.0F;
    
    if (DHT22_ValidateChecksum(data))  // If checksum is valid
    {
        status = DHT22_IsAboveThreshold(temperature);  // Check if temperature is above threshold
    }
    
    return status;
}

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Configure GPIO pin as output
  * @param  port: GPIO port
  * @param  pin: GPIO pin number
  * @retval None
  */
static void DHT22_SetPinOutput(GPIO_TypeDef* port, uint16_t pin)
{
    GPIO_InitTypeDef GPIO_InitStruct = 
    {
        .Pin = pin,
        .Mode = GPIO_MODE_OUTPUT_PP,
        .Pull = GPIO_NOPULL,
        .Speed = GPIO_SPEED_FREQ_LOW
    };
    
    if ((port != NULL) && (pin != 0U))
    {
        HAL_GPIO_Init(port, &GPIO_InitStruct);
    }
}

/**
  * @brief  Configure GPIO pin as input
  * @param  port: GPIO port
  * @param  pin: GPIO pin number
  * @retval None
  */
static void DHT22_SetPinInput(GPIO_TypeDef* port, uint16_t pin)
{
    GPIO_InitTypeDef GPIO_InitStruct = 
    {
        .Pin = pin,
        .Mode = GPIO_MODE_INPUT,
        .Pull = GPIO_NOPULL
    };
    
    if ((port != NULL) && (pin != 0U))
    {
        HAL_GPIO_Init(port, &GPIO_InitStruct);
    }
}

/**
  * @brief  Microsecond delay implementation
  * @param  us: Delay duration in microseconds
  * @retval None
  */
static void DHT22_DelayMicroseconds(uint32_t us)
{
    uint32_t start = HAL_GetTick();
    uint32_t ms = us / 1000U;
    
    /* MISRA Rule 14.1 - No empty while loops */
    while ((HAL_GetTick() - start) < ms)
    {
        __NOP();
    }
}

/**
  * @brief  Validate DHT22 data checksum
  * @param  data: Array containing received data
  * @retval 1 if checksum valid, 0 otherwise
  */
static uint8_t DHT22_ValidateChecksum(const uint8_t data[])
{
    uint8_t checksum = 0U;
    
    if (data != NULL)
    {
        checksum = (uint8_t)(data[0] + data[1] + data[2] + data[3]);
    }
    
    return (checksum == data[4]) ? 1U : 0U;
}

/**
  * @brief  Check if the temperature is above 40 degrees Celsius
  * @param  temperature: The temperature value to check
  * @retval 1 if temperature is above 40 degrees Celsius, 0 otherwise
  */
bool DHT22_IsAboveThreshold(float temperature)
{
    return (temperature > 40.0f);
}

/************************ (C) COPYRIGHT Naufal Faqiih *****END OF FILE****/