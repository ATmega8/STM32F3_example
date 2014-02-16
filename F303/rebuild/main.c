#include"main.h"

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

Usart_Config()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE); 
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE); /*PC4&&PC5*/

  	GPIO_PinAFConfig(GPIOA, GPIO_PinSource2, GPIO_AF_7);    
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_7);
    //GPIO_PinAFConfig(GPIOE, GPIO_PinSource1, GPIO_AF_7);

	GPIO_InitStructure.GPIO_Pin  	= GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode 	= GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType   = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd    = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed 	= GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	/*GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_1;
	GPIO_Init(GPIOE, &GPIO_InitStructure);*/

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

/*int _write(FILE *fi, char *ptr, int len)
{
	int n;

	for (n = 0; n < len; n++) 
	{
		USART_SendData(USART1, *ptr);
		while(!(USART1->ISR & USART_FLAG_TXE));

		ptr++;
	}


	return len;
}*/
USART1_printf(USART_TypeDef* USARTx, uint8_t *Data, ...)
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

/*_sbrk(int incr) 
{
    return (caddr_t) 0;
}
int _write(int file, char *ptr, int len) 
{     
   return 0;
}

int _close(int file) 
{ 
   return -1; 
}

int _fstat(int file, struct stat *st) 
{ 
	return 0;
}
int _isatty(int file) 
{ 
	return 1; 
}
int _lseek(int file, int ptr, int dir) 
{ 
    return 0; 
}
int _read(int file, char *ptr, int len) 
{ 
	return 0;
}*/

int main()
{
	uint8_t n;

	LED_GPIO_Config();
	Usart_Config();
	
	USART1_printf(USART2, "\r\n Hollow,World! \r\n");
	USART1_printf(USART2, "\r\n 12345678\r\n");

	while(1)
	{
	}
}
