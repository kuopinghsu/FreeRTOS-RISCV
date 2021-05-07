

// An simple program to test FreeRTOS pthread
#include "FreeRTOS.h"
#include "FreeRTOS_POSIX.h"
#include "FreeRTOS_POSIX/pthread.h"
#include "FreeRTOS_POSIX/mqueue.h"
#include "FreeRTOS_POSIX/time.h"
#include "FreeRTOS_POSIX/fcntl.h"
#include "FreeRTOS_POSIX/errno.h"

#include <stdlib.h>

#define PTHREAD_INIT(func)                  \
int main(void) {                            \
    printf( "FreeRTOS POSIX demo\n" );      \
                                            \
    /* Start the task to run POSIX demo */  \
    xTaskCreate(func,                       \
                "init",                     \
                configMINIMAL_STACK_SIZE,   \
                NULL,                       \
                tskIDLE_PRIORITY + 4,       \
                NULL );                     \
                                            \
    vTaskStartScheduler();                  \
                                            \
    while(1);                               \
}

