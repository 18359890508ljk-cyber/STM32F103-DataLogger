#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void MYSPI_CS(uint8_t bitvalue)
{
	GPIO_WriteBit(GPIOB, GPIO_Pin_4, (BitAction)bitvalue);
	Delay_us(5);
}

void MYSPI_Start(void)
{
	MYSPI_CS(0);
}

void MYSPI_Stop(void)
{
	MYSPI_CS(1);
}

void MYSPI_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitKey;
	GPIO_InitKey.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitKey.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitKey.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitKey);
	
	GPIO_InitKey.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitKey.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7;
	GPIO_InitKey.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitKey);
	
	GPIO_InitKey.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitKey.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitKey.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitKey);
	
	SPI_InitTypeDef SPI_init;
	SPI_init.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_128;
	SPI_init.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_init.SPI_CPOL = SPI_CPOL_Low;
	SPI_init.SPI_CRCPolynomial = 0x0007;
	SPI_init.SPI_DataSize = SPI_DataSize_8b;
	SPI_init.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_init.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_init.SPI_Mode = SPI_Mode_Master;
	SPI_init.SPI_NSS = SPI_NSS_Soft;
	SPI_Init(SPI1, &SPI_init);
	
	SPI_Cmd(SPI1, ENABLE);
	
	MYSPI_CS(1);
}

uint8_t MYSPI_Swap(uint8_t Byte)
{
	uint8_t Data = 0x00;
	MYSPI_Start();
	
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE) != SET);
	SPI_I2S_SendData(SPI1, Byte);
	
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_RXNE) != SET);
	Data = SPI_I2S_ReceiveData(SPI1);
	
	return Data;
}