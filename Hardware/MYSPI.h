#ifndef __MYSPI_H_
#define __MYSPI_H_

void MYSPI_CS(uint8_t bitvalue);
void MYSPI_Init(void);
void MYSPI_Start(void);
void MYSPI_Stop(void);
uint8_t MYSPI_Swap(uint8_t Byte);

#endif