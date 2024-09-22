/***************************************************************************
 * @file    IoHwAb_LoadSensor.c
 * @brief   Định nghĩa các hàm điều khiển cảm biến tải trọng
 * @details File này chứa định nghĩa của các hàm điều khiển cảm biến tải trọng
 *          bao gồm khởi tạo và đọc giá trị cảm biến tải trọng.
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/

#include "IoHwAb_LoadSensor.h"
#include "Adc.h" // Gọi API từ MCAL để đọc giá trị từ ADC
#include <stdio.h>

// Giả lập cấu hình của cảm biến tải trọng
static LoadSensor_ConfigType LoadSensor_CurrentConfig;

// Hàm khởi tạo cảm biến tải trọng
Std_ReturnType IoHwAb_LoadSensor_Init(const LoadSensor_ConfigType *ConfigPtr)
{
    if (ConfigPtr == NULL)
    {
        printf("Error: Null configuration pointer passed to IoHwAb_LoadSensor_Init.\n");
        return E_NOT_OK;
    }

    // Lưu cấu hình cảm biến tải trọng vào biến toàn cục
    LoadSensor_CurrentConfig.LoadSensor_Channel = ConfigPtr->LoadSensor_Channel;
    LoadSensor_CurrentConfig.LoadSensor_MaxValue = ConfigPtr->LoadSensor_MaxValue;

    // Gọi API từ MCAL để khởi tạo ADC
    Adc_ConfigType adcConfig;
    adcConfig.Adc_Channel = ConfigPtr->LoadSensor_Channel;
    Adc_Init(&adcConfig);

    // In ra thông tin cấu hình cảm biến tải trọng
    printf("Load Sensor Initialized with Configuration:\n");
    printf(" - ADC Channel: %d\n", LoadSensor_CurrentConfig.LoadSensor_Channel);
    printf(" - Max Load Value: %d kg\n", LoadSensor_CurrentConfig.LoadSensor_MaxValue);
    return E_OK;
}

// Hàm đọc giá trị từ cảm biến tải trọng
Std_ReturnType IoHwAb_LoadSensor_Read(float *LoadValue)
{
    if (LoadValue == NULL)
    {
        return E_NOT_OK; // Kiểm tra con trỏ NULL
    }

    // Đọc giá trị ADC từ MCAL
    uint16_t adcValue = 0;
    if (Adc_ReadChannel(LoadSensor_CurrentConfig.LoadSensor_Channel, &adcValue) != E_OK)
    {
        printf("Error: Failed to read ADC value.\n");
        return E_NOT_OK;
    }

    // Chuyển đổi giá trị ADC sang giá trị tải trọng (kg)
    *LoadValue = ((float)adcValue / 1023.0f) * LoadSensor_CurrentConfig.LoadSensor_MaxValue;

    // In ra giá trị tải trọng
    printf("Load Sensor (ADC Channel %d): Load = %.2f kg\n",
           LoadSensor_CurrentConfig.LoadSensor_Channel, *LoadValue);

    return E_OK;
}
