#C编译器
CC = arm-none-eabi-gcc

#汇编编译器
AS = arm-none-eabi-gcc

#链接器
LD = arm-none-eabi-ld

#二进制文件生成
OBJCOPY = arm-none-eabi-objcopy

#二进制信息生成
OBJDUMP = arm-none-eabi-objdump

#生成文件的名称
TARGET = main

#需要编译的C文件
SRC = 

#需要编译的汇编文件
ASRC = main.s startup_stm32f30x.s 

ASFLAGS = -g -c -O2 -T stm32f30_flash.ld -mcpu=cortex-m4 -mlittle-endian -mthumb -mthumb-interwork 

ASFLAGS += -nostdlib -ffreestanding

#LDLIBDIR = .
#LDLIBS = stm32f3

LDFLAGS = -nostdlib  -T stm32f30_flash.ld 
#-L$(LDLIBDIR) -l $(LDLIBS)

OBJS = $(SRC:.c=.o) $(ASRC:.s=.o)

ELF = $(TARGET).elf
BIN = $(TARGET).bin
################################################################################

all: begin Compolversion Compile Link Binout Other end
begin:
	@echo
	@echo -----------------------------------begin----------------------------------------

Compolversion:
	@$(CC) -v

Compile: $(OBJS)
%.o: %.c
	$(CC) -c -o $@ $<
%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

Link: $(ELF)
$(ELF):
	$(LD) $(LDFLAGS) -o $(ELF) $(OBJS)

Binout: $(BIN)
$(BIN):
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

