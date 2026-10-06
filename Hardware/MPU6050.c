#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "MYI2C.h"
#include "MPU6050_RegADDRESS.h"
 
void MPU6050_Init(void)
{
	MYI2C_Init();
	MYI2C_WriteReg(MPUP6050_Address, MPU6050_PWR_MGMT_1, 0x01);
	MYI2C_WriteReg(MPUP6050_Address, MPU6050_PWR_MGMT_2, 0x00);
  MYI2C_WriteReg(MPUP6050_Address, MPU6050_SMPLRT_DIV, 0x09);
  MYI2C_WriteReg(MPUP6050_Address, MPU6050_CONFIG, 0x06);
  MYI2C_WriteReg(MPUP6050_Address, MPU6050_GYRO_CONFIG, 0x18);
  MYI2C_WriteReg(MPUP6050_Address, MPU6050_ACCEL_CONFIG, 0x18);
}

void MPU6050_SendByte(uint8_t SlaveAddress, uint8_t RegAddress, uint8_t Byte)
{
	MYI2C_WriteReg(SlaveAddress, RegAddress, Byte);
}

void MPU6050_Read_A_G_Data(int16_t *AX, int16_t *AY, int16_t *AZ, int16_t *GX, int16_t *GY, int16_t *GZ)
{
	uint8_t Data_H, Data_L;
	Data_H = MYI2C_ReadReg(MPUP6050_Address, MPU6050_ACCEL_XOUT_H);
	Data_L = MYI2C_ReadReg(MPUP6050_Address, MPU6050_ACCEL_XOUT_L);
	*AX = (Data_H << 8) | Data_L;
	
	Data_H = MYI2C_ReadReg(MPUP6050_Address, MPU6050_ACCEL_YOUT_H);
	Data_L = MYI2C_ReadReg(MPUP6050_Address, MPU6050_ACCEL_YOUT_L);
	*AY = (Data_H << 8) | Data_L;
	
	Data_H = MYI2C_ReadReg(MPUP6050_Address, MPU6050_ACCEL_ZOUT_H);
	Data_L = MYI2C_ReadReg(MPUP6050_Address, MPU6050_ACCEL_ZOUT_L);
	*AZ = (Data_H << 8) | Data_L;
	
	Data_H = MYI2C_ReadReg(MPUP6050_Address, MPU6050_GYRO_XOUT_H);
	Data_L = MYI2C_ReadReg(MPUP6050_Address, MPU6050_GYRO_XOUT_L);
	*GX = (Data_H << 8) | Data_L;
	
	Data_H = MYI2C_ReadReg(MPUP6050_Address, MPU6050_GYRO_YOUT_H);
	Data_L = MYI2C_ReadReg(MPUP6050_Address, MPU6050_GYRO_YOUT_L);
	*GY = (Data_H << 8) | Data_L;
	
	Data_H = MYI2C_ReadReg(MPUP6050_Address, MPU6050_GYRO_ZOUT_H);
	Data_L = MYI2C_ReadReg(MPUP6050_Address, MPU6050_GYRO_ZOUT_L);
	*GZ = (Data_H << 8) | Data_L;
}

