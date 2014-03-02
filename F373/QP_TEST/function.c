#include "main.h"

/*char *hex_str(int32_t data)
{
    char *
    uint32_t temp, i;

    for(i = 0; i < 4; i++)
    {

    }


}*/

void __attribute__((__no_instrument_function__))
     __cyg_profile_func_enter(void *this_func, void *call_site)
{


    char s[16] = "\r\nE:0x00000000\n\r";

    uint32_t temp, i;

    for(i = 0; i < 8; i++)
    {
        temp = (((uint32_t)this_func >> i*4) & 0xf);

        if(temp < 10)
            s[13-i] = temp + 0x30;
        else
            s[13-i] = temp + 0x37;

    }

    for(i = 0; i < 16; i++)
    {
		USART_SendData(USART2, s[i]);
		while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
    }

}
void __attribute__((__no_instrument_function__))
     __cyg_profile_func_exit(void *this_func, void *call_site)
{
    char s[16] ="\r\nX:0x00000000\n\r";


    uint32_t temp, i;

    for(i = 0; i < 8; i++)
    {
        temp = (((uint32_t)this_func >> i*4) & 0xf);

        if(temp < 10)
            s[13-i] = temp + 0x30;
        else
            s[13-i] = temp + 0x37;

    }

    for(i = 0; i < 16; i++)
    {
		USART_SendData(USART2, s[i]);
		while(USART_GetFlagStatus(USART2, USART_FLAG_TC) == RESET);
    }
}

