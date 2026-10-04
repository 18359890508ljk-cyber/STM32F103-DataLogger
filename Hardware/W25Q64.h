#ifndef __W25Q64_H_
#define __W25Q64_H_

void W25Q64_Init(void);
void W25Q64_ReadID(uint8_t *MID, uint16_t *DID);
void W25Q64_WriteEnable(void);


#endif