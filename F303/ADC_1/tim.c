#include "main.h"


void tim3_config(void)
{	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_InitStructure;
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStructure.TIM_Period = 100;
	TIM_InitStructure.TIM_Prescaler = 64;
	TIM_InitStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseInit(TIM3, &TIM_InitStructure);
}

void nvic_tim3_config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void dac_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	DAC_InitTypeDef DAC_InitStructure;;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
	
	/*
	 * GPIOA时钟已在usart.c中初始化
	 * RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);*/
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	DAC_DeInit(); 
	DAC_InitStructure.DAC_Trigger = DAC_Trigger_None;
	DAC_InitStructure.DAC_WaveGeneration = DAC_WaveGeneration_Noise;
	DAC_InitStructure.DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bits11_0;
	DAC_InitStructure.DAC_OutputBuffer = DAC_OutputBuffer_Enable;
	DAC_Init(DAC_Channel_1, &DAC_InitStructure);
	DAC_Cmd(DAC_Channel_1, ENABLE);
}

void pga_config(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	OPAMP_InitTypeDef OPAMP_InitStructure;
	OPAMP_InitStructure.OPAMP_InvertingInput = OPAMP_InvertingInput_PGA;
	OPAMP_InitStructure.OPAMP_NonInvertingInput = OPAMP_NonInvertingInput_IO1;
	OPAMP_Init(OPAMP_Selection_OPAMP1, &OPAMP_InitStructure);

	OPAMP_PGAConfig(OPAMP_Selection_OPAMP1, OPAMP_OPAMP_PGAGain_16, OPAMP_PGAConnect_No);
	OPAMP_Cmd(OPAMP_Selection_OPAMP1, ENABLE);
}
