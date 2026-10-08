# STM32F103 Data Logger

基于 STM32F103 的多外设综合学习项目。用于练习 GPIO、I2C、SPI、ADC、DMA、Timer、USART 等外设，
并逐步实现传感器数据采集、OLED 显示、W25Q64 存储和串口控制。

## Hardware

- STM32F103
- OLED Display
- W25Q64 SPI Flash
- MPU6050
- Analog input for ADC

## Development Environment

- Keil MDK
- ARMCC V5
- STM32F10x Standard Peripheral Library
- STM32F103

## Current Progress

- [x] OLED display
- [x] Hardware SPI1 initialization
- [x] SPI byte exchange
- [x] W25Q64 JEDEC ID read
- [x] W25Q64 sector erase
- [x] W25Q64 page program
- [x] W25Q64 data read
- [x] W25Q64 busy status polling
- [x] W25Q64 automatic cross-page write
- [ ] W25Q64 data logging
- [x] MPU6050 WHO_AM_I self-test
- [x] MPU6050 initialization
- [x] MPU6050 six-axis raw data reading
- [x] ADC + DMA sampling
- [ ] Timer based task scheduling
- [ ] USART command interface
- [ ] System state machine

## Current W25Q64 Test

W25Q64 is connected through SPI1.

Current SPI pins:

- PA4: CS
- PA5: SCK
- PA6: MISO
- PA7: MOSI

Current supported functions:

- JEDEC ID read
- Write Enable
- Status Register-1 read
- Busy status polling
- 4KB sector erase
- Page program
- Data read
- Automatic cross-page writing

JEDEC ID:

`EF 40 17`

## Planned Functions

The final project will support:

- Read MPU6050 sensor data
- Read ADC data through DMA
- Display real-time data on OLED
- Store data in W25Q64
- Control logging through USART commands
- Use timer flags for simple task scheduling

## Project Structure

```text
STM32F103-DataLogger/
├── Hardware/
├── Library/
├── Start/
├── System/
├── User/
└── p.uvprojx
```
