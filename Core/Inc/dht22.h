/*******************************************************************************
* @file    dht22.h
* @author  Naufal Faqiih
* @version 1.0.0
* @date    23 April 2024
* @brief   Header file for DHT22 temperature and humidity sensor driver
*******************************************************************************/

#ifndef DHT22_H_
#define DHT22_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "stdbool.h"

/* Public constants ----------------------------------------------------------*/
#define DHT22_OK            (0U)    /* Operation successful */
#define DHT22_ERROR         (1U)    /* Operation failed */
#define DHT22_TIMEOUT       (2U)    /* Sensor timeout */

/* Public function prototypes ------------------------------------------------*/

/**
  * @brief  Initialize DHT22 sensor
  * @param  port: GPIO port where sensor is connected (GPIO_TypeDef*)
  * @param  pin: GPIO pin number where sensor is connected (uint16_t)
  * @retval None
  * @note   Must be called before any read operations
  * @warning GPIO pin must be configured as open-drain output
  */
void DHT22_Init(GPIO_TypeDef* port, uint16_t pin);

/**
  * @brief  Read temperature and humidity from DHT22 sensor
  * @param  port: GPIO port where sensor is connected (GPIO_TypeDef*)
  * @param  pin: GPIO pin number where sensor is connected (uint16_t)
  * @param  temperature: Pointer to store temperature value (float*)
  * @param  humidity: Pointer to store humidity value (float*)
  * @retval Operation status (DHT22_OK, DHT22_ERROR, DHT22_TIMEOUT)
  * @note   Temperature unit is Celsius, humidity is percentage
  * @warning This function contains blocking delays
  */
uint8_t DHT22_Read(GPIO_TypeDef* port, uint16_t pin);

/**
  * @brief  Check if the temperature from DHT22 sensor is above a specified threshold
  * @param  temperature: Current temperature value (float)
  * @param  tempThreshold: Temperature threshold to compare against (float)
  * @retval bool: Operation result (true if above threshold, false otherwise)
  * @note   Temperature unit is Celsius, humidity is in percentage.
  */
bool DHT22_IsAboveThreshold(float temperature);

#ifdef __cplusplus
}
#endif

#endif /* DHT22_H_ */

/************************ (C) COPYRIGHT Naufal Faqiih *****END OF FILE****/