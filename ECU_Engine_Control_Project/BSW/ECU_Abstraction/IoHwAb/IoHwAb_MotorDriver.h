/***************************************************************************
 * @file    IoHwAb_MotorDriver.h
 * @brief   Khai báo các hàm và cấu trúc liên quan đến điều khiển Motor Driver
 * @details File này cung cấp giao diện cho việc điều khiển Motor Driver
 *          bao gồm khởi tạo và điều chỉnh mô-men xoắn động cơ.
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/

#ifndef IOHWAB_MOTORDRIVER_H
#define IOHWAB_MOTORDRIVER_H

#include "Std_Types.h"

// Cấu trúc cấu hình cho mô-tơ
typedef struct
{
    uint8_t Motor_Channel;    // Kênh PWM điều khiển mô-tơ
    uint16_t Motor_MaxTorque; // Mô-men xoắn tối đa (Nm)
} MotorDriver_ConfigType;

// Prototype khởi tạo mô-tơ
Std_ReturnType IoHwAb_MotorDriver_Init(const MotorDriver_ConfigType *ConfigPtr);

// Prototype điều chỉnh mô-men xoắn của mô-tơ
Std_ReturnType IoHwAb_MotorDriver_SetTorque(float TorqueValue);

#endif /* IOHWAB_MOTORDRIVER_H */
