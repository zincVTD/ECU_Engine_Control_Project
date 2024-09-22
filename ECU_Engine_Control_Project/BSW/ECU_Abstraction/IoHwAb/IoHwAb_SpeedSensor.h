/***************************************************************************
 * @file    IoHwAb_SpeedSensor.h
 * @brief   Khai báo các hàm và cấu trúc liên quan đến điều khiển cảm biến
 *          tốc độ
 * @details File này cung cấp giao diện cho việc điều khiển cảm biến tốc độ
 *          bao gồm khởi tạo và đọc giá trị cảm biến tải trọng.
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/

#ifndef IOHWAB_SPEEDSENSOR_H
#define IOHWAB_SPEEDSENSOR_H

#include "Std_Types.h"

// Cấu hình cho cảm biến tốc độ
typedef struct
{
    uint8_t SpeedSensor_Channel;   // Kênh ADC để đọc giá trị từ cảm biến tốc độ
    uint16_t SpeedSensor_MaxValue; // Giá trị tốc độ tối đa mà cảm biến có thể đọc (km/h)
} SpeedSensor_ConfigType;

// Prototype cho hàm khởi tạo cảm biến tốc độ
Std_ReturnType IoHwAb_SpeedSensor_Init(const SpeedSensor_ConfigType *ConfigPtr);

// Prototype cho hàm đọc giá trị từ cảm biến tốc độ
Std_ReturnType IoHwAb_SpeedSensor_Read(float *SpeedValue);

#endif /* IOHWAB_SPEEDSENSOR_H */
