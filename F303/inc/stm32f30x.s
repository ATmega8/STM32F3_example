.equ FLASH_BASE,             0x08000000
.equ SRAM_BASE,              0x20000000
.equ PERIPH_BASE,            0x40000000
.equ SRAM_BB_BASE,           0x22000000 /*!< SRAM base address in the bit-band region ;*/
.equ PERIPH_BB_BASE,         0x42000000 /*!< Peripheral base address in the bit-band region */



.equ APB1PERIPH_BASE,       PERIPH_BASE
.equ APB2PERIPH_BASE,        PERIPH_BASE + 0x00010000 
.equ AHB1PERIPH_BASE,        PERIPH_BASE + 0x00020000 
.equ AHB2PERIPH_BASE,        PERIPH_BASE + 0x08000000 
.equ AHB3PERIPH_BASE,        PERIPH_BASE + 0x10000000 


.equ TIM2_BASE,              APB1PERIPH_BASE + 0x00000000 
.equ TIM3_BASE,              APB1PERIPH_BASE + 0x00000400 
.equ TIM4_BASE,              APB1PERIPH_BASE + 0x00000800 
.equ TIM6_BASE,              APB1PERIPH_BASE + 0x00001000 
.equ TIM7_BASE,              APB1PERIPH_BASE + 0x00001400 
.equ RTC_BASE,              APB1PERIPH_BASE + 0x00002800 
.equ WWDG_BASE,              APB1PERIPH_BASE + 0x00002C00 
.equ IWDG_BASE,              APB1PERIPH_BASE + 0x00003000 
.equ I2S2ext_BASE,           APB1PERIPH_BASE + 0x00003400 
.equ SPI2_BASE,              APB1PERIPH_BASE + 0x00003800 
.equ SPI3_BASE,              APB1PERIPH_BASE + 0x00003C00 
.equ I2S3ext_BASE,           APB1PERIPH_BASE + 0x00004000 
.equ USART2_BASE,            APB1PERIPH_BASE + 0x00004400 
.equ USART3_BASE,            APB1PERIPH_BASE + 0x00004800 
.equ UART4_BASE,             APB1PERIPH_BASE + 0x00004C00 
.equ UART5_BASE,             APB1PERIPH_BASE + 0x00005000 
.equ I2C1_BASE,              APB1PERIPH_BASE + 0x00005400 
.equ I2C2_BASE,              APB1PERIPH_BASE + 0x00005800 
.equ CAN1_BASE,              APB1PERIPH_BASE + 0x00006400 
.equ PWR_BASE,               APB1PERIPH_BASE + 0x00007000 
.equ DAC_BASE,               APB1PERIPH_BASE + 0x00007400 

/*!< APB2 peripherals */
.equ SYSCFG_BASE,            APB2PERIPH_BASE + 0x00000000 
.equ COMP_BASE,              APB2PERIPH_BASE + 0x0000001C 
.equ COMP1_BASE,             APB2PERIPH_BASE + 0x0000001C 
.equ COMP2_BASE,             APB2PERIPH_BASE + 0x00000020 
.equ COMP3_BASE,             APB2PERIPH_BASE + 0x00000024 
.equ COMP4_BASE,             APB2PERIPH_BASE + 0x00000028 
.equ COMP5_BASE,             APB2PERIPH_BASE + 0x0000002C 
.equ COMP6_BASE,             APB2PERIPH_BASE + 0x00000030 
.equ COMP7_BASE,             APB2PERIPH_BASE + 0x00000034 
.equ OPAMP_BASE,             APB2PERIPH_BASE + 0x00000038 
.equ OPAMP1_BASE,            APB2PERIPH_BASE + 0x00000038 
.equ OPAMP2_BASE,            APB2PERIPH_BASE + 0x0000003C 
.equ OPAMP3_BASE,            APB2PERIPH_BASE + 0x00000040 
.equ OPAMP4_BASE,            APB2PERIPH_BASE + 0x00000044 
.equ EXTI_BASE,              APB2PERIPH_BASE + 0x00000400 
.equ TIM1_BASE,              APB2PERIPH_BASE + 0x00002C00 
.equ SPI1_BASE,              APB2PERIPH_BASE + 0x00003000 
.equ TIM8_BASE,              APB2PERIPH_BASE + 0x00003400 
.equ USART1_BASE,            APB2PERIPH_BASE + 0x00003800 
.equ TIM15_BASE,             APB2PERIPH_BASE + 0x00004000 
.equ TIM16_BASE,             APB2PERIPH_BASE + 0x00004400 
.equ TIM17_BASE,             APB2PERIPH_BASE + 0x00004800 

