# put your *.o targets here, make should handle the rest!
SRCS = main.c stm32f30x_it.c system_stm32f30x.c

# all the files will be generated with this name (main.elf, main.bin, main.hex, etc)

PROJ_NAME=main

# that's it, no need to change anything below this line!

###################################################

export CC=arm-none-eabi-gcc
export LD=arm-none-eabi-gcc
export AR=arm-none-eabi-ar
export AS=arm-none-eabi-as
export OBJCOPY=arm-none-eabi-objcopy
export RANLIB=arm-none-eabi-ranlib

export LDFLAGS=-Wl,-T,stm32f30_flash.ld -L../FWLib -lstm32f3 
#export CFLAGS=-g -O1 -c -nostdlib -fno-common 
#CFLAGS += -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mthumb-interwork -mlittle-endian -mfpu=fpv4-sp-d16 
#CFLAGS += -DUSE_STDPERIPH_DRIVER -DSTM32F4XX -DMANGUSTA_DISCOVERY -DHSE_VALUE=8000000
export CFLAGS=-g -O2 
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -ffreestanding -nostdlib
CFLAGS += -DSTM32F30X

#CWD = $(shell pwd)
#export ROOT=$(CWD)
#export LIB_ROOT=$(ROOT)/lib

###################################################

vpath %.c ../FWLib/src 

CFLAGS += -I../FWLib/inc -I../CMSIS/Include
CFLAGS += -I../CMSIS/Device/ST/STM32F30x/Include

SRCS += ../STARTCODE/startup_stm32f30x.s # add startup file to build

OBJS = $(SRCS:.c=.o)

###################################################

.PHONY: proj

all: 	proj


lib:
	$(MAKE) -C lib

proj: 	$(PROJ_NAME).elf

$(PROJ_NAME).elf: $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)
#	$(LD) $(LDFLAGS) --verbose -o $@ $(OBJS) -lstm32f4
	$(OBJCOPY) -O ihex $(PROJ_NAME).elf $(PROJ_NAME).hex
	$(OBJCOPY) -O binary $(PROJ_NAME).elf $(PROJ_NAME).bin

clean:
	rm -f *.o
	rm -f $(PROJ_NAME).elf
	rm -f $(PROJ_NAME).hex
	rm -f $(PROJ_NAME).bin
