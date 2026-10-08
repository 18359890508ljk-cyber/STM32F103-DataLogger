#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "MYDMA.h"

uint16_t AD_Value;

void MYADC_Init(void)
{
	MYDMA_ADC_Init((uint32_t)&AD_Value);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_init;
	GPIO_init.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_init.GPIO_Pin = GPIO_Pin_2;
	GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_init);
	
	ADC_InitTypeDef ADC_init;
	ADC_init.ADC_ContinuousConvMode = DISABLE;
	ADC_init.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_init.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_init.ADC_Mode = ADC_Mode_Independent;
	ADC_init.ADC_NbrOfChannel = 1;
	ADC_init.ADC_ScanConvMode = DISABLE;
	ADC_Init(ADC1, &ADC_init);
	
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_0, 1, ADC_SampleTime_55Cycles5);
	
	ADC_Cmd(ADC1, ENABLE);
	
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1) != RESET);
	
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1) != RESET);
	
	ADC_DMACmd(ADC1, ENABLE);
}

uint16_t MYADC_Getvalue(void)
{
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) != SET);
	
	return ADC_GetConversionValue(ADC1);
}

void MYADCDMA_Getvalue(void)
{
	DMA_Cmd(DMA1_Channel1, DISABLE);
	DMA_SetCurrDataCounter(DMA1_Channel1, 1);
	DMA_Cmd(DMA1_Channel1, ENABLE);
	
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) != SET);
	DMA_ClearFlag(DMA1_FLAG_TC1);
}

