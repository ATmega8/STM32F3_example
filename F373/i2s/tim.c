#include "main.h"

void IR_timer_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructurc;
	TIM_TimeBaseInitTypeDef TIM_InitStructure;
 	TIM_OCInitTypeDef TIM_OCInitStructure;

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM16 | RCC_APB2Periph_TIM17, ENABLE);

	GPIO_InitStructurc.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructurc.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructurc.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructurc.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructurc.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOB, &GPIO_InitStructurc);

	GPIO_PinAFConfig(GPIOB, GPIO_PinSource9, GPIO_AF_6);

	TIM_InitStructure.TIM_Period = 32;
	TIM_InitStructure.TIM_Prescaler = 0;
	TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_InitStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseInit(TIM16 ,&TIM_InitStructure);

	TIM_InitStructure.TIM_Period = 1000;
	TIM_InitStructure.TIM_Prescaler = 64;
	TIM_TimeBaseInit(TIM17,  &TIM_InitStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle;
	TIM_OCInitStructure.TIM_OutputState = ENABLE;
	TIM_OCInitStructure.TIM_OutputNState = DISABLE;
	TIM_OCInitStructure.TIM_Pulse = 16;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
	TIM_OC1Init(TIM16, &TIM_OCInitStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_Toggle;
	TIM_OCInitStructure.TIM_OutputState = ENABLE;
	TIM_OCInitStructure.TIM_OutputNState = DISABLE;
	TIM_OCInitStructure.TIM_Pulse = 500;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCNPolarity = TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OCIdleState = TIM_OCIdleState_Set;
	TIM_OCInitStructure.TIM_OCNIdleState = TIM_OCNIdleState_Set;
	TIM_OC1Init(TIM17, &TIM_OCInitStructure);

	TIM_CCxCmd(TIM16, TIM_Channel_1, TIM_CCx_Enable);
	TIM_CCxCmd(TIM17, TIM_Channel_1, TIM_CCx_Enable);
	TIM_Cmd(TIM16, ENABLE);
	TIM_Cmd(TIM17, ENABLE);
}
