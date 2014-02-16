#include"main.h"
/*
 *���������������ʼ��PE15��
 */

static void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/*GPIOʱ�ӳ�ʼ��*/
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);

	/*GPIOE_Pin15ʹ��*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	/*���ģʽ*/
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	/*����ģʽ*/
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	/*����ģʽ*/
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	/*����������������*/
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	/*��ʼ��*/
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/*
 *���������������ʼ��PA0��
 */

static void EXTI_PA0_Config(void)
{
	/*�����ʼ���ṹ��*/
	GPIO_InitTypeDef GPIO_InitStructure;
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	/*��ʼ��ʱ��*/
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
