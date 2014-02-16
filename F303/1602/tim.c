#include    "main.h"

void tim2_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_ICInitTypeDef TIM_ICStructure;
	TIM_TimeBaseInitTypeDef TIM_InitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOB, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	/*GPIOA的时钟初始化在LCD_1602_gpio_init中*/

	GPIO_PinAFConfig(GPIOA, GPIO_PinSource8, GPIO_AF_10);
	GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_2);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	TIM_InitStructure.TIM_ClockDivision = 0;
	TIM_InitStructure.TIM_Prescaler = 0;
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStructure.TIM_Period = 10000;
	TIM_TimeBaseInit(TIM4, &TIM_InitStructure);
	
	TIM_ICStructure.TIM_Channel = TIM_Channel_1;
	TIM_ICStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
	TIM_ICStructure.TIM_ICPrescaler = TIM_ICPSC_DIV1;
	TIM_ICStructure.TIM_ICFilter = 0x4;
	TIM_ICStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
	TIM_ICInit(TIM4, &TIM_ICStructure);
	
	TIM_SelectInputTrigger(TIM4, TIM_TS_ETRF);

	TIM_ETRConfig(TIM4, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted, 0x4);

	TIM_SelectSlaveMode(TIM4, TIM_SlaveMode_Reset);
	TIM_SelectMasterSlaveMode(TIM4, TIM_MasterSlaveMode_Enable);

	TIM_Cmd(TIM4, ENABLE);
}

void tim3_config(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	TIM_TimeBaseInitTypeDef TIM_InitStructure;

	TIM_InitStructure.TIM_ClockDivision = 0;
	TIM_InitStructure.TIM_Prescaler = 100;
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStructure.TIM_Period = 7200;
	TIM_TimeBaseInit(TIM3, &TIM_InitStructure);

	TIM_Cmd(TIM3, ENABLE);
}
