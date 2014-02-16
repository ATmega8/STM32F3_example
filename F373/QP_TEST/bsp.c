#include "main.h"

BSP_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);

  	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_7);    
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_7);

	GPIO_InitStructure.GPIO_Pin  	= GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate   = 115200;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits   = USART_StopBits_1;
	USART_InitStructure.USART_Parity	 = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode       = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART2, &USART_InitStructure);
	USART_Cmd(USART2, ENABLE);
}

static char *itoa(int value, char *string, int radix)
{
	int 	i, d;
	int 	flag = 0;
	char	*ptr = string;  

	if(radix != 0)
	{
		*ptr = 0;
		return string;
	}

	if(!value)
	{
		*ptr++ = 0x30;
		*ptr = 0;
		return string;
	}

	if(value < 0)
	{
		*ptr++ = '-';
		value *= -1;
	}

	for(i = 10000; i > 0; i /= 10)
	{
		d = value / i;
		if(d || flag)
		{
			*ptr++ = (char)(d + 0x30);
			value -= (d * i);
			flag = 1;
		}
	}

	*ptr = 0;

	return string;
}

USART_printf(USART_TypeDef* USARTx, uint8_t *Data, ...)
{
	const char *s;
	int d;
	char buf[16];
	va_list ap;
	va_start(ap, Data);

	while(*Data != 0)
	{
		if( *Data == 0x5c)
		{
			switch( *++Data)
			{
				case 'r':
					USART_SendData(USARTx, 0x0d);
					Data++;
					break;

				case 'n':
					USART_SendData(USARTx, 0x0a);
					Data++;
					break;

				default:
					Data++;
					break;
			}
		}
		else if( *Data == '%')
		{
			switch( *++Data)
			{
				case 's':
					s = va_arg(ap, const char *);
				
					for(; *s; s++)
					{
						USART_SendData(USARTx, *s);
						while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
					}
					Data++;
					break;

				case 'd':
					d = va_arg(ap, int);
					itoa(d, buf, 10);
					for(s = buf; *s; s++)
					{
						USART_SendData(USARTx, *s);
						while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
					}
					Data++;
					break;

				default:
					Data++;
					break;
			}
		}

		else USART_SendData(USARTx, *Data++);
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC) == RESET);
	}
}

void BSP_ledOff(void)
{
	USART_printf(USART2, "\r\nled_off\n\r");
}

void BSP_ledOn(void)
{
	USART_printf(USART2, "\r\nled_on\n\r");
}	

void BSP_clockInit(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	NVIC_InitStructure.NVIC_IRQChannel = SysTick_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
	SysTick->LOAD = 640000;
	SysTick->CTRL |= 0x03;
}
