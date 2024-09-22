/***************************************************************************
 * @file    Adc.c
 * @brief   Định nghĩa các hàm điều khiển bộ ADC trong MCU STM32F103C8.
 * @details File này chứa định nghĩa của các hàm điều khiển bộ ADC1
 *          bao gồm khởi tạo và đọc giá trị sau khi chuyển đổi.
 * @version 1.0
 * @date    2024-09-22
 * @author  Võ Thành Danh
 ***************************************************************************/

#include "Adc.h"

/**************************************************************************
 * @brief   Hàm khởi tạo 1 kênh trong bộ ADC1.
 * @details Hàm này khởi tạo 1 kênh trong bộ ADC1 sử dụng các cài đặt từ
 *          con trỏ được truyền vào hàm.
 * @param   ConfigPtr Con trỏ chứa các cài đặt cấu hình ADC.
 * @return  void
 **************************************************************************/
void Adc_Init(const Adc_ConfigType *ConfigPtr)
{
    // Cấp clock cho bộ ADC1
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
		
		// Cấu hình chung cho GPIO
		GPIO_InitTypeDef GPIO_InitStruct;
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;
		GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

    // Cấp clock cho GPIO
    if (ConfigPtr->Adc_Channel < 8)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
				GPIO_InitStruct.GPIO_Pin = ConfigPtr->Adc_Channel;	//PA0 -> PA7
				GPIO_Init(GPIOA, &GPIO_InitStruct);
    }
    else if (ConfigPtr->Adc_Channel < 10)
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
				GPIO_InitStruct.GPIO_Pin = ConfigPtr->Adc_Channel - 8;	//PB0 - PB1
				GPIO_Init(GPIOB, &GPIO_InitStruct);
    }
    else
    {
        RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
				GPIO_InitStruct.GPIO_Pin = ConfigPtr->Adc_Channel - 10;	//PC0 -> PC5
				GPIO_Init(GPIOC, &GPIO_InitStruct);
    }

    // Cấu hình ADC
    ADC_InitTypeDef ADC_InitStruct;

    ADC_InitStruct.ADC_Mode = ADC_Mode_Independent;
    ADC_InitStruct.ADC_ScanConvMode = DISABLE;
    ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
    ADC_InitStruct.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
    ADC_InitStruct.ADC_DataAlign = ADC_DataAlign_Right;
    ADC_InitStruct.ADC_NbrOfChannel = 1;

    // Cho phép ADC hoạt động
    ADC_Init(ADC1, &ADC_InitStruct); // Lưu cấu hình ADC
    ADC_RegularChannelConfig(ADC1, ConfigPtr->Adc_Channel,
                             ConfigPtr->Adc_Rank,
                             ConfigPtr->Adc_SamplingTime);
    ADC_Cmd(ADC1, ENABLE);
}

/**************************************************************************
 * @brief   Hàm đọc giá trị sau chuyển đổi ở 1 kênh trong bộ ADC1.
 * @details Hàm này đọc giá trị sau chuyển đổi 1 kênh trong bộ ADC1 và lưu vào
 *          con trỏ truyền vào hàm.
 *          Nếu con trỏ đầu vào là NULL, hàm sẽ trả về lỗi.
 * @param   Adc_Channel Số thứ tự kênh trong bộ ADC1 mà muốn đọc.
 * @param   Adc_Value Con trỏ chứa giá trị sau khi đọc.
 * @return  Std_ReturnType
 *          - E_OK: Thành công
 *          - E_NOT_OK: Lỗi khi con trỏ NULL hoặc không đọc được giá trị
 **************************************************************************/
Std_ReturnType Adc_ReadChannel(Adc_ChannelType Adc_Channel, uint16_t *Adc_Value)
{
    // Kiểm tra tham số truyền vào
    if (Adc_Value == NULL_PTR)
    {
        return E_NOT_OK;
    }
    ADC_SoftwareStartConvCmd(ADC1, ENABLE); // Bắt đầu chuyển đổi

    while (!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC))  //Chờ kết thức chuyển đổi
    {
    }

    *Adc_Value = ADC_GetConversionValue(ADC1);

    // Trả về OK nếu đọc thành công
    return E_OK;
}