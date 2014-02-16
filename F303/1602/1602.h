#define     DATA_PORT GPIOC 
#define     DATA_PORT_MASK 0x000F
#define     DATA_PORT_OFFSET 0
#define     CONTROL_PORT GPIOA
#define     CONTROL_PORT_RS GPIO_Pin_0
#define     CONTROL_PORT_EN GPIO_Pin_1

void lcd_1602_enable(void);
void lcd_1602_write_data(uint8_t data);
void lcd_1602_write_comd(uint8_t comd);
void lcd_1602_dis_char(uint8_t x, uint8_t y, char ptr);
void lcd_1602_dis_str(uint8_t x, uint8_t y, char *str);
void lcd_1602_gpio_init(void);
void lcd_1602_init(void);
void delay_ms(uint32_t times);
char *itoa(int value, char *string, int radix);
