#include "global.h"


/*!
 * \var 	portTickType deadline_miss
 * \brief 	 Number of Missed Deadlines ordered by task index
 */
portTickType deadline_miss[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		portTickType deadline_met
 * \brief	Number of Met Deadlines ordered by task index
 */
portTickType deadline_met[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		float frequency
 * \brief	Task Frequencies ordered by task_index
 */
float frequency[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		portTickType period
 * \brief	Task Periods ordered by task_index
 */
portTickType period[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		portTickType priority
 * \brief	Task Priorities ordered by task_index
 */
portTickType priority[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		int load
 * \brief	Task Loads ordered by task_index
 */
int load[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		int load_exp3
 * \brief	Task Loads of the Experiment 3 ordered by task_index
 */
int load_exp3[N_TASK];//to handle variable load of EXPERIMENT_3

/*!
 * \var		uint8_t task_index
 * \brief	Task Indexes
 */
uint8_t task_index[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		uint32_t raw_speed
 * \brief	Raw Speed of the specific architecture
 */
uint16_t raw_speed;

/*!
 * \var		xTaskHandle taskHandle
 * \brief	Task Handles ordered by task index
 */
xTaskHandle taskHandle[N_TASK + MAX_ADDITIONAL_TASKS];

/*!
 * \var		portTickType start
 * \brief	Start Tick Time initialized for each experiment
 */
portTickType start;