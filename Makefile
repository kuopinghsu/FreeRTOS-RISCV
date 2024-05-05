FREERTOS_VER ?= V11.1.0
FREERTOS_POSIX_VER ?= e921c4f

all: check
	make -C Demo

check:
	[ -d FreeRTOS-Kernel ] || git clone -b ${FREERTOS_VER} https://github.com/FreeRTOS/FreeRTOS-Kernel.git FreeRTOS-Kernel
	[ -d FreeRTOS-POSIX ] || git clone https://github.com/FreeRTOS/Lab-Project-FreeRTOS-POSIX.git FreeRTOS-POSIX && cd FreeRTOS-POSIX && git checkout ${FREERTOS_POSIX_VER}

clean:
	make -C Demo clean

distclean:
	rm -rf FreeRTOS-Kernel FreeRTOS-POSIX

