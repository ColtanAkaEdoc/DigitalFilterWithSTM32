#ifndef _MYMAIN_H_
#define _MYMAIN_H_

#include "main.h"

/*
 * Personal abstraction layer because cube's looks like ass
 *
 *
 * */

#define ADC_BUF_LEN 512
#define DAC_BUF_LEN	ADC_BUF_LEN/2

DAC_HandleTypeDef hdac1;
DMA_HandleTypeDef hdma_dac_ch1;

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

TIM_HandleTypeDef htim7;

// this gets called in user block 2
int mymain(void);


#endif
