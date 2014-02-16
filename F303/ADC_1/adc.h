void adc_gpio_config(void);
void adc12_mode_config(void);
void Delay(__IO uint32_t nCount);
volatile uint16_t ADC_ConvertedValue;

#define ADC1_ADDRESS ((uint32_t) 0x50000000 + 0x40)
