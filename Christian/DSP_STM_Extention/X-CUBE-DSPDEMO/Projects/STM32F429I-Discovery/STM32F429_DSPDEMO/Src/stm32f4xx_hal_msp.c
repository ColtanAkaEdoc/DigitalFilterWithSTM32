/**
  ******************************************************************************
  * @file    STM32F429_DSPDEMO/Src/stm32f4xx_hal_msp.c
  * @author  MCD Application Team
  * @brief   HAL MSP module.
  ******************************************************************************
  *
  * COPYRIGHT(c) 2016 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
  
 /* Includes ------------------------------------------------------------------*/
#include "global.h"

/**
  * @brief  Initializes the Global MSP.
  * @param  None
  * @retval None
  */
void HAL_MspInit(void)
{
  /* NOTE : This function is generated automatically by MicroXplorer and eventually
            modified by the user
   */
}

/**
  * @brief  DeInitializes the Global MSP.
  * @param  None
  * @retval None
  */
void HAL_MspDeInit(void)
{
  /* NOTE : This function is generated automatically by MicroXplorer and eventually
            modified by the user
   */
}

/**
  * @brief DAC MSP Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO to their default state
  * @param hadc: DAC handle pointer
  * @retval None
  */
void HAL_DAC_MspInit(DAC_HandleTypeDef* hdac)
{
  GPIO_InitTypeDef          GPIO_InitStructDspDemo;
  static DMA_HandleTypeDef  hdma_dac2;

  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* DAC Periph clock enable */
  __HAL_RCC_DAC_CLK_ENABLE();
  /* Enable GPIO clock ****************************************/
  DACx_CHANNEL2_GPIO_CLK_ENABLE();
  /* DMA1 clock enable */
  DMAx_CLK_ENABLE();

  /*##-2- Configure peripheral GPIO ##########################################*/
  /* DAC Channel1 GPIO pin configuration */
  GPIO_InitStructDspDemo.Pin = DACx_CHANNEL2_PIN;
  GPIO_InitStructDspDemo.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStructDspDemo.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(DACx_CHANNEL2_GPIO_PORT, &GPIO_InitStructDspDemo);

  /*##-3- Configure the DMA streams ##########################################*/
  /* Set the parameters to be configured for Channel1*/
  hdma_dac2.Instance = DACx_DMA_STREAM6;

  hdma_dac2.Init.Channel  = DACx_DMA_CHANNEL7;
  hdma_dac2.Init.Direction = DMA_MEMORY_TO_PERIPH;
  hdma_dac2.Init.PeriphInc = DMA_PINC_DISABLE;
  hdma_dac2.Init.MemInc = DMA_MINC_ENABLE;
  hdma_dac2.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
  hdma_dac2.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
  hdma_dac2.Init.Mode = DMA_CIRCULAR;
  hdma_dac2.Init.Priority = DMA_PRIORITY_HIGH;
  hdma_dac2.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
  hdma_dac2.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_HALFFULL;
  hdma_dac2.Init.MemBurst = DMA_MBURST_SINGLE;
  hdma_dac2.Init.PeriphBurst = DMA_PBURST_SINGLE;

  HAL_DMA_Init(&hdma_dac2);

  /* Associate the initialized DMA handle to the the DAC handle */
  __HAL_LINKDMA(hdac, DMA_Handle2, hdma_dac2);

  /*##-4- Configure the NVIC for DMA #########################################*/
  /* Enable the DMA1 Stream5 IRQ Channel */
  HAL_NVIC_SetPriority(DACx_DMA_IRQn2, 2, 0);
  HAL_NVIC_EnableIRQ(DACx_DMA_IRQn2);
}
/**
  * @brief ADC MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param huart: UART handle pointer
  * @retval None
  */
