#include "stm32f10x.h"                  // Device header
#include "Delay.h"

uint16_t MYSize;
void MYDMA_Init(uint32_t AddressA, uint32_t AddressB, uint16_t Size)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	DMA_InitTypeDef DMA_init;
	DMA_init.DMA_BufferSize = Size;
	DMA_init.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_init.DMA_M2M = DMA_M2M_Enable;
	DMA_init.DMA_MemoryBaseAddr = AddressB;
	DMA_init.DMA_MemoryDataSize = DMA_PeripheralDataSize_Byte;
	DMA_init.DMA_MemoryInc = DMA_MemoryInc_Enable;
	DMA_init.DMA_Mode = DMA_Mode_Normal;
	DMA_init.DMA_PeripheralBaseAddr = AddressA;
	DMA_init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
	DMA_init.DMA_PeripheralInc = DMA_PeripheralInc_Enable;
	DMA_init.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(DMA1_Channel1, &DMA_init);
	
	DMA_Cmd(DMA1_Channel1, ENABLE);
}

void MYDMA_ADC_Init(uint32_t AddressB)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1, ENABLE);
	
	DMA_InitTypeDef DMA_init;
	DMA_init.DMA_BufferSize = 1;
	DMA_init.DMA_DIR = DMA_DIR_PeripheralSRC;
	DMA_init.DMA_M2M = DMA_M2M_Disable;
	DMA_init.DMA_MemoryBaseAddr = AddressB;
	DMA_init.DMA_MemoryDataSize = DMA_MemoryDataSize_HalfWord;
	DMA_init.DMA_MemoryInc = DMA_MemoryInc_Disable;
	DMA_init.DMA_Mode = DMA_Mode_Normal;
	DMA_init.DMA_PeripheralBaseAddr = (uint32_t)&ADC1->DR;
	DMA_init.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_init.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_init.DMA_Priority = DMA_Priority_Medium;
	DMA_Init(DMA1_Channel1, &DMA_init);
	
	DMA_Cmd(DMA1_Channel1, ENABLE);
}

void MYDMA_Transfer(void)
{
	DMA_Cmd(DMA1_Channel1, DISABLE);
	DMA_SetCurrDataCounter(DMA1_Channel1, 1);
	DMA_Cmd(DMA1_Channel1, ENABLE);
	
	while(DMA_GetFlagStatus(DMA1_FLAG_TC1) != SET);
	DMA_ClearFlag(DMA1_FLAG_TC1);
}