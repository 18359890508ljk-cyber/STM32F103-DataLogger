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
- [ ] MPU6050 self-test
- [ ] ADC + DMA sampling
- [ ] Timer based task scheduling
- [ ] USART command interface
- [ ] W25Q64 data logging
- [ ] System state machine

## Current W25Q64 Test

W25Q64 is connected through SPI1.

Current SPI pins:

- PA4: CS
- PA5: SCK
- PA6: MISO
- PA7: MOSI

The JEDEC ID can be read successfully.

Expected result:

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
