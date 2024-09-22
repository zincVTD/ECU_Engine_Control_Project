/***************************************************************************
 * @file    IoHwAb_SpeedSensor.c
 * @brief   Định nghĩa các hàm điều khiển cảm biến tốc độ
 * @details File này chứa định nghĩa của các hàm điều khiển cảm biến tốc độ
 *          bao gồm khởi tạo và đọc giá trị cảm biến tốc độ.
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/

#include "IoHwAb_SpeedSensor.h"
#include "Adc.h" // Gọi API từ MCAL để đọc giá trị từ ADC
#include <stdio.h>
#include <stdlib.h>

// Giả lập cấu hình của cảm biến tốc độ
static SpeedSensor_ConfigType SpeedSensor_CurrentConfig;

// Hàm khởi tạo cảm biến tốc độ với cấu hình
Std_ReturnType IoHwAb_SpeedSensor_Init(const SpeedSensor_ConfigType *ConfigPtr)
{
    if (ConfigPtr == NULL)
    {
        printf("Error: Null configuration pointer passed to IoHwAb_SpeedSensor_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến tốc độ vào biến toàn cục
    SpeedSensor_CurrentConfig.SpeedSensor_Channel = ConfigPtr->SpeedSensor_Channel;
    SpeedSensor_CurrentConfig.SpeedSensor_MaxValue = ConfigPtr->SpeedSensor_MaxValue;

    // Gọi API từ MCAL để khởi tạo ADC
    Adc_ConfigType adcConfig;
    adcConfig.Adc_Channel = ConfigPtr->SpeedSensor_Channel;
    Adc_Init(&adcConfig);

    // In ra thông tin cấu hình cảm biến tốc độ
    printf("Speed Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", SpeedSensor_CurrentConfig.SpeedSensor_Channel);
    printf(" - Max Speed Value: %d km/h\n", SpeedSensor_CurrentConfig.SpeedSensor_MaxValue);

    return E_OK;
}

// Hàm đọc giá trị từ cảm biến tốc độ
Std_ReturnType IoHwAb_SpeedSensor_Read(float *SpeedValue)
{
    if (SpeedValue == NULL)
    {
        return E_NOT_OK; // Kiểm tra con trỏ NULL
    }

    // Đọc giá trị từ kênh ADC
    uint16_t adcValue = 0;
    if (Adc_ReadChannel(SpeedSensor_CurrentConfig.SpeedSensor_Channel, &adcValue) != E_OK)
    {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    // Chuyển đổi giá trị ADC sang tốc độ (giả lập)
    *SpeedValue = ((float)adcValue / 1023.0f) * SpeedSensor_CurrentConfig.SpeedSensor_MaxValue;

    // In ra giá trị tốc độ
    printf("Reading Speed Sensor (ADC Channel %d): Speed = %.2f km/h\n",
           SpeedSensor_CurrentConfig.SpeedSensor_Channel, *SpeedValue);

    return E_OK;
}
