#ifndef __MPU6050_RegADDRESS_H_
#define __MPU6050_RegADDRESS_H_

/* I2C Device Address*/

/*
 * MPU6050 7-bit address = 0x68 (AD0 = 0)
 * STM32F1 SPL I2C_Send7bitAddress() uses left-shifted address:
 * 0x68 << 1 = 0xD0
 */
#define MPUP6050_Address				0xD0

/*  Configuration Registers  */

/* Sample Rate Divider
 * Controls sensor output sample rate
 */
#define MPU6050_SMPLRT_DIV         0x19

/* Configuration Register
 * Mainly controls DLPF (Digital Low Pass Filter)
 */
#define MPU6050_CONFIG             0x1A

/* Gyroscope Configuration
 * Controls gyro full-scale range:
 */
#define MPU6050_GYRO_CONFIG        0x1B

/* Accelerometer Configuration
 * Controls accelerometer full-scale range:
 */
#define MPU6050_ACCEL_CONFIG       0x1C

/*  Accelerometer Data Registers  */

/* X-axis acceleration, 16-bit = High byte + Low byte */
#define MPU6050_ACCEL_XOUT_H       0x3B
#define MPU6050_ACCEL_XOUT_L       0x3C
#define MPU6050_ACCEL_YOUT_H       0x3D
#define MPU6050_ACCEL_YOUT_L       0x3E
#define MPU6050_ACCEL_ZOUT_H       0x3F
#define MPU6050_ACCEL_ZOUT_L       0x40

/*  Temperature Data Registers  */

/* Internal temperature sensor, 16-bit */
#define MPU6050_TEMP_OUT_H         0x41
#define MPU6050_TEMP_OUT_L         0x42


#define MPU6050_GYRO_XOUT_H        0x43
#define MPU6050_GYRO_XOUT_L        0x44
#define MPU6050_GYRO_YOUT_H        0x45
#define MPU6050_GYRO_YOUT_L        0x46
#define MPU6050_GYRO_ZOUT_H        0x47
#define MPU6050_GYRO_ZOUT_L        0x48

/* 
Power Management Registers 
*/

/* Power Management 1
 * Controls device reset, sleep mode and clock source
 * SLEEP bit = 0 -> MPU6050 wakes up
 */
#define MPU6050_PWR_MGMT_1   0x6B 

/* Power Management 2
 * Controls standby state of accelerometer and gyroscope axes
 * STBY_XA / YA / ZA
 * STBY_XG / YG / ZG
 */
#define MPU6050_PWR_MGMT_2   0x6C 


/*  Device Identification  */

/* Device identity register
 * MPU6050 normally returns 0x68
 */
#define MPU6050_WHO_AM_I     0x75

#endif