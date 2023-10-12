/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "STM32_F103C6.h"
#include "GPIO_driver.h"



void Clock_init()
{
	//Enable clock GPIOA
	RCC_GPIOA_CLK_EN() ;

	//Enable clock GPIOB
	RCC_GPIOB_CLK_EN();

}

void GPIO_init()
{
	GPIO_PINConfig_t PinCfg ;

	//PA1 input HighZ floting input (reset value )
	PinCfg.GPIO_PinNumber =GPIO_PIN_1;
	PinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCfg);

	//PB1 output push pull mode
	//CNF 00: General purpose output push-pull
	//01: Output mode, max speed 10 MHz
	PinCfg.GPIO_PinNumber =GPIO_PIN_1;
	PinCfg.GPIO_MODE =GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);


	//PA13 input HighZ
	PinCfg.GPIO_PinNumber =GPIO_PIN_13;
	PinCfg.GPIO_MODE =GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init(GPIOA, &PinCfg);


	//PB13  output push pull mode
	PinCfg.GPIO_PinNumber =GPIO_PIN_13;
	PinCfg.GPIO_MODE =GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_OUTPUT_SPEED =GPIO_SPEED_10M;
	MCAL_GPIO_Init(GPIOB, &PinCfg);

}

void my_wait(int x)
{
	unsigned int i , j ;
	for(i=0;i<x;i++)
		for(j=0;j<255;j++);
}

int main(void)
{
	Clock_init();
	GPIO_init();


	while(1)
	{
		//PA1 >>> Connected external PUR
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == 0) //Press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
			while (MCAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1) == 0); //Single press
		}

		//PA13 >>> Connected external PDR
		if(MCAL_GPIO_ReadPin(GPIOA, GPIO_PIN_13) == 1) //Multi Press
		{
			MCAL_GPIO_TogglePin(GPIOB, GPIO_PIN_13);
		}
		my_wait(1);
	}


	return 0;
}


