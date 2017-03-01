/* ###################################################################
**     Filename    : os_tasks.c
**     Project     : kl25z_pe
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-04, 22:00, # CodeGen: 2
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         Touch_task - void Touch_task(os_task_param_t task_init_data);
**
** ###################################################################*/
/*!
** @file os_tasks.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup os_tasks_module os_tasks module documentation
**  @{
*/         
/* MODULE os_tasks */

#include "Cpu.h"
#include "Events.h"
#include "rtos_main_task.h"
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "TsiMQX_Kl25z.h"
#include <stdint.h>
#include <stdio.h>

uint32_t serial0_queue[sizeof(LWMSGQ_STRUCT)/sizeof(uint32_t) + NUM_OF_MESSAGES * MSG_SIZE];


/*
** ===================================================================
**     Callback    : Touch_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Touch_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
	//uint32_t result teste 2;
	TSI_STATUS_T tsiHandler;
	uint8_t currentStateTouch, previusState;

	TsiMQXKl25z_Init(&tsiHandler);

	printf("calibrated: %d\r\n",(int)tsiHandler.avgUntouch);
  
#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */
	  currentStateTouch = TsiMQXKl25z_GetElectrodesStatus(&tsiHandler);
	  if(currentStateTouch == TOUCHED){
		  printf("Touched\r\n");
	  }
    _time_delay(100);
    
#ifdef PEX_USE_RTOS   
  }
#endif    
}

/*
** ===================================================================
**     Callback    : Task2_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task2_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
  
#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */
    
    
    OSA_TimeDelay(10);                 /* Example code (for task release) */
   
    
    
    
#ifdef PEX_USE_RTOS   
  }
#endif    
}

/*
** ===================================================================
**     Callback    : TaskGatekeeper_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void TaskGatekeeper_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
	_mqx_uint result, lwmsg[MSG_SIZE];

	result = _lwmsgq_init((void *) serial0_queue, NUM_OF_MESSAGES, MSG_SIZE);
	if (result != MQX_OK) {
		printf("lwmsg init failed\r\n");
	}
  
#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */
	  result = _lwmsgq_receive((void *)serial0_queue, lwmsg, LWMSGQ_RECEIVE_BLOCK_ON_EMPTY,0,0);
	  if(resul == MQX_OK){

	  }
    
    OSA_TimeDelay(10);                 /* Example code (for task release) */
   
    
    
    
#ifdef PEX_USE_RTOS   
  }
#endif    
}

/* END os_tasks */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
