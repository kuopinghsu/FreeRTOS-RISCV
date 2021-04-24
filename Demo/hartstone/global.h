#ifndef GLOBAL_H
#define GLOBAL_H

#include "FreeRTOS.h"
#include "task.h"
#include "whetstone.h"
#include "periodic_task.h"

/*! \def	RAW_TEST
    \brief	Computes the RawSpeed
*/
#define RAW_TEST

/*! \def	EXP_1
    \brief	Executes Experiment 1
*/
#define EXP_1

/*! \def	EXP_2
    \brief	Executes Experiment 2
*/
#define EXP_2

/*! \def	EXP_3
    \brief	Executes Experiment 3
*/
//#define EXP_3

/*! \def	EXP_4
    \brief	Executes Experiment 4
*/
#define EXP_4

/*! \def	GUI_OUTPUT
    \brief	Produces Output Format for the GUI Application
*/
//#define GUI_OUTPUT

/*! \def	N_TASK
    \brief	Number of tasks
*/
#define N_TASK					5

/*! \def	MAX_ADDITIONAL_TASKS
    \brief	Number of additional tasks to handle EXPERIMENT_4
*/
#define MAX_ADDITIONAL_TASKS	5

/*! \def	TEST_LEN
    \brief	Duration of each test
*/
#define TEST_LEN 				3000

/*! \def	TASK_MAN_STACK_SIZE
    \brief	Management Task Stack Depth
*/
#define TASK_MAN_STACK_SIZE		300

/*! \def	TASK_GEN_STACK_SIZE
    \brief	Generic Task Stack Depth
*/
#define TASK_GEN_STACK_SIZE		100

/*! \def	RAW_SINGLE_LOAD
    \brief	Parameter to generate the Raw Speed Computation
*/
#define RAW_SINGLE_LOAD 		10

/*! \def	BASELINE_FREQUENCY_0
    \brief	Frequency of the lowest priority task in the Baseline Task-Set, expressed in Hz
*/
#define BASELINE_FREQUENCY_0	60

/*! \def	BASELINE_PERIOD_0
    \brief	Period of the lowest priority task in the Baseline Task-Set, expressed in ms
*/
#define BASELINE_PERIOD_0 		500

/*! \def	BASELINE_PRIORITY_0
    \brief	Priority of the lowest priority task in the Baseline Task-Set
*/
#define BASELINE_PRIORITY_0 	2

/*! \def	BASELINE_LOAD_0
    \brief	Load of the lowest priority task in the Baseline Task-Set
*/
#define BASELINE_LOAD_0			256

/*! \def	WORKLOAD_STEP
    \brief	Amount of KWIPS added for each Experiment 3 Test.
*/
#define WORKLOAD_STEP			2

/*!
 * \var 	portTickType deadline_miss
 * \brief 	 Number of Missed Deadlines ordered by task index
 */
extern portTickType deadline_miss[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		portTickType deadline_met
 * \brief	Number of Met Deadlines ordered by task index
 */
extern portTickType deadline_met[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		float frequency
 * \brief	Task Frequencies ordered by task_index
 */
extern float frequency[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		portTickType period
 * \brief	Task Periods ordered by task_index
 */
extern portTickType period[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		portTickType priority
 * \brief	Task Priorities ordered by task_index
 */
extern portTickType priority[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		int load
 * \brief	Task Loads ordered by task_index
 */
extern int load[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		int load_exp3
 * \brief	Task Loads of the Experiment 3 ordered by task_index
 */
extern int load_exp3[N_TASK];//to handle variable load of EXPERIMENT_3

/*!
 * \var		uint8_t task_index
 * \brief	Task Indexes
 */
extern uint8_t task_index[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		uint16_t raw_speed
 * \brief	Raw Speed of the specific architecture
 */
extern uint16_t raw_speed;

/*!
 * \var		xTaskHandle taskHandle
 * \brief	Task Handles ordered by task index
 */
extern xTaskHandle taskHandle[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		portTickType start
 * \brief	Start Tick Time initialized for each experiment
 */
extern portTickType start;

#endif /* GLOBAL_H */
