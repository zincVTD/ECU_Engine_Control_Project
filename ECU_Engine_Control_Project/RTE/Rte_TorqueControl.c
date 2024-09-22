/***************************************************************************
 * @file    Rte_TorqueControl.c
 * @brief   Định nghĩa các API ở lớp RTE để Torque Control SWC
 *          giao tiếp với hệ thống.
 * @details File này chứa định nghĩa các API để gọi và khởi tạo các hàm
 *          khởi tạo và cập nhật giá trị các cảm biến và bộ điều khiển ở lớp
 *          I/O Hardware Abstraction
 *          dùng cho việc điều khiển mô-men xoắn động cơ.
 * @version 1.0
 * @date    2024-09-11
 * @author  HALA Academy
 * @website https://hala.edu.vn/
 ***************************************************************************/

#include "Rte_TorqueControl.h"
#include "IoHwAb_ThrottleSensor.h" // API IoHwAb để đọc cảm biến bàn đạp ga
#include "IoHwAb_SpeedSensor.h"    // API IoHwAb để đọc cảm biến tốc độ
#include "IoHwAb_LoadSensor.h"     // API IoHwAb để đọc cảm biến tải trọng
#include "IoHwAb_TorqueSensor.h"   // API IoHwAb để đọc mô-men xoắn thực tế
#include "IoHwAb_MotorDriver.h"    // API IoHwAb để điều khiển mô-men xoắn động cơ
#include "Std_Types.h"

