#include"main.h"
/*
 *这个函数是用来初始化PE15的
 */

static void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*GPIO时钟初始化*/
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

	/*GPIOE_Pin15使能*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	/*输出模式*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	/*高速模式*/
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	/*推挽模式*/
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	/*无上拉，下拉电阻*/
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	/*初始化*/
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/*
 *这个函数是用来初始化PA0的
 */

static void EXTI_PA0_Config(void)
{
	/*定义初始化结构体*/
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	/*初始化时钟*/
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);

	/**/
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA, EXTI_PinSource0);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	EXTI_InitStructure.EXTI_Line = EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x0F;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}

int main(void)
{
	LED_GPIO_Config();
	EXTI_PA0_Config();
	
	while(1)
	{
	}
}
