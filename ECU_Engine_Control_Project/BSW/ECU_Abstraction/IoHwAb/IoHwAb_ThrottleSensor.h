/***************************************************************************
 * @file    IoHwAb_ThrottleSensor.h
 * @brief   Khai báo các hàm và cấu trúc liên quan đến điều khiển cảm biến
 *          bàn đạp ga
 * @details File này cung cấp giao diện cho việc điều khiển cảm biến bàn đạp ga
 *          bao gồm khởi tạo và đọc giá trị cảm biến bàn đạp ga.
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/

#ifndef IOHWAB_THROTTLESENSOR_H
#define IOHWAB_THROTTLESENSOR_H

#include "Std_Types.h"

// Cấu hình cho cảm biến bàn đạp ga
typedef struct
{
    uint8_t ThrottleSensor_Channel; // Kênh ADC để đọc giá trị từ cảm biến bàn đạp ga
} ThrottleSensor_ConfigType;

// Prototype cho hàm khởi tạo cảm biến bàn đạp ga
Std_ReturnType IoHwAb_ThrottleSensor_Init(const ThrottleSensor_ConfigType *ConfigPtr);

// Prototype cho hàm đọc giá trị từ cảm biến bàn đạp ga
Std_ReturnType IoHwAb_ThrottleSensor_Read(float *ThrottlePosition);

#endif /* IOHWAB_THROTTLESENSOR_H */
