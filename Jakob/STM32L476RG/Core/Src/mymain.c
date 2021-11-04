/*
 * f_name:	mymain.c
 * auth:	Jakob Tschavoll
 * ver:		1.2
 * brief:	abstraction for IDE-specific main.c for cleaner code
 * */

#include "mymain.h"
#include "coeff.h"

// buffers
uint32_t adc_buf[FULL_BUF_LEN];
uint32_t dac_buf[FULL_BUF_LEN];
float toDSP_buf[HALF_BUF_LEN];
float fromDSP_buf[HALF_BUF_LEN];
volatile static uint32_t* pIn = &adc_buf[0];
volatile static uint32_t* pOut = &dac_buf[HALF_BUF_LEN];

// flags
uint16_t i;
uint8_t hlfcplt = 0;
uint8_t cplt = 0;

// IIR-filter instance struct
arm_biquad_casd_df1_inst_f32 iirsettings;

// 4 delayed samples per biquad
float iir_state [4];

// functions
int mymain(void){

	HAL_TIM_Base_Start(&htim6);
	HAL_ADC_Start_DMA(&hadc1, adc_buf, FULL_BUF_LEN);
	HAL_DAC_Start_DMA(&hdac1, DAC1_CHANNEL_1, dac_buf, FULL_BUF_LEN, DAC_ALIGN_12B_R);

	HAL_Delay(1);


	//init IIR structure

	arm_biquad_cascade_df1_init_f32 ( &iirsettings, 1, &iir_coeff[17][0], &iir_state[0]);

	HAL_TIM_Base_Start(&htim7);
	while(1){
		dsp();
	}
}

void dsp(void){

	if(hlfcplt || cplt){

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
		for(i = 0; i < HALF_BUF_LEN; i++){

			toDSP_buf[i] = (float)(((int32_t)pIn[i])-2048);//Offset 12-bit halbe
		}

		arm_biquad_cascade_df1_f32(&iirsettings, toDSP_buf, fromDSP_buf, HALF_BUF_LEN);

		for(i = 0; i < HALF_BUF_LEN; i++){

			pOut[i] = ((uint32_t)(fromDSP_buf[i]+2048));//Offset 12-bit halbe
		}

		hlfcplt = 0;
		cplt = 0;
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	}
}

// callbacks
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc){


	pIn = &adc_buf[0];
	pOut = &dac_buf[HALF_BUF_LEN];
	hlfcplt = 1;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);

}

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc){

	pIn = &adc_buf[HALF_BUF_LEN];
	pOut = &dac_buf[0];
	cplt = 1;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
}
