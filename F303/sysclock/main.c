#include "main.h"

int main(void)
{
	tim3_nvic_config();
	tim3_config();
	led_config();

	TIM_Cmd(TIM3, ENABLE);

	while(1)
	{

	}
}
