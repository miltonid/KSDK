/* ###################################################################
**     Filename    : Events.h
**     Project     : kl25z_pe
**     Processor   : MKL25Z128VLK4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-11-04, 21:55, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.h
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "fsl_device_registers.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "mqx_ksdk.h"
#include "uart1.h"
#include "fsl_hwtimer1.h"
#include "MainTask.h"
#include "TaskTouch.h"
#include "tsi1.h"
#include "TaskGatekeeper.h"
#include "Task2.h"

#ifdef __cplusplus
extern "C" {
#endif 


/*
** ===================================================================
**     Callback    : uart1_TxCallback
**     Description : This callback occurs when data are transmitted.
**     Parameters  :
**       instance - The LPSCI instance number.
**       lpsciState - A pointer to the LPSCI driver state structure
**       memory.
**     Returns : Nothing
** ===================================================================
*/
void uart1_TxCallback(uint32_t instance, void * lpsciState);

/*
** ===================================================================
**     Callback    : tsi1_Callback0
**     Description : Callback function is called when measurement is
**     done.
**     Parameters  :
**       instance - Peripheral device instance number.
**       userData - Pointer to registered user data.
**     Returns : Nothing
** ===================================================================
*/
void tsi1_Callback0(uint32_t instance,void *userData);

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

#endif 
/* ifndef __Events_H*/
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
