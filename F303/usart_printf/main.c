#include"main.h"
void delay_ms(uint32_t times)
{   
    SysTick->CTRL&=0xfffffffb;
	SysTick->LOAD=times*9000; //时间加载 
	SysTick->CTRL|=0x01;               //开始倒数   
	while(!(SysTick->CTRL&(1<<16)));   //等待时间到达
		SysTick->CTRL&=0XFFFFFFFE;         //关闭计数器
	SysTick->VAL=0X00000000;           //清空计数器    
}
int main()
{

	uint16_t i = 1234;
    char *s = "hehe";

	Usart2_Config();
	 

	while(1)
	{
		USART_printf(USART2, "\r\n Hollow,World! \r\n");
		delay_ms(10);
		
	}

	while(1)
	{
	}
}
