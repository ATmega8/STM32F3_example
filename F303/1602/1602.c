#include "main.h"

void lcd_1602_enable(void)
{
	GPIOA->ODR |= CONTROL_PORT_EN;
	delay_ms(1);
	GPIOA->ODR &= ~CONTROL_PORT_EN;
	delay_ms(1);
}

void lcd_1602_write_data(uint8_t data)
{
	GPIOC->ODR &= ~DATA_PORT_MASK;

	GPIOA->ODR |=  CONTROL_PORT_RS;
	GPIOC->ODR |= (uint16_t)((data & 0xF0) >> 4);
	lcd_1602_enable();

	GPIOC->ODR &= ~DATA_PORT_MASK;
	GPIOC->ODR |= (uint16_t)(data & 0x0F);
	lcd_1602_enable();
}

void lcd_1602_write_comd(uint8_t comd)
{
	GPIOC->ODR &= ~DATA_PORT_MASK;

	GPIOA->ODR &=  ~CONTROL_PORT_RS;
	GPIOC->ODR |= (uint16_t)((comd & 0xF0) >> 4);
	lcd_1602_enable();

	GPIOC->ODR &= ~DATA_PORT_MASK;
	GPIOC->ODR |= (uint16_t)(comd & 0x0F);
	lcd_1602_enable();
}

void lcd_1602_dis_char(uint8_t x, uint8_t y, char ptr)
{
	uint8_t addr;

	if( y == 0 )
	{
		addr = 0x80 + x;
	}
	else
	{
		addr = 0xc0 + x;
	}
	lcd_1602_write_comd(addr);
	lcd_1602_write_data(ptr);

}

void lcd_1602_dis_str(uint8_t x, uint8_t y, char *str)
{
	while( *str )
	{
		lcd_1602_dis_char(x, y, *str);
		x++;
		str++;
	}
}

void lcd_1602_gpio_init(void)
{

	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = CONTROL_PORT_EN | CONTROL_PORT_RS;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
}

void lcd_1602_init(void)
{
	uint8_t i;

	lcd_1602_gpio_init();
	
	for(i = 0; i < 10; i++)
	{
		lcd_1602_write_comd(0x33);
		lcd_1602_write_comd(0x32);
		lcd_1602_write_comd(0x28);
		lcd_1602_write_comd(0x0c);
		lcd_1602_write_comd(0x01);
	}
}

void delay_ms(uint32_t times)
{   
    SysTick->CTRL&=0xfffffffb;
	SysTick->LOAD=times*9000; //时间加载 
	SysTick->CTRL|=0x01;               //开始倒数   
	while(!(SysTick->CTRL&(1<<16)));   //等待时间到达
		SysTick->CTRL&=0XFFFFFFFE;         //关闭计数器
	SysTick->VAL=0X00000000;           //清空计数器    
}  

void delay_us(uint32_t Nus)
{ 
	SysTick->LOAD=Nus;       //时间加载     
	SysTick->CTRL|=0x01;            //开始倒数   
	while(!(SysTick->CTRL&(1<<16)));//等待时间到达
		SysTick->CTRL=0X00000000;       //关闭计数器
	SysTick->VAL=0X00000000;        //清空计数器    
}  

char *itoa(int value, char *string, int radix)
{
	uint32_t 	i, d;
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

	for(i = 100000000; i > 0; i /= 10)
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
