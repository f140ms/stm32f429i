TARGET=main.bin
EXECUTABLE=main.elf

CC=/scratch/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-gcc
LD=/scratch/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-ld 
AR=/scratch/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-ar
AS=/scratch/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-as
CP=/scratch/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-objcopy
OD=/scratch/opt/gcc-arm-none-eabi-9-2020-q2-update/bin/arm-none-eabi-objdump


DEFS = -DUSE_STDPERIPH_DRIVER -DSTM32F429_439xx -DHSE_VALUE=8000000
# --specs=nosys.specs = http://stackoverflow.com/questions/19419782/exit-c-text0x18-undefined-reference-to-exit-when-using-arm-none-eabi-gcc
MCU = cortex-m4
MCFLAGS = -mcpu=$(MCU) -mlittle-endian -mfpu=fpv4-sp-d16 -mfloat-abi=hard --specs=nosys.specs
STM32_INCLUDES = -I./lib/inc -I./Include

OPTIMIZE       = -Os
#-Os

CFLAGS	= $(MCFLAGS)  $(OPTIMIZE)  $(DEFS) -I./ -I./ $(STM32_INCLUDES)  -Wl,-T,STM32F429IG_FLASH.ld
AFLAGS	= $(MCFLAGS) 
#-mapcs-float use float regs. small increase in code size

SRC = main.c \
	system_stm32f4xx.c \
	lib/src/stm32f4xx_gpio.c \
	lib/src/stm32f4xx_rcc.c \
	lib/src/stm32f4xx_syscfg.c \
	lib/src/misc.c \

STARTUP = startup_stm32f429_439xx.s

OBJDIR = .
OBJ = $(SRC:%.c=$(OBJDIR)/%.o) 
OBJ += Startup.o

#sangpm - read the following article to know why we need this http://stackoverflow.com/questions/2145590/what-is-the-purpose-of-phony-in-a-makefile
.PHONY: all program clean 

all: $(TARGET)

$(TARGET): $(EXECUTABLE)
	@echo "  OBJCOPY   $@" 
	$(CP) -O binary $^ $@

$(EXECUTABLE): $(SRC) $(STARTUP)
	@echo "  CC        $@" 
	$(CC) $(CFLAGS) $^ -o $@

# sangpm - we have to use tab at the beginning of a line --> error: "missing separator.  Stop"
p2: $(TARGET)
	st-flash write $(TARGET) 0x8000000

program: $(TARGET)
	#st-flash write $(TARGET) 0x8000000
	time sudo stm32flash -w $(TARGET) /dev/ttyUSB0
	#time sudo stm32flash -w $(TARGET) -v /dev/ttyUSB0
	#st-flash write $(TARGET) 0x8000000

run:
	#st-flash write $(TARGET) 0x8000000
	sudo stm32flash -g 0x08000000 /dev/ttyUSB0
	#st-flash write $(TARGET) 0x8000000

clean:
	rm -f Startup.lst  $(TARGET)  $(TARGET).lst $(OBJ) $(AUTOGEN)  $(TARGET).out  $(TARGET).hex  $(TARGET).map \
	main.o main.bin main.elf \
	$(TARGET).dmp  $(TARGET).elf
