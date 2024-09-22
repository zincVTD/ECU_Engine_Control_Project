/***************************************************************************
 * @file    main.c
 * @brief   Ð?nh nghia task di?u khi?n mô-men xo?n c?a d?ng co.
 * @details File này ch?a d?nh nghia c?a task di?u khi?n b? mô-men xo?n
 *          c?a d?ng co và ti?n hành ch?y task này
 * @version 1.0
 * @date    2024-09-22
 * @author  Võ Thành Danh
 ***************************************************************************/

#include "Torque_Control.h"
#include <stdio.h>

int main(void)
{
    TorqueControl_Init();

    while (1)
    {
        TorqueControl_Update();
    }
    return 0;
}
