#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "MYSPI.h"
#include "W25Q64_IN.h"

void W25Q64_Init(void)
{
	MYSPI_Init();
}

void W25Q64_ReadID(uint8_t *MID, uint16_t *DID)
{
	MYSPI_Start();
	MYSPI_Swap(W25Q64_JEDEC_ID);
	*MID = MYSPI_Swap(W25Q64_DUMMY_BYTE);
	*DID = MYSPI_Swap(W25Q64_DUMMY_BYTE);
	*DID  <<= 8;
	*DID |= MYSPI_Swap(W25Q64_DUMMY_BYTE);
	
 	MYSPI_Stop();
}

void W25Q64_WaitBusy()
{
	MYSPI_Start();
	MYSPI_Swap(W25Q64_WRITE_ENABLE);
	MYSPI_Stop();
}

void W25Q64_WriteEnable(void)
{
	MYSPI_Start();
	MYSPI_Swap(W25Q64_WRITE_ENABLE);
	MYSPI_Stop();
}
