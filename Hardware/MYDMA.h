#ifndef __MYDMA_H_
#define __MYDMA_H_

void MYDMA_Init(uint32_t AddressA, uint32_t AddressB, uint16_t Size);
void MYDMA_ADC_Init(uint32_t AddressB);
void MYDMA_Transfer(void);


#endif