#C编译器
CC = arm-none-eabi-gcc

#汇编编译器
AS = arm-none-eabi-as

#链接器
LD = arm-none-eabi-ld

#二进制文件生成
OBJCOPY = arm-none-eabi-objcopy

#二进制信息生成
OBJDUMP = arm-none-eabi-objdump

#生成文件的名称
TARGET = main

#需要编译的C文件
SRC = stm32f37x_it.c ../src/system_stm32f37x.c main.c bsp.c 

#需要编译的汇编文件
ASRC = 

#启动文件
ASRC += ../STARTCODE/startup_stm32f37x.s ../STARTCODE/qk_port.s
#寄存器定义
#ASRC += ../inc/stm32f30x.s

INCDIR =  -I ../inc 
INCDIR += -I ../CMSIS/Include 
INCDIR += -I../CMSIS/Device/ST/STM32F37x/Include

CFLAGS = -g -c -O2 -T STM32_FLASH.ld $(INCDIR) 
CFLAGS += -mcpu=cortex-m4 -mlittle-endian -mthumb -mthumb-interwork 
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS += -nostdlib -ffreestanding -fno-builtin
#-Dprintf=iprintf

ASFLAGS = -g -c -mcpu=cortex-m4 -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASFLAGS +=  

LDLIBDIR = ../lib

LDLIBS = ../lib/libstm32f3.a ../lib/libstm32f3_qp.a


LDFLAGS = -T ../ldfile/STM32_FLASH.ld -L$(LDLIBDIR)  $(LDLIBS) -mcpu=cortex-m4 -mlittle-endian -mthumb -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16 

OBJS = $(SRC:.c=.o) $(ASRC:.s=.o)

ELF = $(TARGET).elf
BIN = $(TARGET).hex
################################################################################

all: begin Compolversion Compile Link Binout Other end
begin:
	@echo
	@echo -----------------------------------begin----------------------------------------

Compolversion:
	@$(CC) -v
	@echo 
	@echo Compile:
	@echo
Compile: $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<  
%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<
	@echo 
	@echo Link:
	@echo	
Link: $(ELF)
$(ELF):
	$(CC) --specs=nano.specs -Wl,--start-group -lgcc -lc -lc -lm -lnosys -Wl,--end-group $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(ELF) 
#-L /opt/gcc-arm-none-eabi-4_7-2013q2/lib/gcc/arm-none-eabi/4.7.4/armv7e-m/fpu/ -lc -lgcc  
	@echo 
	@echo Binout:
	@echo
Binout: $(BIN)
$(BIN):
	$(OBJCOPY) -O ihex $(TARGET).elf $(TARGET).hex
	$(OBJCOPY) -O binary $(TARGET).elf $(TARGET).bin

Other:$(TARGET).lst
$(TARGET).lst:
	$(OBJDUMP) -S $(ELF) > $(TARGET).lst


end:
	@echo
	@echo -----------------------------------end------------------------------------------

clean:
	rm -f *.o
	rm -f *.elf
	rm -f *.bin
	rm -f *.lst
	rm -f *.mem
	rm -f *.map
	rm -f *.hex

