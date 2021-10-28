/*
 * f_name:	mymain.c
 * auth:	Jakob Tschavoll
 * ver:		1.2
 * brief:	abstraction for IDE-specific main.c for cleaner code
 * */

#include "mymain.h"

// global vars
uint16_t adc_buf[FULL_BUF_LEN];
uint16_t dac_buf[FULL_BUF_LEN];
uint16_t i;

static volatile uint16_t* pIn = &adc_buf[0];
static volatile uint16_t* pOut = &dac_buf[HALF_BUF_LEN];

uint8_t hlfcplt = 0;
uint8_t cplt = 0;


// functions
int mymain(void){

	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buf, FULL_BUF_LEN);
	HAL_DAC_Start_DMA(&hdac1, DAC1_CHANNEL_1, (uint32_t*)dac_buf, FULL_BUF_LEN, DAC_ALIGN_12B_R);
	HAL_TIM_Base_Start(&htim6);
	HAL_Delay(1);
	HAL_TIM_Base_Start(&htim7);

	while(1){

		dsp();
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	}
}

void dsp(void){

	if(hlfcplt){
		for(i = 0; i < HALF_BUF_LEN; i++){
			pOut[i] = pIn[i];
		}
		hlfcplt = 0;
	}
	if(cplt){
		for(i = 0; i < HALF_BUF_LEN; i++){
			pOut[i] = pIn[i];
		}
		cplt = 0;
	}
}

// callbacks
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc){


	pIn = &adc_buf[0];
	pOut = &dac_buf[HALF_BUF_LEN];
	hlfcplt = 1;

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){

	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
	pIn = &adc_buf[HALF_BUF_LEN];
	pOut = &dac_buf[0];
	cplt = 1;
}