/**************************************************************************
 * @brief   API để đọc giá trị vị trí bàn đạp ga.
 * @details API này đọc giá trị từ cảm biến bàn đạp ga và lưu vào
 *          tham số con trỏ truyền vào.
 *          Nếu con trỏ đầu vào là NULL, hàm sẽ trả về lỗi.
 * @param   ThrottlePosition Con trỏ đến biến lưu giá trị bàn đạp ga.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Read_RpThrottleSensor_ThrottlePosition(float *ThrottlePosition)
{
    if (ThrottlePosition == NULL)
    {
        return E_NOT_OK; // Trả về lỗi nếu con trỏ NULL
    }
    return IoHwAb_ThrottleSensor_Read(ThrottlePosition); // Gọi API từ IoHwAb để đọc giá trị từ cảm biến
}

/**************************************************************************
 * @brief   API để đọc giá trị cảm biến tốc độ.
 * @details API này đọc giá trị từ cảm biến tốc độ và lưu vào
 *          tham số con trỏ truyền vào.
 *          Nếu con trỏ đầu vào là NULL, hàm sẽ trả về lỗi.
 * @param   Speed Con trỏ đến biến lưu giá trị tốc độ.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Read_RpSpeedSensor_Speed(float *Speed)
{
    if (Speed == NULL)
    {
        return E_NOT_OK;
    }
    return IoHwAb_SpeedSensor_Read(Speed); // Gọi API từ IoHwAb để đọc giá trị từ cảm biến tốc độ
}

/**************************************************************************
 * @brief   API để đọc giá trị cảm biến tải trọng.
 * @details API này đọc giá trị từ cảm biến tải trọng và lưu vào
 *          tham số con trỏ truyền vào.
 *          Nếu con trỏ đầu vào là NULL, hàm sẽ trả về lỗi.
 * @param   LoadWeight Con trỏ đến biến lưu giá trị tải trọng.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Read_RpLoadSensor_LoadWeight(float *LoadWeight)
{
    if (LoadWeight == NULL)
    {
        return E_NOT_OK;
    }
    return IoHwAb_LoadSensor_Read(LoadWeight); // Gọi API từ IoHwAb để đọc giá trị từ cảm biến tải trọng
}

/**************************************************************************
 * @brief   API để đọc mô-men xoắn thực tế từ cảm biến mô-men xoắn.
 * @details API này đọc giá trị từ cảm biến mô-men xoắn và lưu vào
 *          tham số con trỏ truyền vào.
 *          Nếu con trỏ đầu vào là NULL, hàm sẽ trả về lỗi.
 * @param   ActualTorque Con trỏ đến biến lưu giá trị mô-men xoắn thực tế.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Read_RpTorqueSensor_ActualTorque(float *ActualTorque)
{
    if (ActualTorque == NULL)
    {
        return E_NOT_OK;
    }
    return IoHwAb_TorqueSensor_Read(ActualTorque); // Gọi API từ IoHwAb để đọc mô-men xoắn thực tế
}

/**************************************************************************
 * @brief   API để ghi dữ liệu mô-men xoắn yêu cầu tới bộ điều khiển động cơ.
 * @details API để ghi dữ liệu mô-men xoắn yêu cầu tới bộ điều khiển động cơ.
 * @param   TorqueValue Con trỏ đến biến lưu giá trị tốc độ.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Write_PpMotorDriver_SetTorque(float TorqueValue)
{
    return IoHwAb_MotorDriver_SetTorque(TorqueValue); // Gọi API từ IoHwAb để ghi mô-men xoắn yêu cầu tới động cơ
}

/**************************************************************************
 * @brief   API khởi tạo cảm biến bàn đạp ga.
 * @details API này cấu hình cho cảm biến bàn đap ga, bao gồm
 *          chọn kênh ADC và khởi tạo nó.
 * @param   void
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Call_RpThrottleSensor_Init(void)
{
    ThrottleSensor_ConfigType throttleSensorConfig = {
        .ThrottleSensor_Channel = 0 // Kênh ADC cho cảm biến bàn đạp ga
    };
    return IoHwAb_ThrottleSensor_Init(&throttleSensorConfig); // Gọi API từ IoHwAb để khởi tạo cảm biến bàn đạp ga
}

/**************************************************************************
 * @brief   API khởi tạo cảm biến tốc độ.
 * @details API này cấu hình cho cảm biến tốc độ, bao gồm
 *          chọn kênh ADC, tốc độ tối đa và khởi tạo nó.
 * @param   void
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Call_RpSpeedSensor_Init(void)
{
    // Cấu hình cho cảm biến tốc độ
    SpeedSensor_ConfigType speedSensorConfig = {
        .SpeedSensor_Channel = 1,   // Kênh ADC cho cảm biến tốc độ
        .SpeedSensor_MaxValue = 200 // Tốc độ tối đa giả lập (200 km/h)
    };
    return IoHwAb_SpeedSensor_Init(&speedSensorConfig); // Gọi API từ IoHwAb để khởi tạo cảm biến tốc độ
}

/**************************************************************************
 * @brief   API khởi tạo cảm biến tải trọng.
 * @details API này cấu hình cho cảm biến tải trọng, bao gồm
 *          chọn kênh ADC, tải trọng tối đa và khởi tạo nó.
 * @param   void
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Call_RpLoadSensor_Init(void)
{
    // Cấu hình cho cảm biến tải trọng
    LoadSensor_ConfigType loadSensorConfig = {
        .LoadSensor_Channel = 2,    // Kênh ADC cho cảm biến tải trọng
        .LoadSensor_MaxValue = 1000 // Tải trọng tối đa giả lập (1000 kg)
    };
    return IoHwAb_LoadSensor_Init(&loadSensorConfig); // Gọi API từ IoHwAb để khởi tạo cảm biến tải trọng
}

/**************************************************************************
 * @brief   API khởi tạo cảm biến mô-men xoắn.
 * @details API này cấu hình cho cảm biến mô-men xoắn, bao gồm
 *          chọn kênh ADC, mô-men xoắn tối đa và khởi tạo nó.
 * @param   void
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Call_RpTorqueSensor_Init(void)
{
    // Cấu hình cho cảm biến mô-men xoắn
    TorqueSensor_ConfigType torqueSensorConfig = {
        .TorqueSensor_Channel = 3,   // Kênh ADC cho cảm biến mô-men xoắn
        .TorqueSensor_MaxValue = 500 // Mô-men xoắn tối đa giả lập (500 Nm)
    };
    return IoHwAb_TorqueSensor_Init(&torqueSensorConfig); // Gọi API từ IoHwAb để khởi tạo cảm biến mô-men xoắn
}

/**************************************************************************
 * @brief   API khởi tạo bộ điều khiển mô-men xoắn.
 * @details API này cấu hình cho bộ điều khiển mô-men xoắn, bao gồm
 *          chọn kênh ADC, mô-men xoắn tối đa của động cơ và khởi tạo nó.
 * @param   void
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Rte_Call_PpMotorDriver_Init(void)
{
    // Cấu hình cho bộ điều khiển mô-men xoắn
    MotorDriver_ConfigType motorDriverConfig = {
        .Motor_Channel = 1,    // Kênh điều khiển mô-tơ
        .Motor_MaxTorque = 300 // Mô-men xoắn tối đa giả lập (300 Nm)
    };
    return IoHwAb_MotorDriver_Init(&motorDriverConfig); // Gọi API từ IoHwAb để khởi tạo bộ điều khiển mô-men xoắn
}
