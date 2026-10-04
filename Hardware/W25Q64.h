#ifndef __W25Q64_H_
#define __W25Q64_H_

void W25Q64_Init(void);
void W25Q64_ReadID(uint8_t *MID, uint16_t *DID);
void W25Q64_WaitBusy(void);
void W25Q64_EraseSector(uint32_t Address);
void W25Q64_WriteEnable(void);
void W25Q64_PageProgram(uint32_t Address, uint8_t *Array, uint16_t Count);
void W25Q64_WriteData(uint32_t Address, uint8_t *Array, uint16_t Count);
void W25Q64_ReadData(uint32_t Address, uint8_t *Array, uint16_t Count);

#endif