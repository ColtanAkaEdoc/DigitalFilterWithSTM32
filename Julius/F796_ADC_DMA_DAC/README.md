# STM32CubeIde Project

## Target: DISCO-F769NI

[![Generic badge](https://img.shields.io/badge/Working-YES-<COLOR>.svg)](https://shields.io/)

## DMA example, using timer to trigger ADC and DAC repeatedly

Uses a timer to trigger the adc and the dac for every sample, regarding in *1 Megasample* throughput. The DMA is used to transfer data to the memory. 

Applicable to max. 100 kHz (10 Samples per sine wave)

### PA_6 is signal IN (Arduino header pin A0)
### PA_4 is signal OUT (Arduino header pin A1)

