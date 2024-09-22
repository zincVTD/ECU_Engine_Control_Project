/***************************************************************************
 * @file    MotorControl.h
 * @brief   Khai báo các hàm và cấu trúc liên quan đến điều khiển mô-men xoắn
 *          động cơ
 * @details File này cung cấp giao diện cho việc điều khiển mô-men xoắn động cơ
 *          bao gồm khởi tạo và cập nhật mô-men xoắn động cơ.
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/

#ifndef TORQUE_CONTROL_H
#define TORQUE_CONTROL_H

/**************************************************************************
 * Định nghĩa hằng số cho giới hạn mô-men của động cơ
 * MAX_TORQUE: Mô-men tối đa
 * MIN_TORQUE: Mô-men tối thiểu
 **************************************************************************/
#define MAX_TORQUE 100.0f
#define MIN_TORQUE 0.0f

/**************************************************************************
 * @brief   Khởi tạo hệ thống điều khiển mô-men xoắn.
 * @param   void
 * @return  void
 **************************************************************************/
void TorqueControl_Init(void);

/**************************************************************************
 * @brief   Cập nhật hệ thống điều khiển mô-men xoắn.
 * @param   void
 * @return  void
 **************************************************************************/
void TorqueControl_Update(void);

#endif // TORQUE_CONTROL_H
