include ./Makefile.common

FREERTOS_SRC = \
    $(FREERTOS_SOURCE_DIR)/croutine.c \
    $(FREERTOS_SOURCE_DIR)/list.c \
    $(FREERTOS_SOURCE_DIR)/queue.c \
    $(FREERTOS_SOURCE_DIR)/tasks.c \
    $(FREERTOS_SOURCE_DIR)/timers.c \
    $(FREERTOS_SOURCE_DIR)/event_groups.c \
    $(FREERTOS_SOURCE_DIR)/portable/MemMang/heap_3.c

PORT_SRC = $(FREERTOS_SOURCE_DIR)/portable/GCC/RISC-V/port.c \
           Common/syscall.c

PORT_ASM = $(FREERTOS_SOURCE_DIR)/portable/GCC/RISC-V/portASM.S \
           Common/crt0.S

DEMO_SRC = examples/demo.c

RTOS_OBJ = $(FREERTOS_SRC:.c=.o)
PORT_OBJ = $(PORT_SRC:.c=.o)
PORT_ASM_OBJ = $(PORT_ASM:.S=.o)
DEMO_OBJ = $(DEMO_SRC:.c=.o)
OBJS = $(PORT_ASM_OBJ) $(PORT_OBJ) $(RTOS_OBJ) $(DEMO_OBJ)

INCLUDES = \
    -I$(FREERTOS_SOURCE_DIR)/include \
	-I$(FREERTOS_SOURCE_DIR)/portable/GCC/RISC-V \
    -I./Common \
    -I./conf \
    -I./examples

CFLAGS   = -O2 -g -Wall $(INCLUDES) $(RISCV_GCC_OPTS)
LDFLAGS  = -T Common/link.ld $(RISCV_GCC_OPTS)
LIBS     = -lc -lgcc
PROG	 = demo

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

%.o: %.S
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(PROG).elf

$(PROG).elf: $(OBJS) Makefile
	$(CC) -o $@ $(OBJS) $(LIBS) $(LDFLAGS)
	$(OBJDUMP) -d $@ > $(PROG).dis

clean:
	$(RM) -f $(OBJS) $(PROG).elf $(PROG).dis

