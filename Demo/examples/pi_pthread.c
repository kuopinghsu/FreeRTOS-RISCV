
// Reference: https://www.stolaf.edu/people/rab/os/pub0/modules/Pi_Integration_SharedMemory/Pthreads/Pthreads.html
// This is an example to test FreeRTOS pthread

/* FreeRTOS includes. */
#include "FreeRTOS_POSIX.h"

/* System headers. */
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* FreeRTOS+POSIX. */
#include "FreeRTOS_POSIX/pthread.h"
#include "FreeRTOS_POSIX/mqueue.h"
#include "FreeRTOS_POSIX/time.h"
#include "FreeRTOS_POSIX/fcntl.h"
#include "FreeRTOS_POSIX/errno.h"

#include "printf.h"
#include "common.h"

#define mainPOSIX_DEMO_PRIORITY    ( tskIDLE_PRIORITY + 4 )

#define NUM_RECT 1000 // 1000000000
#define NUMTHREADS 25
double  gPi = 0.0;              //  global accumulator for areas computed
pthread_mutex_t gLock;

void   *
Area (void *pArg)
{
    int     myNum = *((int *) pArg);
    double  h = 2.0 / NUM_RECT;
    double  partialSum = 0.0, x;    // local to each thread

    // use every NUMTHREADS-th ste
    for (int i = myNum; i < NUM_RECT; i += NUMTHREADS) {
        x = -1 + (i + 0.5f) * h;
        partialSum += sqrt (1.0 - x * x) * h;
    }
    pthread_mutex_lock (&gLock);
    gPi += partialSum;          // add partial to global final answer
    pthread_mutex_unlock (&gLock);
    return 0;
}

void
pi_test (void *param)
{
    pthread_t tHandles[NUMTHREADS];
    int     tNum[NUMTHREADS], i;

    (void)param;

    pthread_mutex_init (&gLock, NULL);
    for (i = 0; i < NUMTHREADS; ++i) {
        tNum[i] = i;
        pthread_create (&tHandles[i],   // Returned thread handle
                        NULL,   // Thread Attributes
                        Area,   // Thread function
                        (void *) &tNum[i]); // Data for Area()
    }
    for (i = 0; i < NUMTHREADS; ++i) {
        pthread_join (tHandles[i], NULL);
    }
    gPi *= 2.0;
    printf ("Computed value of Pi:  %12.9f\n", gPi);
    pthread_mutex_destroy (&gLock);
    exit(0);
}

int
main (void)
{

    printf( "FreeRTOS POSIX demo\n" );

    /* Start the task to run POSIX demo */
    xTaskCreate( pi_test,
                 "posix",
                 configMINIMAL_STACK_SIZE,
                 NULL,
                 mainPOSIX_DEMO_PRIORITY,
                 NULL );

    vTaskStartScheduler();

    /* Should never get here! */
    return 0;
}

