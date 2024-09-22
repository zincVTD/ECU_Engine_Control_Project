/***************************************************************************
 * @file    main.c
 * @brief   �?nh nghia task di?u khi?n m�-men xo?n c?a d?ng co.
 * @details File n�y ch?a d?nh nghia c?a task di?u khi?n b? m�-men xo?n
 *          c?a d?ng co v� ti?n h�nh ch?y task n�y
 * @version 1.0
 * @date    2024-09-22
 * @author  V� Th�nh Danh
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
