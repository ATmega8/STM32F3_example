#include"main.h"

int main()
{

	adc_gpio_config();
	adc12_mode_config();
	tim3_config();
	dac_config();
	nvic_tim3_config();
	Usart2_Config();
	pga_config();
	TIM_Cmd(TIM3, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	while(1)
	{
	}
}
