/*! \file periodic_task.h
    \brief Periodic Tast Implementation
	
	@author Daniel Casini, Emiliano Palermiti, Matteo Pampana
*/

#ifndef PERIODIC_MACRO_H
#define PERIODIC_MACRO_H

/* PERIODIC MACRO */

/* TASK STRUCTURE */
/*
 * void vTask (void * pvparameters){
 *
 * 		INIT_PERIODIC()
 *
 * 		START_PERIODIC()
 *
 * 			task_body
 *
 * 		WAIT_FOR_NEXT_PERIOD()
 *
 * }
 */

#define MY_RATIO	1

#define CEILING(x,y) ((x == 0)? 0 : (1 + ((x - 1) / y)))

#define INIT_PERIODIC() \
			uint8_t index = *((uint8_t*)pvParameters); \
			deadline_miss[index] = 0; \
			deadline_met[index] = 0; \
			/*char my_buf[64];*/ \
			portTickType xAct,xResp,xCompl; \
			/*portTickType xPeriod = period[index] / (portTICK_RATE_MS*MY_RATIO); */\
			portTickType xPeriod = period[index]; \
			/*xAct = xTaskGetTickCount();*/ \
			xAct = start;

#define START_PERIODIC()\
			while(1){

/*
*/

#define WAIT_FOR_NEXT_PERIOD() \
				vTaskSuspendAll(); \
				xCompl = xTaskGetTickCount(); \
				xResp = xCompl - xAct; \
				xResp = ((xResp == 0)?1:xResp); \
				xAct = xAct + CEILING(xResp, xPeriod) * xPeriod; \
				if(CEILING(xResp,xPeriod) == 1){ \
					deadline_met[index]++; \
				}else{ \
					deadline_miss[index]++; \
				} \
				/*sprintf(my_buf,"%d) Act = %d \t Resp = %d \t Comp = %d \t AbsDead = %d \r\n",index,xAct-start,xResp,xCompl-start,xAct+xPeriod-start);*/ \
				/*console_out(my_buf);*/ \
				xTaskResumeAll(); \
				/*vTaskDelayUntil(&xCompl, xAct - xCompl); */\
				vTaskDelayUntil(&xCompl, xAct - xCompl); \
			}

/******************/

#endif
