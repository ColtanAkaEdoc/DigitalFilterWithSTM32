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
arm_biquad_casd_df1_inst_f32 iirsettings[N_IIR_FILTERS];

// FIR-decimator instance struct
arm_fir_decimate_instance_f32 firdsettings[N_FIR_DECIMATORS]

// 4 delayed samples per biquad
float iir_state [N_IIR_FILTERS][4];

// ? delayed samples per FIR
float fir_state [N_FIR_DECIMATORS][4];

// functions
int mymain(void){

	// start timer 6
	HAL_TIM_Base_Start(&htim6);

	// start ADC
	HAL_ADC_Start_DMA(&hadc1, adc_buf, FULL_BUF_LEN);

	// This will be deleted after enough testing has been done
	HAL_DAC_Start_DMA(&hdac1, DAC1_CHANNEL_1, dac_buf, FULL_BUF_LEN, DAC_ALIGN_12B_R);

	// create shift between timers
	HAL_Delay(1);

	// start timer 7
	HAL_TIM_Base_Start(&htim7);

	// init 30 IIR structures
	for(uint8_t i = 0; i < N_FILTERS; i++)
	{
		arm_biquad_cascade_df1_init_f32(&iirsettings[i], N_BIQUADS, &iir_coeff[i][0], &iir_state[i][0]);
	}

	// init 10 decimators
	for(uint8_t i = 0; i < N_FIR_DECIMATORS; i++)
	{
		arm_fir_decimate_init_f32(firdsettings[i], N_TAPS, (i), pCoeffs, pState, blockSize)
	}

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
