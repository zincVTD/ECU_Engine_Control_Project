/***************************************************************************
 * @file    Adc.h
 * @brief   Khai báo các hàm và cấu trúc dữ liệu cần thiết
 *          để điều khiển bộ ADC1.
 * @details File này cung cấp giao diện cho việc khởi tạo và đọc giá trị
 *          sau chuyển đổi một kênh trong bộ ADC1.
 * @version 1.0
 * @date    2024-09-22
 * @author  Võ Thành Danh
 ***************************************************************************/

#ifndef ADC_H
#define ADC_H

#include "stm32f10x.h"                  // Device header
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f10x_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_adc.h"              // Keil::Device:StdPeriph Drivers:ADC

#include <stdio.h>
#include "Std_Types.h"

/**************************************************************************
 * Định nghĩa kiểu dữ liệu uint cho số thứ tự một kênh trong bộ ADC.
 **************************************************************************/
typedef uint8_t Adc_ChannelType;

/**************************************************************************
 * Định nghĩa kiểu dữ liệu uint cho số thứ tự một nhóm các kênh trong bộ ADC.
 **************************************************************************/
typedef uint8_t Adc_GroupType;

/**************************************************************************
 * Định nghĩa kiểu dữ liệu uint cho thời gian lấy mẫu của bộ ADC.
 **************************************************************************/
typedef uint32_t Adc_SamplingTimeType;

/**************************************************************************
 * Định nghĩa kiểu dữ liệu uint cho số bit độ phân giải bộ ADC.
 **************************************************************************/
typedef uint8_t Adc_ResolutionType;

/**************************************************************************
 * Định nghĩa cấu trúc Adc_ConfigType chứa thông tin về các thông số cấu hình
 * một kênh trong bộ ADC.
 * Adc_Channel: Số thứ tự một kênh trong bộ ADC.
 * Adc_Rank: Mức ưu tiên chuyển đổi của một kênh trong bộ ADC.
 * Adc_SamplingTime: Thời gian lấy mẫu của bộ ADC.
 * Adc_Resolution: Số bit độ phân giải bộ ADC.
 **************************************************************************/
typedef struct
{
    Adc_ChannelType Adc_Channel;
    uint8_t Adc_Rank;
    Adc_SamplingTimeType Adc_SamplingTime;
    Adc_ResolutionType Adc_Resolution;
} Adc_ConfigType;

/**************************************************************************
 * @brief   Hàm khởi tạo 1 kênh trong bộ ADC1.
 * @param   ConfigPtr Con trỏ chứa các cài đặt cấu hình ADC.
 * @return  void
 **************************************************************************/
void Adc_Init(const Adc_ConfigType *ConfigPtr);

/**************************************************************************
 * @brief   Hàm đọc giá trị sau chuyển đổi ở 1 kênh trong bộ ADC1.
 * @param   Adc_Channel Số thứ tự kênh trong bộ ADC1 mà muốn đọc.
 * @param   Adc_Value Con trỏ chứa giá trị sau khi đọc.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Adc_ReadChannel(Adc_ChannelType Adc_Channel, uint16_t *Adc_Value);

#endif // ADC_H
