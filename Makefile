FREERTOS_VER ?= V10.4.5
FREERTOS_POSIX_VER ?= v1.0

all: check
	make -C Demo

check:
	[ -d Source ] || git clone -b ${FREERTOS_VER} https://github.com/FreeRTOS/FreeRTOS-Kernel.git Source
	[ -d FreeRTOS-POSIX ] || git clone -b ${FREERTOS_POSIX_VER} https://github.com/FreeRTOS/Lab-Project-FreeRTOS-POSIX.git FreeRTOS-POSIX

clean:
	make -C Demo clean

distclean:
	rm -rf Source FreeRTOS-POSIX

