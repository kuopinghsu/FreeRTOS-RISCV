/*! \file hartstone.h
    \brief Hartstone Benchmark implementation
	
	@author Daniel Casini, Emiliano Palermiti, Matteo Pampana
*/

#ifndef HARTSTONE_H
#define HARTSTONE_H

#include <stdio.h>
#include <stdlib.h>
#include "global.h"
#include "printf.h"

/*! \fn		void vManagementTask( void * pvParameters )
    \brief  Task Body of the main task that performs the Benchmark Management
	\param  pvParameters	Pointer to the parameters structure
*/
void vManagementTask( void * pvParameters );

/*! \fn		void vGenericTask( void * pvParameters )
    \brief  Task Body of the generic periodic task used during the Benchmark
	\param  pvParameters	Pointer to the parameters structure
*/
void vGenericTask( void * pvParameters );

/*! \fn		void vGenericTaskExp3( void * pvParameters )
    \brief  Task Body of the generic periodic task used during Experiment 3
	\param  pvParameters	Pointer to the parameters structure
*/
void vGenericTaskExp3( void * pvParameters );

/*! \fn		void hartstone_raw_speed()
    \brief  Performs the raw speed computation, updating the raw_speed global variable.
*/
void hartstone_raw_speed();

/*! \fn		uint8_t total_deadline_miss()
    \brief  Returns the sum of the entire missed deadlines generated during a single test
    \return The missed deadlines sum
*/
uint8_t total_deadline_miss();

/*! \fn		void baseline_test_init()
    \brief  Reset the task set parameters to the Baseline configuration
*/
void baseline_test_init();

/*! \fn		void scale_frequencies(float scale)
    \brief  Scales the frequencies of a scale factor ( frequency[i] = frequency[i] * scale )
    \param	scale Scaling Factor
*/
void scale_frequencies(float scale);

/*! \fn		void increment_workload()
    \brief  Increments the task loads by an amount of WORKLOAD_STEP ( load[i] = load[i] * WORKLOAD_STEP )
*/
void increment_workload();

/*! \fn		void hartstone_print_report(uint8_t experiment_num, uint8_t test_num,uint8_t additional)
    \brief  Prints the current test results
    \param	experiment_num		Experiment Number
 	\param	test_num			Test Number
 	\param	additional			Number of additional tasks added
*/
void hartstone_print_report(uint8_t experiment_num, uint8_t test_num,uint8_t additional);

/*! \fn		void hartstone_create_taskset(uint8_t additional, pdTASK_CODE pvTaskCode)
    \brief  Creates the task set required for the specific experiment
 	\param	additional	Number of additional tasks added
 	\param	pvTaskCode	Pointer to the tasks body to be created
*/
void hartstone_create_taskset(uint8_t additional, pdTASK_CODE pvTaskCode);

/*! \fn		void hartstone_delete_taskset(uint8_t additional)
    \brief  Deletes the task set previously built for the specific experiment
 	\param	additional	Number of additional tasks added
*/
void hartstone_delete_taskset(uint8_t additional);

/*! \fn		float hartstone_step_size(uint8_t experiment_num)
    \brief  Computes the step size depending on the specific experiment
	\param	experiment_num	Experiment number
	\return Experiment Step Size
*/
float hartstone_step_size(uint8_t experiment_num);

/*! \fn		void hartstone_test(uint8_t exp,uint8_t test,uint8_t additional,pdTASK_CODE pvTaskCode)
    \brief 	Creates the task set required for the specific test of a certain experiment
	\param	exp			Experiment Number
	\param	additional	Number of additional tasks added
	\param	pvTaskCode	Pointer to the tasks body to be created
*/
void hartstone_test(uint8_t exp,uint8_t test,uint8_t additional,pdTASK_CODE pvTaskCode);

/*! \fn		void hartstone_start(void)
    \brief  Launches the Benchamark
*/
void hartstone_start(void);

/*! \fn		void hartstone_error(uint8_t errorCode)
    \brief  Generates and sends the right error string starting from the error code
    \param	errorCode	Error code
*/
void hartstone_error(uint8_t errorCode);

#endif /* HARTSTONE_H */
