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
**         Task1_task - void Task1_task(os_task_param_t task_init_data);
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
#include <stdint.h>
#include <stdio.h>
/*
** ===================================================================
**     Callback    : Task1_task
**     Description : Task function entry.
**     Parameters  :
**       task_init_data - OS task parameter
**     Returns : Nothing
** ===================================================================
*/
void Task1_task(os_task_param_t task_init_data)
{
  /* Write your local variable definition here */
	//uint32_t result;
	tsi_status_t result;
	 uint8_t tsiChn[2], i,j;
	 uint16_t measureResult[2];
	 uint32_t sumUntouch=0;
	 uint32_t avgMeasure,avgUntouch = 0;

	 tsiChn[0] = 9;
	 tsiChn[1] = 10;


	// Enable electrodes for normal mode
	for (i = 0; i < 2; i++) {
		result = TSI_DRV_EnableElectrode(tsi1_IDX, tsiChn[i], true);
		if (result != kStatus_TSI_Success) {
			printf("\r\nThe initialization of TSI channel %d failed \r\n",
					tsiChn[i]);
		}
	}

	//measusure untouched
	result = TSI_DRV_MeasureBlocking(tsi1_IDX);
	if (result != kStatus_TSI_Success) {
		printf("\r\nThe measure of TSI failed. ");
	}else{
		printf("\r\nThe measure of TSI ok ");
	}

    // Measures average value in untouched mode.
    for(i = 0; i<100u; i++)
    {
        for(j = 0; j < 2; j++)
        {
            result = TSI_DRV_GetCounter(tsi1_IDX, tsiChn[j], &measureResult[j]);
            if(result != kStatus_TSI_Success)
            {
                printf("\r\nThe read of TSI channel %d failed.", tsiChn[j]);
            }
            // Calculates sum of average values.
            sumUntouch += measureResult[j];
        }
    }


    // Calculates average value afer 100 times measurement.
        avgUntouch = sumUntouch/(100 * 2);
  printf("calibrated %d\r\n",avgUntouch);
  
#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */
      result = TSI_DRV_MeasureBlocking(tsi1_IDX);
      if(result != kStatus_TSI_Success)
      {
          printf("\r\nThe measure of TSI failed.");
      }

      // Init average measurement.
      avgMeasure = 0;
      for(i = 0; i < 2; i++)
      {
          result = TSI_DRV_GetCounter(tsi1_IDX, tsiChn[i], &measureResult[i]);
          if(result != kStatus_TSI_Success)
          {
              printf("\r\nThe read of TSI channel %d failed.", tsiChn[i]);
          }
          avgMeasure += measureResult[i];
      }
      // Calculates average measurement.
      avgMeasure /=2;

      if(avgMeasure > avgUntouch + 10){
    	  printf("new measure %d\r\n",(int)avgMeasure);
      }

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
