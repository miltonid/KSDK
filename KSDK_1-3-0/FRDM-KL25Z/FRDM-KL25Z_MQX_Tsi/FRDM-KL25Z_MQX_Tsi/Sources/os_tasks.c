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
	//uint32_t result;
	TSI_STATUS_T tsiHandler;

	TsiMQXKl25z_Init(&tsiHandler);

	printf("calibrated: %d\r\n",(int)tsiHandler.avgUntouch);
  
#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */
	  TsiMQXKl25z_GetElectrodesStatus(&tsiHandler);
    _time_delay(100);
    
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
