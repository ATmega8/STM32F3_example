#include "main.h"

uint8_t screenx = 0;
uint8_t screeny = 0;



void lcd_ks0108_delay(void)
{
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
	asm("nop");asm("nop");asm("nop");asm("nop");asm("nop");
}

void lcd_ks0108_enable(uint8_t controller)
{
	switch (controller)
	{
		case 0:
			GPIO_ResetBits(COMD, CS1);
			break;

		case 1:
			GPIO_ResetBits(COMD, CS2);
			break;

		default:
			break;
	}
}

void lcd_ks0108_disable(uint8_t controller)
{
	switch (controller)
	{
		case 0:
			GPIO_SetBits(COMD, CS1);
			break;

		case 1:
			GPIO_SetBits(COMD, CS2);
			break;

		default:
			break;
	}
}

uint8_t lcd_read_status(uint8_t controller)
{
	uint8_t status;
	
	/*
	 * 切换I/O为输入状态
	 */

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin  = DATA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(DATA, &GPIO_InitStructure);

	GPIO_SetBits(COMD, RW);
	GPIO_ResetBits(COMD, RS);
	lcd_ks0108_enable(controller);
	lcd_ks0108_delay();

	GPIO_SetBits(COMD, E);
	lcd_ks0108_delay();

	status = (uint8_t)(GPIO_ReadInputData(DATA) >> DATA_OFFSET);

	GPIO_ResetBits(COMD, E);
	lcd_ks0108_disable(controller);

	return status;
}

void lcd_ks0108_write_command(uint8_t command, uint8_t controller)
{
	while(lcd_read_status(controller) & DISPLAY_STATUS_BUSY);

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = DATA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(DATA, &GPIO_InitStructure);

	GPIO_ResetBits(COMD, RS | RW);
	lcd_ks0108_delay();
	lcd_ks0108_enable(controller);
	lcd_ks0108_delay();

	GPIO_SetBits(DATA, (uint16_t)(command << DATA_OFFSET));
	command ^= 0xFF;
	GPIO_ResetBits(DATA, (uint16_t)(command << DATA_OFFSET));
	lcd_ks0108_delay();

	GPIO_SetBits(COMD, E);
	lcd_ks0108_delay();

	GPIO_ResetBits(COMD, E);
	lcd_ks0108_delay();

	lcd_ks0108_disable(controller);
}

uint8_t lcd_read_data(void)
{
	uint8_t data;
	while(lcd_read_status(screenx / 64) & DISPLAY_STATUS_BUSY);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin  = DATA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(DATA, &GPIO_InitStructure);

	GPIO_SetBits(COMD, RS | RW);

	lcd_ks0108_enable(screenx / 64);
	lcd_ks0108_delay();

	GPIO_SetBits(COMD, E);
	lcd_ks0108_delay();

	data = (uint8_t)(GPIO_ReadInputData(DATA) >> DATA_OFFSET);
	GPIO_ResetBits(COMD, E);

	lcd_ks0108_disable(screenx / 64);
	screenx++;

	return data;
}

void lcd_ks0108_write_data(uint8_t data)
{ while(lcd_read_status(screenx / 64) &DISPLAY_STATUS_BUSY);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = DATA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(DATA, &GPIO_InitStructure);

	GPIO_ResetBits(COMD, RW);
	lcd_ks0108_delay();

	GPIO_SetBits(COMD, RS);
	lcd_ks0108_delay();

	GPIO_SetBits(DATA, (uint16_t)(data << DATA_OFFSET));
	data ^= 0xFF;
	GPIO_ResetBits(DATA, (uint16_t)(data << DATA_OFFSET));
	lcd_ks0108_delay();

	lcd_ks0108_enable(screenx / 64);
	lcd_ks0108_delay();

	GPIO_SetBits(COMD, E);
	lcd_ks0108_delay();

	GPIO_ResetBits(COMD, E);
	lcd_ks0108_delay();

	lcd_ks0108_disable(screenx / 64);
	screenx ++;
}

void lcd_ks0108_gpio_init(void)
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA | RCC_AHBPeriph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = DATA_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(DATA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = COMD_PIN;
	GPIO_Init(COMD, &GPIO_InitStructure);
}

void lcd_ks0108_init(void)
{
	uint8_t i;
	
	lcd_ks0108_gpio_init();

	for(i = 0; i < 3; i++)
	{
		lcd_ks0108_write_command(DISPLAY_ON_CMD | ON , i);
	}
}

void lcd_ks0108_move(uint8_t x, uint8_t y)
{
	uint8_t i;

	screenx = x;
	screeny = y;

	for(i = 0; i < KS0108_SCREEN_WIDTH / 64; i++)
	{
		lcd_ks0108_write_command(DISPLAY_SET_Y | 0, i);
		lcd_ks0108_write_command(DISPLAY_SET_X | y, i);
		lcd_ks0108_write_command(DISPLAY_START_LINE | 0, i);
	}

	lcd_ks0108_write_command(DISPLAY_SET_Y | (x % 64), x / 64);
	lcd_ks0108_write_command(DISPLAY_SET_X | y, x / 64);
}

void lcd_ks0108_clear_screen(void)
{
	uint8_t i, j;
	for(j = 0; j < KS0108_SCREEN_HEIGHT / 8; j++)
	{
		lcd_ks0108_move(0, j);
		for(i = 0; i < KS0108_SCREEN_WIDTH; i++)
		{
			lcd_ks0108_write_data(0x00);
		}
	}
}
