#include "main.h"

int main(void)
{
	lcd_1602_init();
	tim2_config();
	tim3_config();
	nvic_config();

	TIM_ITConfig(TIM4, TIM_IT_CC1, ENABLE);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);

	while( 1 )
	{
	 
	}
}
