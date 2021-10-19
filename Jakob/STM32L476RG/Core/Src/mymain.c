#include "mymain.h"

// global vars
uint16_t adc_buf[ADC_BUF_LEN];
uint16_t dac_buf[DAC_BUF_LEN];
uint16_t i;


// functions
int mymain(void){

	HAL_ADC_Start_DMA(&hadc1, (uint32_t*)adc_buf, ADC_BUF_LEN);
	HAL_DAC_Start_DMA(&hdac1, DAC1_CHANNEL_1, (uint32_t*)dac_buf, DAC_BUF_LEN/2, DAC_ALIGN_12B_R);
	HAL_TIM_Base_Start_IT(&htim7);

	while(1);
}

// callbacks
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc){

	for(i = 0; i < ADC_BUF_LEN/2; i++){

		dac_buf[i] = adc_buf[i];
		}
}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){

	for(i = ADC_BUF_LEN/2; i < ADC_BUF_LEN; i++){

		dac_buf[i] = adc_buf[i];
		}
}

void HAL_TIM_PeriodElapsedHalfCpltCallback(TIM_HandleTypeDef* htim){

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim){

}


