/* ###################################################################
**     Filename    : os_tasks.c
**     Project     : FRDM-KL25Z_ESP8266
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-03-31, 00:52, # CodeGen: 2
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
#include "os_tasks.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Servo.h"
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
	uint8_t ang;
	SERVO_HANDLER_T servo1;

	servo1.instance = tpmTmr1_IDX;
	servo1.channel = 0;
	servo1.param = &tpmTmr1_ChnConfig0;

	SERVO_Init( &servo1, 500, 2500);

	GPIO_DRV_WritePinOutput(RST_ESP, 0);
	GPIO_DRV_WritePinOutput(CHPD_ESP, 1);
	UART_DRV_SendDataBlocking(uartCom1_IDX,(const uint8_t *)"AT\n\r", sizeof("AT\n\r"), 0);

	ang= 0;

#ifdef PEX_USE_RTOS
  while (1) {
#endif
    /* Write your code here ... */
    
	SERVO_Write(&servo1,ang);
    _time_delay(200);
    ang++;
    if(ang >= 180){
    	ang = 0;
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
