include ../Makefile.common

ROOTDIR             = $(shell cd ../.. && pwd)
FREERTOS_SOURCE_DIR = $(ROOTDIR)/FreeRTOS-Kernel

EXE      = .elf
SRC      = global.c hartstone.c whetstone.c main.c
OBJECTS  = $(SRC:.c=.o)
SYSOBJS  = ../Common/crt0.o ../Common/printf.o ../Common/syscall.o
CFLAGS  += -O2 -g -Wall
CFLAGS  += $(RISCV_GCC_OPTS)
CFLAGS  += -I$(FREERTOS_SOURCE_DIR)/include \
           -I$(FREERTOS_SOURCE_DIR)/portable/GCC/RISC-V \
           -I../Common \
           -I../conf
CFLAGS  += -Wno-return-type -Wno-implicit-function-declaration -Wno-implicit-int -flto
LDFLAGS += -flto -L.. -T ../Common/link.ld $(SYSOBJS)
LDFLAGS += -lfreertos -lc -lm -lgcc
TARGET   = hartstone
OUTPUT   = $(TARGET)$(EXE)

.SUFFIXS: .c .o
.PHONY: all clean

all: $(TARGET)

%.o: %.c global.h
	$(CC) -c -o $@ $< $(CFLAGS)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJECTS) $(LDFLAGS)
	$(OBJCOPY) -j .text -O binary $(OUTPUT) imem.bin
	$(OBJCOPY) -j .data -O binary $(OUTPUT) dmem.bin
	$(OBJCOPY) -O binary $(OUTPUT) memory.bin
	$(OBJDUMP) -d $(OUTPUT) > $(TARGET).dis
	$(READELF) -a $(OUTPUT) > $(TARGET).symbol

clean:
	$(RM) *.o $(OUTPUT) $(OBJECTS) $(TARGET).dis $(TARGET).symbol [id]mem.bin memory.bin
