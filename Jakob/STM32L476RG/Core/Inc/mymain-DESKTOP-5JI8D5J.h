/*
 * Personal abstraction layer because cube's looks like ass
 *
 *
 * */

#ifndef _MYMAIN_H_
#define _MYMAIN_H_

#define ARM_MATH_CM4

#include "main.h"
#include "arm_math.h"

#define FULL_BUF_LEN 		256
#define HALF_BUF_LEN		FULL_BUF_LEN/2

DAC_HandleTypeDef hdac1;
DMA_HandleTypeDef hdma_dac_ch1;

ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim7;

// this gets called in user block 2
int mymain(void);

void dsp(void);

#endif
