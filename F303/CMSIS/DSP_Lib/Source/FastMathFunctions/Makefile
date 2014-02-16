CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###########################################

vpath %.c src 

CFLAGS  = -g -O2 -Wall
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -ffreestanding -nostdlib
CFLAGS += -Iinc
#CFLAGS += -Iinc -I../CMSIS/Include -I../USER 
#CFLAGS += -I../CMSIS/Device/ST/STM32F30x/Include
CFLAGS += -D ARM_MATH_CM4

SRCS = arm_cos_f32.c arm_cos_q15.c arm_cos_q31.c arm_sin_f32.c \
       arm_sin_q15.c arm_sin_q31.c arm_sqrt_q15.c arm_sqrt_q31.c

OBJS = $(SRCS:.c=.o)

.PHONY: libfastmathfunc.a

all: libfastmathfunc.a

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $^

libfastmathfunc.a: $(OBJS)
	$(AR) -r $@ $(OBJS)

clean:
	rm -f $(OBJS) libfastmathfunc.a
