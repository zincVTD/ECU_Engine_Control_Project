/***************************************************************************
 * @file    IoHwAb_LoadSensor.h
 * @brief   Khai báo các hàm và cấu trúc liên quan đến điều khiển cảm biến
 *          tải trọng
 * @details File này cung cấp giao diện cho việc điều khiển cảm biến tải trọng
 *          bao gồm khởi tạo và đọc giá trị cảm biến tải trọng.
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/

#ifndef IOHWAB_LOADSENSOR_H
#define IOHWAB_LOADSENSOR_H

#include "Std_Types.h"

// Cấu hình cho cảm biến tải trọng (Load Sensor)
typedef struct
{
    uint8_t LoadSensor_Channel;   // Kênh ADC để đọc giá trị từ cảm biến
    uint16_t LoadSensor_MaxValue; // Giá trị tải trọng tối đa mà cảm biến có thể đọc
} LoadSensor_ConfigType;

// Khởi tạo cảm biến tải trọng
Std_ReturnType IoHwAb_LoadSensor_Init(const LoadSensor_ConfigType *ConfigPtr);

// Đọc giá trị từ cảm biến tải trọng
Std_ReturnType IoHwAb_LoadSensor_Read(float *LoadValue);

#endif /* IOHWAB_LOADSENSOR_H */
