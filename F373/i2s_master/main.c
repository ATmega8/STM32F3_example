#include "main.h"

int main(void)
{
	uint32_t t_data = 0x123456;
	uint16_t r_data = 0x1234;
	static uint8_t counter = 0;

	i2s_config();	
	Usart2_Config();
	I2S_Cmd(SPI1, ENABLE);	
	USART_Cmd(USART2, ENABLE);
	SPI_I2S_ITConfig(SPI1, SPI_I2S_IT_TXE, ENABLE);
	while(1)
	{
		/*while(USART_GetFlagStatus(USART2, USART_FLAG_RXNE) == SET)
		{	
			if(counter == 0)
			{
				r_data = USART_ReceiveData(USART2) << 8;
				counter = 1;
			}
			else if( counter == 1)
			{
				r_data |= (uint8_t)USART_ReceiveData(USART2);
				counter = 0;
			}

			SPI_I2S_SendData16(SPI1, (uint16_t)(r_data) );
			while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE)  !=  RESET);
		}*/
	}
}