void HAL_ADC_MspInit(ADC_HandleTypeDef* hadc)
{
  GPIO_InitTypeDef          GPIO_InitStructDspDemo;
  static DMA_HandleTypeDef  hdma_adc;

  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* Enable GPIO clock */
  ADCx_CHANNEL_GPIO_CLK_ENABLE();
  /* ADC3 Periph clock enable */
  ADCx_CLK_ENABLE();
  /* Enable DMA2 clock */
  DMA2_CLK_ENABLE();

  /*##-2- Configure peripheral GPIO ##########################################*/
  /* ADC3 Channel8 GPIO pin configuration */
  GPIO_InitStructDspDemo.Pin = ADCx_CHANNEL_PIN;
  GPIO_InitStructDspDemo.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStructDspDemo.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ADCx_CHANNEL_GPIO_PORT, &GPIO_InitStructDspDemo);

  /*##-3- Configure the DMA streams ##########################################*/
  /* Set the parameters to be configured */
  hdma_adc.Instance = ADCx_DMA_STREAM;

  hdma_adc.Init.Channel  = ADCx_DMA_CHANNEL;
  hdma_adc.Init.Direction = DMA_PERIPH_TO_MEMORY;
  hdma_adc.Init.PeriphInc = DMA_PINC_DISABLE;
  hdma_adc.Init.MemInc = DMA_MINC_ENABLE;
  hdma_adc.Init.PeriphDataAlignment = DMA_PDATAALIGN_HALFWORD;
  hdma_adc.Init.MemDataAlignment = DMA_MDATAALIGN_HALFWORD;
  hdma_adc.Init.Mode = DMA_CIRCULAR;
  hdma_adc.Init.Priority = DMA_PRIORITY_VERY_HIGH;
  hdma_adc.Init.FIFOMode = DMA_FIFOMODE_DISABLE;
  hdma_adc.Init.FIFOThreshold = DMA_FIFO_THRESHOLD_HALFFULL;
  hdma_adc.Init.MemBurst = DMA_MBURST_SINGLE;
  hdma_adc.Init.PeriphBurst = DMA_PBURST_SINGLE;

  HAL_DMA_Init(&hdma_adc);

  /* Associate the initialized DMA handle to the the ADC handle */
  __HAL_LINKDMA(hadc, DMA_Handle, hdma_adc);

}

/**
  * @brief ADC MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO to their default state
  * @param hadc: ADC handle pointer
  * @retval None
  */
void HAL_ADC_MspDeInit(ADC_HandleTypeDef *hadc)
{
  static DMA_HandleTypeDef  hdma_adc;

  /*##-1- Reset peripherals ##################################################*/
  ADCx_FORCE_RESET();
  ADCx_RELEASE_RESET();

  /*##-2- Disable peripherals and GPIO Clocks ################################*/
  /* De-initialize the ADC3 Channel8 GPIO pin */
  HAL_GPIO_DeInit(ADCx_CHANNEL_GPIO_PORT, ADCx_CHANNEL_PIN);

  /*##-3- Disable the DMA Streams ############################################*/
  /* De-Initialize the DMA Stream associate to transmission process */
  HAL_DMA_DeInit(&hdma_adc);

}

/**
  * @brief  DeInitializes the DAC MSP.
  * @param  hdac: pointer to a DAC_HandleTypeDef structure that contains
  *         the configuration information for the specified DAC.
  * @retval None
  */
void HAL_DAC_MspDeInit(DAC_HandleTypeDef* hdac)
{
  static DMA_HandleTypeDef  hdma_dac2;

  /*##-1- Reset peripherals ##################################################*/
  DACx_FORCE_RESET();
  DACx_RELEASE_RESET();

  /*##-2- Disable peripherals and GPIO Clocks ################################*/
  /* De-initialize the DAC Channel1 GPIO pin */
  HAL_GPIO_DeInit(DACx_CHANNEL2_GPIO_PORT, DACx_CHANNEL2_PIN);

  /*##-3- Disable the DMA Streams ############################################*/
  /* De-Initialize the DMA Stream associate to Channel1 */
  HAL_DMA_DeInit(&hdma_dac2);

  /*##-4- Disable the NVIC for DMA ###########################################*/
  HAL_NVIC_DisableIRQ(DACx_DMA_IRQn2);
}

/**
  * @brief TIM MSP Initialization
  *        This function configures the hardware resources used in this example:
  *           - Peripheral's clock enable
  *           - Peripheral's GPIO Configuration
  * @param htim: TIM handle pointer
  * @retval None
  */
void HAL_TIM_Base_MspInit(TIM_HandleTypeDef* htim)
{
  /* TIM4 Periph clock enable */
  __HAL_RCC_TIM4_CLK_ENABLE();

  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* TIMx Peripheral clock enable */
  __HAL_RCC_TIM3_CLK_ENABLE();

  /*##-2- Configure the NVIC for TIMx ########################################*/
  /* Set the TIMx priority */
  HAL_NVIC_SetPriority(TIM3_IRQn, 0, 1);

  /* Enable the TIMx global Interrupt */
  HAL_NVIC_EnableIRQ(TIM3_IRQn);

  __HAL_RCC_TIM2_CLK_ENABLE();
}

/**
  * @brief TIM MSP De-Initialization
  *        This function frees the hardware resources used in this example:
  *          - Disable the Peripheral's clock
  *          - Revert GPIO to their default state
  * @param htim: TIM handle pointer
  * @retval None
  */
void HAL_TIM_Base_MspDeInit(TIM_HandleTypeDef *htim)
{

  /*##-1- Reset peripherals ##################################################*/
  __HAL_RCC_TIM2_FORCE_RESET();
  __HAL_RCC_TIM2_RELEASE_RESET();
  __HAL_RCC_TIM4_FORCE_RESET();
  __HAL_RCC_TIM4_RELEASE_RESET();
}
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics ************************/
