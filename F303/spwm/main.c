#include    "main.h"


int main()
{
	tim1_config();
	dma_config();
	nvic_config();

	TIM_ARRPreloadConfig(TIM1, ENABLE);	
	TIM_OC2PreloadConfig(TIM1, TIM_OCPreload_Enable);
	TIM_CCxCmd(TIM1, TIM_Channel_2, TIM_CCx_Enable);
	TIM_CCxNCmd(TIM1, TIM_Channel_2,TIM_CCxN_Enable);
	TIM_CtrlPWMOutputs(TIM1, ENABLE);
	/*TIM_DMAConfig(TIM1, TIM_DMABase_CCR2, TIM_DMABurstLength_1Transfer);
	TIM_DMACmd(TIM1, TIM_DMA_Update, ENABLE);*/
	TIM_Cmd(TIM1, ENABLE);
	TIM_ITConfig(TIM1, TIM_IT_CC2, ENABLE);


	while( 1 )
	{
	 	
	}
}
