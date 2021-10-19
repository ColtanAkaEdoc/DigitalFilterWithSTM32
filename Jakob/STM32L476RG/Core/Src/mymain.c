/*
 * f_name:	mymain.c
 * auth:	Jakob Tschavoll
 * ver:		1.2
 * brief:	abstraction for IDE-specific main.c for cleaner code
 * */

#include "mymain.h"

#define NS  128

uint32_t Wave_LUT[NS] = {
    2048, 2149, 2250, 2350, 2450, 2549, 2646, 2742, 2837, 2929, 3020, 3108, 3193, 3275, 3355,
    3431, 3504, 3574, 3639, 3701, 3759, 3812, 3861, 3906, 3946, 3982, 4013, 4039, 4060, 4076,
    4087, 4094, 4095, 4091, 4082, 4069, 4050, 4026, 3998, 3965, 3927, 3884, 3837, 3786, 3730,
    3671, 3607, 3539, 3468, 3394, 3316, 3235, 3151, 3064, 2975, 2883, 2790, 2695, 2598, 2500,
    2400, 2300, 2199, 2098, 1997, 1896, 1795, 1695, 1595, 1497, 1400, 1305, 1212, 1120, 1031,
    944, 860, 779, 701, 627, 556, 488, 424, 365, 309, 258, 211, 168, 130, 97,
    69, 45, 26, 13, 4, 0, 1, 8, 19, 35, 56, 82, 113, 149, 189,
    234, 283, 336, 394, 456, 521, 591, 664, 740, 820, 902, 987, 1075, 1166, 1258,
    1353, 1449, 1546, 1645, 1745, 1845, 1946, 2047
};

// global vars
uint16_t adc_buf[ADC_BUF_LEN];
uint16_t* pBuf;
uint16_t i;

// functions
int mymain(void){

	pBuf = &adc_buf[0];

	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buf, ADC_BUF_LEN);
	HAL_DAC_Start_DMA(&hdac1, DAC1_CHANNEL_1, (uint32_t*)pBuf, DAC_BUF_LEN, DAC_ALIGN_12B_R);
	HAL_TIM_Base_Start(&htim7);

	while(1){

	}
}

// callbacks
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc){

//	for(i = 0; i < ADC_BUF_LEN/2; i++){
//
//		dac_buf[i] = adc_buf[i];
//		}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){

	for(i = ADC_BUF_LEN/2; i < ADC_BUF_LEN; i++){

		dac_buf[i] = adc_buf[i];
		}
}
