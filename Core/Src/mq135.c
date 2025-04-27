/*******************************************************************************
* @file    mq135.c
* @author  Naufal Faqiih
* @version 1.0.0
* @date    23 April 2024
* @brief   Implementasi modul Sensor Gas MQ135 menggunakan STM32F4xx HAL
*******************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "mq135.h"
#include "stm32f4xx_hal.h"
#include <stdbool.h>

/* Private defines -----------------------------------------------------------*/
#define ADC_MAX_VALUE          (4095U)       /* 12-bit ADC resolusi */
#define VREF_VOLTAGE          (3.3F)        /* Tegangan referensi ADC */
#define CONVERSION_FACTOR     (100.0F)      /* Faktor konversi tegangan ke konsentrasi */
#define HAL_MAX_DELAY_VALUE   (0xFFFFFFFFU) /* Nilai timeout maksimal HAL */

/* Function definitions ------------------------------------------------------*/

/**
  * @brief  Membaca nilai konsentrasi gas dari sensor MQ135
  * @param  hadc1: Pointer ke handler ADC (ADC_HandleTypeDef)
  * @retval Nilai konsentrasi gas dalam ppm (parts per million)
  * @note   Kalibrasi diperlukan untuk akurasi pengukuran
  */
float MQ135_Read(ADC_HandleTypeDef* hadc1)
{
    bool concentration;
    uint32_t adcValue = 0U;
    float voltage = 0.0F;
    HAL_StatusTypeDef adcStatus = HAL_ERROR;

    /* MISRA Rule 17.2 - Validasi parameter input */
    if (hadc1 == NULL)
    {
        concentration = 0.0F;
    }
    else
    {
        /* MISRA Rule 13.5 - Operasi ADC dengan pengecekan status */
        adcStatus = HAL_ADC_Start(hadc1);
        if (adcStatus == HAL_OK)
        {
            adcStatus = HAL_ADC_PollForConversion(hadc1, HAL_MAX_DELAY_VALUE);
            if (adcStatus == HAL_OK)
            {
                adcValue = HAL_ADC_GetValue(hadc1);
                
                /* MISRA Rule 10.1 - Operasi aritmetika dengan tipe yang sesuai */
                voltage = (adcValue * VREF_VOLTAGE) / (float)ADC_MAX_VALUE;
                
                /* Hitung konsentrasi */
                concentration = MQ135_CalculateConcentration(voltage);
            }
            /* MISRA Rule 15.5 - Single exit point */
            (void)HAL_ADC_Stop(hadc1);
        }
    }

    return concentration;
}

/**
  * @brief  Menghitung konsentrasi gas berdasarkan tegangan input
  * @param  voltage: Nilai tegangan dari pembacaan ADC
  * @retval Nilai konsentrasi gas dalam ppm
  * @note   Fungsi ini harus dikalibrasi sesuai karakteristik sensor
  */
static bool MQ135_CalculateConcentration(float voltage)
{
    float concentration = 0.0F;
    
    /* MISRA Rule 13.3 - Validasi input */
    if (voltage < 0.0F)
    {
        voltage = 0.0F;
    }
    
    /* Contoh perhitungan sederhana - sesuaikan dengan datasheet */
    concentration = voltage * CONVERSION_FACTOR;
    
    return MQ135_IsAboveThreshold(concentration);
}

/**
  * @brief  Memeriksa apakah konsentrasi gas melebihi ambang batas
  * @param  concentration: Nilai konsentrasi gas dalam ppm
  * @param  threshold: Ambang batas konsentrasi
  * @retval true jika konsentrasi melebihi ambang batas, false sebaliknya
  */
bool MQ135_IsAboveThreshold(float concentration)
{
    return (concentration >= 300);
}

/************************ (C) COPYRIGHT Naufal Faqiih *****END OF FILE****/