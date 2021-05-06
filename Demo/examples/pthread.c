
// An simple program to test FreeRTOS pthread
#include "FreeRTOS.h"
#include "FreeRTOS_POSIX/pthread.h"
#include "FreeRTOS_POSIX/mqueue.h"
#include "FreeRTOS_POSIX/time.h"
#include "FreeRTOS_POSIX/fcntl.h"
#include "FreeRTOS_POSIX/errno.h"

#include "printf.h"
#include "common.h"

#include <stdlib.h>

/* this function is run by the second thread */
void *inc_x(void *x_void_ptr)
{
    /* increment x to 100 */
    int *x_ptr = (int *)x_void_ptr;
    while(++(*x_ptr) < 100);

    printf("x increment finished\n");

    /* the function must return something - NULL will do */
    return NULL;
}

void test(void *param)
{
    int x = 0, y = 0;

    (void)param;

    /* show the initial values of x and y */
    printf("x: %d, y: %d\n", x, y);

    /* this variable is our reference to the second thread */
    pthread_t inc_x_thread;

    /* create a second thread which executes inc_x(&x) */
    if(pthread_create(&inc_x_thread, NULL, inc_x, &x)) {
        printf("Error creating thread\n");
        exit(1);
    }

    /* increment y to 100 in the first thread */
    while(++y < 100);

    printf("y increment finished\n");

    /* wait for the second thread to finish */
    if(pthread_join(inc_x_thread, NULL)) {
        printf("Error joining thread\n");
        exit(2);
    }

    /* show the results - x is now 100 thanks to the second thread */
    printf("x: %d, y: %d\n", x, y);

    exit(0);
}

int main(void) {
    printf( "FreeRTOS POSIX demo\n" );

    /* Start the task to run POSIX demo */
    xTaskCreate(test,
                "test",
                configMINIMAL_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY + 4,
                NULL );

    vTaskStartScheduler();

    while(1);
}

