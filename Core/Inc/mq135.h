/*******************************************************************************
* @file    mq135.h
* @author  Naufal Faqiih
* @version 1.0.0
* @date    23 April 2024
* @brief   Header file for MQ135 Gas Sensor module using STM32F4xx HAL
*******************************************************************************/

#ifndef MQ135_H_
#define MQ135_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include <stdbool.h>

/* Public function prototypes ------------------------------------------------*/

/**
  * @brief  Membaca nilai konsentrasi gas dari sensor MQ135
  * @param  hadc1: Pointer ke handler ADC (ADC_HandleTypeDef)
  * @retval Nilai konsentrasi gas dalam ppm (parts per million)
  * @note   Kalibrasi diperlukan untuk akurasi pengukuran
  */
float MQ135_Read(ADC_HandleTypeDef* hadc1);

/**
  * @brief  Menghitung konsentrasi gas berdasarkan tegangan input
  * @param  voltage: Nilai tegangan dari pembacaan ADC
  * @retval Nilai konsentrasi gas dalam ppm
  * @note   Fungsi ini harus dikalibrasi sesuai karakteristik sensor
  */
static bool MQ135_CalculateConcentration(float voltage);

/**
  * @brief  Memeriksa apakah konsentrasi gas melebihi ambang batas
  * @param  concentration: Nilai konsentrasi gas dalam ppm
  * @param  threshold: Ambang batas konsentrasi
  * @retval true jika konsentrasi melebihi ambang batas, false sebaliknya
  */
bool MQ135_IsAboveThreshold(float concentration);

#ifdef __cplusplus
}
#endif

#endif /* MQ135_H_ */

/************************ (C) COPYRIGHT Naufal Faqiih *****END OF FILE****/