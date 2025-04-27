/*******************************************************************************
* @file    relay.c
* @author  Naufal Faqiih
* @version 1.0.0
* @date    23 April 2024
* @brief   Implementasi modul Relay Control menggunakan STM32F4xx HAL
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "relay.h"
#include "stm32f4xx_hal.h"

/* Private defines -----------------------------------------------------------*/
#define RELAY_PIN_MODE         (GPIO_MODE_OUTPUT_PP)
#define RELAY_PIN_PULL         (GPIO_NOPULL)
#define RELAY_PIN_SPEED        (GPIO_SPEED_FREQ_LOW)

/* Function definitions ------------------------------------------------------*/

/**
  * @brief  Menginisialisasi relay pada port dan pin tertentu
  * @param  port: Pointer ke GPIO Port (GPIO_TypeDef)
  * @param  pin: Nomor pin GPIO (uint16_t)
  * @retval None
  * @note   Fungsi ini harus dipanggil sebelum menggunakan relay
  */
void Relay_Init(GPIO_TypeDef* port, uint16_t pin)
{
    GPIO_InitTypeDef GPIO_InitStruct = 
    {
        .Pin = pin,
        .Mode = RELAY_PIN_MODE,
        .Pull = RELAY_PIN_PULL,
        .Speed = RELAY_PIN_SPEED
    };
    
    /* Parameter validation */
    if((port != NULL) && (pin != 0U))
    {
        HAL_GPIO_Init(port, &GPIO_InitStruct);
    }
    else
    {
        /* MISRA requires all execution paths to be covered */
        ; /* Intentional empty statement for MISRA compliance */
    }
}

/**
  * @brief  Menyalakan relay pada port dan pin tertentu
  * @param  port: Pointer ke GPIO Port (GPIO_TypeDef)
  * @param  pin: Nomor pin GPIO (uint16_t)
  * @retval None
  * @note   Pastikan relay sudah diinisialisasi sebelum memanggil fungsi ini
  */
void Relay_On(GPIO_TypeDef* port, uint16_t pin)
{
    /* Parameter validation */
    if((port != NULL) && (pin != 0U))
    {
        HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
    }
    else
    {
        ; /* Intentional empty statement for MISRA compliance */
    }
}

/**
  * @brief  Mematikan relay pada port dan pin tertentu
  * @param  port: Pointer ke GPIO Port (GPIO_TypeDef)
  * @param  pin: Nomor pin GPIO (uint16_t)
  * @retval None
  * @note   Pastikan relay sudah diinisialisasi sebelum memanggil fungsi ini
  */
void Relay_Off(GPIO_TypeDef* port, uint16_t pin)
{
    /* Parameter validation */
    if((port != NULL) && (pin != 0U))
    {
        HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
    }
    else
    {
        ; /* Intentional empty statement for MISRA compliance */
    }
}

/************************ (C) COPYRIGHT Naufal Faqiih *****END OF FILE****/