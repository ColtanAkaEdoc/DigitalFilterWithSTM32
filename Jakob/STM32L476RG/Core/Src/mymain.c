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

// IIR low-pass coefficients, fs=48kHz, f_cut=1kHz, q=0.707
//float iir_coeffs [5] = {
//				0.003916123487156427f,
//				0.007832246974312854f,
//				0.003916123487156427f,
//				1.8153396116625289f,
//				-0.8310041056111546
//};

// IIR band-pass coefficients, fc=1kHz, q=1
//float iir_coeffs [5] = {
//		0.007792459340162639f,
//		0,
//		-0.007792459340162639f,
//		1.9841702689557372f,
//		-0.9844150813196749f
//};


// hard low pass
//float iir_coeffs [5] = {
//		0.00006100617233135516f,
//		0.00012201234466271032f,
//		0.00006100617233135516f,
//		1.9777862754264195f,
//		-0.9780303001157449f
//};

// high pass
//float iir_coeffs [5] = {
//		0.9459763791505057f,
//		-1.8919527583010114,
//		0.9459763791505057f,
//		1.8890321271622017f,
//		-0.8948733894398211f
//};
// band pass 25khp 250ktp
//float iir_coeffs [5] = {
//		0.2930279845747092f,
//		0,
//		-0.2930279845747092f,
//		1.3695223790602151f,
//		-0.41394403085058157f
//};

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

			//toDSP_buf[i] = (float)pIn[i];
			toDSP_buf[i] = (float)(((int32_t)pIn[i])-2048);//Offset 12-bit halbe
		}

		arm_biquad_cascade_df1_f32(&iirsettings, toDSP_buf, fromDSP_buf, HALF_BUF_LEN);
		for(i = 0; i < HALF_BUF_LEN; i++){
			//pOut[i] = ((uint32_t)fromDSP_buf[i]) + (UINT16_MAX/4);
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
