/*******************************************************************************
* @file    relay.h
* @author  Naufal Faqiih
* @version 1.0.0
* @date    23 April 2024
* @brief   Header file untuk modul Relay Control menggunakan STM32F4xx HAL
*******************************************************************************/

#ifndef RELAY_H_
#define RELAY_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Public function prototypes ------------------------------------------------*/

/**
  * @brief  Menginisialisasi relay pada port dan pin tertentu
  * @param  port: Pointer ke GPIO Port (GPIO_TypeDef)
  * @param  pin: Nomor pin GPIO (uint16_t)
  * @retval None
  * @note   Fungsi ini harus dipanggil sebelum menggunakan relay
  */
void Relay_Init(GPIO_TypeDef* port, uint16_t pin);

/**
  * @brief  Menyalakan relay pada port dan pin tertentu
  * @param  port: Pointer ke GPIO Port (GPIO_TypeDef)
  * @param  pin: Nomor pin GPIO (uint16_t)
  * @retval None
  * @note   Pastikan relay sudah diinisialisasi sebelum memanggil fungsi ini
  */
void Relay_On(GPIO_TypeDef* port, uint16_t pin);

/**
  * @brief  Mematikan relay pada port dan pin tertentu
  * @param  port: Pointer ke GPIO Port (GPIO_TypeDef)
  * @param  pin: Nomor pin GPIO (uint16_t)
  * @retval None
  * @note   Pastikan relay sudah diinisialisasi sebelum memanggil fungsi ini
  */
void Relay_Off(GPIO_TypeDef* port, uint16_t pin);

#ifdef __cplusplus
}
#endif

#endif /* RELAY_H_ */

/************************ (C) COPYRIGHT Naufal Faqiih *****END OF FILE****/