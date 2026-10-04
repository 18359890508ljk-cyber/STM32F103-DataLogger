#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Series.h"
#include "W25Q64.h"

uint16_t Count = 0;
uint8_t MID;
uint16_t DID;

int main(void)
{
	OLED_Init();
	W25Q64_Init();
	
	W25Q64_ReadID(&MID, &DID);

   OLED_ShowHexNum(1, 1, MID, 2);
   OLED_ShowHexNum(2, 1, DID, 4);	
	while (1)
	{	
	}
}
