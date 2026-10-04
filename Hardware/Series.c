#include "stm32f10x.h"                  // Device header
#include "Delay.h"

uint16_t flag,lock = 0;

void Series_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_init;
	GPIO_init.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_init.GPIO_Pin = GPIO_Pin_14;
	GPIO_init.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_init);
	
	GPIO_SetBits(GPIOB, GPIO_Pin_14);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);
	
	EXTI_InitTypeDef EXTI_init;
	EXTI_init.EXTI_Line = EXTI_Line14;
	EXTI_init.EXTI_LineCmd = ENABLE;
	EXTI_init.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_init.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_Init(&EXTI_init);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_init;
	NVIC_init.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_init.NVIC_IRQChannelCmd = ENABLE;
	NVIC_init.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_init.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_init);
}

void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line14) == SET)
	{
		if(lock == 0)
		{
			flag++;
			lock = 1;
		}
		EXTI_ClearITPendingBit(EXTI_Line14);
	}
}



