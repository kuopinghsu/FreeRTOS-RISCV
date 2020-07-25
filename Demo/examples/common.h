#ifndef __COMMON_H

#if configUSE_MALLOC_FAILED_HOOK
void vApplicationMallocFailedHook ( void )
{
    puts("\nMalloc fail, stopping.");
    exit(0);
}
#endif

#if configCHECK_FOR_STACK_OVERFLOW
void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName )
{
    printf("\n%s: Stack overflow, stopping.", pcTaskName);
    exit(0);
}
#endif

#endif // __COMMON_H
