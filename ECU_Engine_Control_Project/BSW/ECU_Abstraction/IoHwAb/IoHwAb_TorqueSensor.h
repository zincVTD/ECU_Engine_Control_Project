/***************************************************************************
 * @file    IoHwAb_TorqueSensor.h
 * @brief   Khai báo các hàm và cấu trúc liên quan đến điều khiển cảm biến
 *          mô-men xoắn
 * @details File này cung cấp giao diện cho việc điều khiển cảm biến
 *          mô-men xoắn bao gồm khởi tạo và đọc giá trị cảm biến mô-men xoắn.
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/

#ifndef IOHWAB_TORQUESENSOR_H
#define IOHWAB_TORQUESENSOR_H

#include "Std_Types.h"

// Cấu hình cho cảm biến mô-men xoắn
typedef struct
{
    uint8_t TorqueSensor_Channel;   // Kênh ADC để đọc giá trị từ cảm biến mô-men xoắn
    uint16_t TorqueSensor_MaxValue; // Giá trị mô-men xoắn tối đa (Nm)
} TorqueSensor_ConfigType;

// Prototype cho hàm khởi tạo cảm biến mô-men xoắn
Std_ReturnType IoHwAb_TorqueSensor_Init(const TorqueSensor_ConfigType *ConfigPtr);

// Prototype cho hàm đọc giá trị từ cảm biến mô-men xoắn
Std_ReturnType IoHwAb_TorqueSensor_Read(float *TorqueValue);

#endif /* IOHWAB_TORQUESENSOR_H */
