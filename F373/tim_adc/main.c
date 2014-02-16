#include"main.h"

#define SHUT_DOWN      0x0900
#define DECODE_MODE    0x0A00
#define SCAN_LIMIT     0x0B00
#define INTENSITY      0x0C00
#define DISPLAY_TEST   0x0F00


int main()
{
	TIM_Config();
	//ADC_Config();

	//TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	//TIM_Cmd(TIM2, ENABLE);
	//ADC_ITConfig(ADC1, ADC_IT_EOC, ENABLE);




	while(1)
	{

	}
}
