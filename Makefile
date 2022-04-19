FREERTOS_VER ?= V10.4.6
FREERTOS_POSIX_VER ?= master

all: check
	make -C Demo

check:
	[ -d FreeRTOS-Kernel ] || git clone -b ${FREERTOS_VER} https://github.com/FreeRTOS/FreeRTOS-Kernel.git FreeRTOS-Kernel
	[ -d FreeRTOS-POSIX ] || git clone -b ${FREERTOS_POSIX_VER} https://github.com/FreeRTOS/Lab-Project-FreeRTOS-POSIX.git FreeRTOS-POSIX

clean:
	make -C Demo clean

distclean:
	rm -rf FreeRTOS-Kernel FreeRTOS-POSIX