/*!< AHB1 peripherals */
.equ DMA1_BASE,              AHB1PERIPH_BASE + 0x00000000 
.equ DMA1_Channel1_BASE,     AHB1PERIPH_BASE + 0x00000008 
.equ DMA1_Channel2_BASE,     AHB1PERIPH_BASE + 0x0000001C 
.equ DMA1_Channel3_BASE,     AHB1PERIPH_BASE + 0x00000030 
.equ DMA1_Channel4_BASE,     AHB1PERIPH_BASE + 0x00000044 
.equ DMA1_Channel5_BASE,     AHB1PERIPH_BASE + 0x00000058 
.equ DMA1_Channel6_BASE,     AHB1PERIPH_BASE + 0x0000006C 
.equ DMA1_Channel7_BASE,     AHB1PERIPH_BASE + 0x00000080 
.equ DMA2_BASE,              AHB1PERIPH_BASE + 0x00000400 
.equ DMA2_Channel1_BASE,     AHB1PERIPH_BASE + 0x00000408 
.equ DMA2_Channel2_BASE,     AHB1PERIPH_BASE + 0x0000041C 
.equ DMA2_Channel3_BASE,     AHB1PERIPH_BASE + 0x00000430 
.equ DMA2_Channel4_BASE,     AHB1PERIPH_BASE + 0x00000444 
.equ DMA2_Channel5_BASE,     AHB1PERIPH_BASE + 0x00000458 
.equ RCC_BASE,               AHB1PERIPH_BASE + 0x00001000 
.equ FLASH_R_BASE,           AHB1PERIPH_BASE + 0x00002000  /*!< Flash registers base address */
.equ OB_BASE,               0x1FFFF800     /*!< Flash Option Bytes base address */
.equ CRC_BASE,               AHB1PERIPH_BASE + 0x00003000 
.equ TSC_BASE,               AHB1PERIPH_BASE + 0x00004000 

/*!< AHB2 peripherals */
.equ GPIOA_BASE,             AHB2PERIPH_BASE + 0x0000 
.equ GPIOB_BASE,             AHB2PERIPH_BASE + 0x0400 
.equ GPIOC_BASE,             AHB2PERIPH_BASE + 0x0800 
.equ GPIOD_BASE,             AHB2PERIPH_BASE + 0x0C00 
.equ GPIOE_BASE,             AHB2PERIPH_BASE + 0x1000 
.equ GPIOF_BASE,             AHB2PERIPH_BASE + 0x1400 

/*!< AHB3 peripherals */
.equ ADC1_BASE,              AHB3PERIPH_BASE + 0x0000 
.equ ADC2_BASE,              AHB3PERIPH_BASE + 0x0100 
.equ ADC1_2_BASE,            AHB3PERIPH_BASE + 0x0300 
.equ ADC3_BASE,              AHB3PERIPH_BASE + 0x0400 
.equ ADC4_BASE,              AHB3PERIPH_BASE + 0x0500 
.equ ADC3_4_BASE,            AHB3PERIPH_BASE + 0x0700 

.equ DBGMCU_BASE,          0xE0042000 /*!< Debug MCU registers base address */


/*--------------------------RCC--------------------------------*/
.equ RCC_CR,                  RCC_BASE + 0x00 
.equ RCC_CFGR,                RCC_BASE + 0x04 
.equ RCC_CIR,                 RCC_BASE + 0x08 
.equ RCC_APB2RSTR,            RCC_BASE + 0x0C 
.equ RCC_APB1RSTR,            RCC_BASE + 0x10 
.equ RCC_AHBENR,              RCC_BASE + 0x14 
.equ RCC_APB2ENR,             RCC_BASE + 0x18 
.equ RCC_APB1ENR,             RCC_BASE + 0x1C 
.equ RCC_BDCR,                RCC_BASE + 0x20 
.equ RCC_CSR,                 RCC_BASE + 0x24 
.equ RCC_AHBRSTR,             RCC_BASE + 0x28 
.equ RCC_CFGR2,               RCC_BASE + 0x2C 
.equ RCC_CFGR3,               RCC_BASE + 0x30 

/*-------------------------Flash-------------------------------*/

.equ FLASH_ACR,                   FLASH_R_BASE + 0x00 
.equ FLASH_KEYR,                  FLASH_R_BASE + 0x04 
.equ FLASH_OPTKEYR,               FLASH_R_BASE + 0x08 
.equ FLASH_SR,                    FLASH_R_BASE + 0x0C 
.equ FLASH_CR,                    FLASH_R_BASE + 0x10 
.equ FLASH_AR,                    FLASH_R_BASE + 0x14 
.equ FLASH_OBR,                   FLASH_R_BASE + 0x18 
.equ FLASH_WRPR,                  FLASH_R_BASE + 0x1C 

/*-----------------------GPIO----------------------------------*/

.equ GPIOA_MODER,                 GPIOA_BASE + 0x00 
.equ GPIOA_OTYPER,                GPIOA_BASE + 0x04 
.equ GPIOA_RESERVED0,             GPIOA_BASE + 0x06 
.equ GPIOA_OSPEEDR,               GPIOA_BASE + 0x08 
.equ GPIOA_PUPDR,                 GPIOA_BASE + 0x0C 
.equ GPIOA_IDR,                   GPIOA_BASE + 0x10 
.equ GPIOA_RESERVED1,             GPIOA_BASE + 0x12 
.equ GPIOA_ODR,                   GPIOA_BASE + 0x14 
.equ GPIOA_RESERVED2,             GPIOA_BASE + 0x16 
.equ GPIOA_BSRR,                  GPIOA_BASE + 0x18 
.equ GPIOA_LCKR,                  GPIOA_BASE + 0x1C 
.equ GPIOA_AFR0,                  GPIOA_BASE + 0x20 
.equ GPIOA_BRR,                   GPIOA_BASE + 0x28 
.equ GPIOA_RESERVED3,             GPIOA_BASE + 0x2A 

