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
	TSI_STATUS_T tsiHandler; /**< Handler for TSI Readings */
	_mqx_uint result, lwmsg[MSG_SIZE]; /**< Variables for lwmsg queue */
	uint8_t currentStateTouch, previusState;
	uint8_t msgType = MSG_TOUCH_TYPE;

	previusState = ERROR_TSI;
	TsiMQXKl25z_Init(&tsiHandler);

	printf("calibrated: %d\r\n",(int)tsiHandler.avgUntouch);
  
#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */

	  /**< Get the status of TSI electrodes */
	  currentStateTouch = TsiMQXKl25z_GetElectrodesStatus(&tsiHandler);

	  if(currentStateTouch != ERROR_TSI && currentStateTouch != previusState){
		  lwmsg[0] = 0; /**< Variables for lwmsg queue */
		  /**< Prepare the data for send */
		  lwmsg[0] |= (0x000000FF & msgType<<0);
		  lwmsg[0] |= (0x0000FF00 & (uint8_t)currentStateTouch<<8);
		  /**< Puts the msg into the queue */
		  result = _lwmsgq_send((void *)serial0_queue, lwmsg, LWMSGQ_SEND_BLOCK_ON_FULL);
		  if(result != MQX_OK){
			  printf("Error lwmsg in task touch\r\n");
		  }
		  previusState = currentStateTouch;  /**< Saves the new value */
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
	_mqx_uint result, lwmsg[MSG_SIZE];
	uint8_t msgType = MSG_TASK2_TYPE;
	uint16_t counter = 0;

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */
    _time_delay(100);
    counter++;
    /**< Prepare the data for send */
	lwmsg[0] = 0;
	lwmsg[0] |= (0x000000FF & msgType  <<  0); /* Saves msgType into byte0 */
	lwmsg[0] |= 0x00FFFF00 & (uint32_t)counter  <<  8; /* Saves counter into byte1 and byte2 */
	result = _lwmsgq_send((void *) serial0_queue, lwmsg,LWMSGQ_SEND_BLOCK_ON_FULL); /**< Puts the msg into the queue */
	if (result != MQX_OK) {
		printf("Error lwmsg in task2\r\n");
	}
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
	uint8_t touchStatus, msgType;
	uint16_t counterTask2;
  
#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */
	  result = _lwmsgq_receive((void *)serial0_queue, lwmsg, LWMSGQ_RECEIVE_BLOCK_ON_EMPTY,0,0);
	  if(result == MQX_OK){
		  msgType = (lwmsg[0] & 0x000000FF);

		  switch(msgType){

		  case MSG_TOUCH_TYPE:
			  touchStatus = ((lwmsg[0] & 0x0000FF00) >> 8);
			  if(touchStatus == TOUCHED){
				  printf("Touched\r\n");
				  GPIO_DRV_WritePinOutput(LEDRGB_BLUE, 0);
			  }else if(touchStatus == UNTOUCHED){
				  printf("Not Touched\r\n");
				  GPIO_DRV_WritePinOutput(LEDRGB_BLUE, 1);
			  }
			  break;

		  case MSG_TASK2_TYPE:
			  counterTask2 = (lwmsg[0] & 0x00FFFF00) >> 8;
			  /*Only prints counter if touch is untouched */
			  if(touchStatus == UNTOUCHED){
				  printf("Counter task2: %d\r\n", counterTask2);
			  }
			  counterTask2 = 0;
			  break;

		  default:
			  break;

		  }//end switch
	  }
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
