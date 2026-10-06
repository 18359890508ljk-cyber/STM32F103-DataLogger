#ifndef __MPU6050_H_
#define __MPU6050_H_

void MPU6050_Init(void);
void MPU6050_SendByte(uint8_t SlaveAddress, uint8_t RegAddress, uint8_t Byte);
void MPU6050_Read_A_G_Data(int16_t *AX, int16_t *AY, int16_t *AZ, int16_t *GX, int16_t *GY, int16_t *GZ);

#endif