.equ GPIOB_MODER,                 GPIOB_BASE + 0x00 
.equ GPIOB_OTYPER,                GPIOB_BASE + 0x04 
.equ GPIOB_RESERVED0,             GPIOB_BASE + 0x06 
.equ GPIOB_OSPEEDR,               GPIOB_BASE + 0x08 
.equ GPIOB_PUPDR,                 GPIOB_BASE + 0x0C 
.equ GPIOB_IDR,                   GPIOB_BASE + 0x10 
.equ GPIOB_RESERVED1,             GPIOB_BASE + 0x12 
.equ GPIOB_ODR,                   GPIOB_BASE + 0x14 
.equ GPIOB_RESERVED2,             GPIOB_BASE + 0x16 
.equ GPIOB_BSRR,                  GPIOB_BASE + 0x18 
.equ GPIOB_LCKR,                  GPIOB_BASE + 0x1C 
.equ GPIOB_AFR0,                  GPIOB_BASE + 0x20 
.equ GPIOB_BRR,                   GPIOB_BASE + 0x28 
.equ GPIOB_RESERVED3,             GPIOB_BASE + 0x2A 

.equ GPIOC_MODER,                 GPIOC_BASE + 0x00 
.equ GPIOC_OTYPER,                GPIOC_BASE + 0x04 
.equ GPIOC_RESERVED0,             GPIOC_BASE + 0x06 
.equ GPIOC_OSPEEDR,               GPIOC_BASE + 0x08 
.equ GPIOC_PUPDR,                 GPIOC_BASE + 0x0C 
.equ GPIOC_IDR,                   GPIOC_BASE + 0x10 
.equ GPIOC_RESERVED1,             GPIOC_BASE + 0x12 
.equ GPIOC_ODR,                   GPIOC_BASE + 0x14 
.equ GPIOC_RESERVED2,             GPIOC_BASE + 0x16 
.equ GPIOC_BSRR,                  GPIOC_BASE + 0x18 
.equ GPIOC_LCKR,                  GPIOC_BASE + 0x1C 
.equ GPIOC_AFR0,                  GPIOC_BASE + 0x20 
.equ GPIOC_BRR,                   GPIOC_BASE + 0x28 
.equ GPIOC_RESERVED3,             GPIOC_BASE + 0x2A 

.equ GPIOD_MODER,                 GPIOD_BASE + 0x00 
.equ GPIOD_OTYPER,                GPIOD_BASE + 0x04 
.equ GPIOD_RESERVED0,             GPIOD_BASE + 0x06 
.equ GPIOD_OSPEEDR,               GPIOD_BASE + 0x08 
.equ GPIOD_PUPDR,                 GPIOD_BASE + 0x0C 
.equ GPIOD_IDR,                   GPIOD_BASE + 0x10 
.equ GPIOD_RESERVED1,             GPIOD_BASE + 0x12 
.equ GPIOD_ODR,                   GPIOD_BASE + 0x14 
.equ GPIOD_RESERVED2,             GPIOD_BASE + 0x16 
.equ GPIOD_BSRR,                  GPIOD_BASE + 0x18 
.equ GPIOD_LCKR,                  GPIOD_BASE + 0x1C 
.equ GPIOD_AFR0,                  GPIOD_BASE + 0x20 
.equ GPIOD_BRR,                   GPIOD_BASE + 0x28 
.equ GPIOD_RESERVED3,             GPIOD_BASE + 0x2A 

.equ GPIOE_MODER,                 GPIOE_BASE + 0x00 
.equ GPIOE_OTYPER,                GPIOE_BASE + 0x04 
.equ GPIOE_RESERVED0,             GPIOE_BASE + 0x06 
.equ GPIOE_OSPEEDR,               GPIOE_BASE + 0x08 
.equ GPIOE_PUPDR,                 GPIOE_BASE + 0x0C 
.equ GPIOE_IDR,                   GPIOE_BASE + 0x10 
.equ GPIOE_RESERVED1,             GPIOE_BASE + 0x12 
.equ GPIOE_ODR,                   GPIOE_BASE + 0x14 
.equ GPIOE_RESERVED2,             GPIOE_BASE + 0x16 
.equ GPIOE_BSRR,                  GPIOE_BASE + 0x18 
.equ GPIOE_LCKR,                  GPIOE_BASE + 0x1C 
.equ GPIOE_AFR0,                  GPIOE_BASE + 0x20 
.equ GPIOE_BRR,                   GPIOE_BASE + 0x28 
.equ GPIOE_RESERVED3,             GPIOE_BASE + 0x2A 

/*-------------------------TIM---------------------------------*/

