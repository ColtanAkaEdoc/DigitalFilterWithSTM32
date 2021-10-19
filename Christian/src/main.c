/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32l4xx.h"
#include "stm32l476g_discovery.h"
			

int main(void)
{
	BSP_LED_Init(LED_GREEN);
	BSP_LED_On(LED_GREEN);
	HAL_RCC_ClockConfig( )

	for(;;);
}
