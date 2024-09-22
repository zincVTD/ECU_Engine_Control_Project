/***************************************************************************
 * @file    Rte_TorqueControl.h
 * @brief   Khai báo các API và cấu trúc dữ liệu cần thiết ở lớp RTE
 *          để Torque Control SWC giao tiếp với hệ thống.
 * @details File này cung cấp giao diện cho việc gọi và khởi tạo các hàm
 *          khởi tạo và cập nhật giá trị các cảm biến và bộ điều khiển ở lớp
 *          I/O Hardware Abstraction
 *          dùng cho việc điều khiển mô-men xoắn động cơ.
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/

#ifndef RTE_TORQUECONTROL_H
#define RTE_TORQUECONTROL_H

#include "Std_Types.h" // Bao gồm các kiểu dữ liệu tiêu chuẩn

/**************************************************************************
 * @brief   API để đọc giá trị vị trí bàn đạp ga.
 * @param   ThrottlePosition Con trỏ đến biến lưu giá trị bàn đạp ga.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Read_RpThrottleSensor_ThrottlePosition(float *ThrottlePosition);

/**************************************************************************
 * @brief   API để đọc giá trị cảm biến tốc độ.
 * @param   Speed Con trỏ đến biến lưu giá trị tốc độ.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Read_RpSpeedSensor_Speed(float *Speed);

/**************************************************************************
 * @brief   API để đọc giá trị cảm biến tải trọng.
 * @param   LoadWeight Con trỏ đến biến lưu giá trị tải trọng.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Read_RpLoadSensor_LoadWeight(float *LoadWeight);

/**************************************************************************
 * @brief   API để đọc mô-men xoắn thực tế từ cảm biến mô-men xoắn.
 * @param   ActualTorque Con trỏ đến biến lưu giá trị mô-men xoắn thực tế.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Read_RpTorqueSensor_ActualTorque(float *ActualTorque);

/**************************************************************************
 * @brief   API để ghi dữ liệu mô-men xoắn yêu cầu tới bộ điều khiển động cơ.
 * @param   TorqueValue Con trỏ đến biến lưu giá trị tốc độ.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Write_PpMotorDriver_SetTorque(float TorqueValue);

/**************************************************************************
 * @brief   API khởi tạo cảm biến bàn đạp ga.
 * @param   void
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Call_RpThrottleSensor_Init(void);

/**************************************************************************
 * @brief   API khởi tạo cảm biến tốc độ.
 * @param   void
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Call_RpSpeedSensor_Init(void);

/**************************************************************************
 * @brief   API khởi tạo cảm biến tải trọng.
 * @param   void
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Call_RpLoadSensor_Init(void);

/**************************************************************************
 * @brief   API khởi tạo cảm biến mô-men xoắn.
 * @param   void
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Call_RpTorqueSensor_Init(void);

/**************************************************************************
 * @brief   API khởi tạo bộ điều khiển mô-men xoắn.
 * @param   void
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Call_PpMotorDriver_Init(void);

#endif // RTE_TORQUECONTROL_H
