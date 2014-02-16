CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###########################################

vpath %.c src 

CFLAGS  = -g -O2 -Wall
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -ffreestanding -nostdlib
CFLAGS += -Iinc -I../CMSIS/Include -I../USER 
CFLAGS += -I../CMSIS/Device/ST/STM32F30x/Include
CFLAGS += -D USE_STDPERIPH_DRIVER 

#SRCS  = stm32f3_discovery.c
SRCS = stm32f30x_adc.c stm32f30x_dma.c stm32f30x_misc.c stm32f30x_syscfg.c \
	stm32f30x_can.c stm32f30x_exti.c stm32f30x_opamp.c stm32f30x_tim.c \
	stm32f30x_comp.c stm32f30x_flash.c stm32f30x_pwr.c stm32f30x_usart.c \
	stm32f30x_crc.c stm32f30x_gpio.c stm32f30x_rcc.c stm32f30x_wwdg.c \
	stm32f30x_dac.c stm32f30x_i2c.c stm32f30x_rtc.c \
	stm32f30x_dbgmcu.c stm32f30x_iwdg.c stm32f30x_spi.c

OBJS = $(SRCS:.c=.o)

.PHONY: libstm32f3.a

all: libstm32f3.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libstm32f3.a: $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) libstm32f3.a
