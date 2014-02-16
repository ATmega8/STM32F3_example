#include"main.h"
void delay_us(uint32_t Nus)
{ 
	SysTick->LOAD=Nus;       //时间加载     
	SysTick->CTRL|=0x01;            //开始倒数   
	while(!(SysTick->CTRL&(1<<16)));//等待时间到达
		SysTick->CTRL=0X00000000;       //关闭计数器
	SysTick->VAL=0X00000000;        //清空计数器    
}

void adc_gpio_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_ADCCLKConfig(RCC_ADC12PLLCLK_Div1);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_ADC12, ENABLE);

	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void adc12_mode_config(void)
{
	ADC_InitTypeDef		  ADC_InitStructure;
	ADC_CommonInitTypeDef ADC_CommonInitStructure;

	/*DMA_DeInit(DMA1_Channel1);
	DMA_InitStructure.DMA_PeripheralBaseAddr = ADC1_ADDRESS;
	DMA_InitStructure.DMA_MemoryBaseAddr     = (uint32_t) &ADC_ConvertedValue;
	DMA_InitStructure.DMA_DIR				 = DMA_DIR_PeripheralSRC;
	DMA_InitStructure.DMA_BufferSize		 = 1;
	DMA_InitStructure.DMA_PeripheralInc      = DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc          = DMA_MemoryInc_Disable;
	DMA_InitStructure.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize     = DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode				 = DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority			 = DMA_Priority_High;
	DMA_InitStructure.DMA_M2M           	 = DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1, &DMA_InitStructure);
	DMA_Cmd(DMA1_Channel1, ENABLE);*/

	//ADC_StructInit(&ADC_InitStructure);
	ADC_VoltageRegulatorCmd(ADC1, ENABLE);

	delay_us(100);

	ADC_SelectCalibrationMode(ADC1, ADC_CalibrationMode_Single);
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1) != RESET);

	ADC_CommonInitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_CommonInitStructure.ADC_Clock = ADC_Clock_AsynClkMode;
	ADC_CommonInitStructure.ADC_DMAAccessMode = ADC_DMAAccessMode_Disabled;
	ADC_CommonInitStructure.ADC_DMAMode = ADC_DMAMode_OneShot;
	ADC_CommonInitStructure.ADC_TwoSamplingDelay = 0;
	ADC_CommonInit(ADC1, &ADC_CommonInitStructure);

	ADC_InitStructure.ADC_Resolution = ADC_Resolution_12b;
	ADC_InitStructure.ADC_ExternalTrigConvEvent = ADC_ExternalTrigConvEvent_0;
	ADC_InitStructure.ADC_ContinuousConvMode = ADC_ContinuousConvMode_Enable;
	ADC_InitStructure.ADC_ExternalTrigEventEdge = ADC_ExternalTrigEventEdge_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_AutoInjMode = ADC_AutoInjec_Disable;
	ADC_InitStructure.ADC_NbrOfRegChannel = 1;
	ADC_Init(ADC1, &ADC_InitStructure);
	
	ADC_RegularChannelConfig(ADC1, ADC_Channel_7, 1, ADC_SampleTime_7Cycles5);

	ADC_DMAConfig(
	
	ADC_Cmd(ADC1, ENABLE);
}
void Delay(__IO uint32_t nTime)
{ 
	TimingDelay = nTime;
	while(TimingDelay != 0);
}



