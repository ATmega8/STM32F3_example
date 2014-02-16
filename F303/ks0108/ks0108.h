
/*
 * LCD硬件连接
 */

#define DATA GPIOA
#define COMD GPIOB

#define DATA_PIN ( GPIO_Pin_15 | GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12 | GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_9 | GPIO_Pin_8 ) 

#define COMD_PIN (GPIO_Pin_14 | GPIO_Pin_13 | GPIO_Pin_12 | GPIO_Pin_11 | GPIO_Pin_10)

#define RS GPIO_Pin_10
#define RW GPIO_Pin_11
#define E  GPIO_Pin_12
#define CS1 GPIO_Pin_13
#define CS2 GPIO_Pin_14

#define DATA_OFFSET 8

/*
 * KS0108控制命令
 */

#define KS0108_SCREEN_WIDTH	128
#define KS0108_SCREEN_HEIGHT	64


#define DISPLAY_SET_Y       0x40
#define DISPLAY_SET_X       0xB8
#define DISPLAY_START_LINE  0xC0
#define DISPLAY_ON_CMD		0x3E
#define ON	0x01
#define OFF	0x00
#define DISPLAY_STATUS_BUSY	0x80

/*
 * 函数声明
 */

void lcd_ks0108_delay(void);
void lcd_ks0108_controller_enable(uint8_t controller);
void lcd_ks0108_disable(uint8_t controller);
uint8_t lcd_read_status(uint8_t controller);
void lcd_ks0108_write_command(uint8_t command, uint8_t controller);
uint8_t lcd_read_data(void);
void lcd_ks0108_write_data(uint8_t data);
void lcd_ks0108_gpio_init(void);
void lcd_ks0108_init(void);
void lcd_ks0108_move(uint8_t x, uint8_t y);
void lcd_ks0108_clear_screen(void);

/*
 * 全局变量声明
 */




