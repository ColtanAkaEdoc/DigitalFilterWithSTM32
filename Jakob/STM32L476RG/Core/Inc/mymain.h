#ifndef _MYMAIN_H_
#define _MYMAIN_H_

#include "main.h"

/*
 * Personal abstraction layer because cube's looks like ass
 *
 *
 * */

#define ADC_BUF_LEN 4096
#define DAC_BUF_LEN	4096

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

DAC_HandleTypeDef hdac1;
DMA_HandleTypeDef hdma_dac_ch1;

TIM_HandleTypeDef htim7;
DMA_HandleTypeDef hdma_tim7_up;

UART_HandleTypeDef huart2;

// this gets called in user block 2
int mymain(void);


#endif
