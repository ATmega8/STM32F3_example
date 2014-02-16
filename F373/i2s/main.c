#include "main.h"
#define I2S_SLAVE_RECEIVER

int main(void)
{
	uint32_t t_data = 0x123456;
	uint32_t r_data = 0;

	i2s_config();	
	Usart2_Config();
	I2S_Cmd(SPI1, ENABLE);
	SPI_I2S_ITConfig(SPI1, SPI_I2S_IT_RXNE, ENABLE);
	USART_printf(USART2, "Sys Init Ok!");	
	while(1)
	{

	}
}

