/*
 * Servo.c
 *
 *  Created on: 08/04/2017
 *      Author: milton
 */

#include "Cpu.h"
#include "Events.h"
#include "os_tasks.h"
#include "Servo.h"
//#include "fsl_tpm_driver.h"
//#include "fsl_clock_manager.h"


///*******************************************************************************
// * Variables
// ******************************************************************************/

/**
 * @brief	Init the servo
 * @param[servoPtr] Pointer to the struct servo handler
 * @param[minPulseWidth_us] minimal duty cycle
 * @param[maxPulseWidth_us] maximal duty cycle
 * @return	void
 */
void SERVO_Init(SERVO_HANDLER_PTR servoPtr, uint16_t minPulseWidth_us, uint16_t maxPulseWidth_us){
	float servoCycle;

	assert(servoPtr->instance < TPM_INSTANCE_COUNT);
	assert(servoPtr->channel < g_tpmChannelCount[servoPtr->instance]);

	servoPtr->freq = TPM_DRV_GetClock(servoPtr->instance);
	servoPtr->uMod = servoPtr->freq / servoPtr->param->uFrequencyHZ - 1;
	servoPtr->min_uCnv = (minPulseWidth_us * servoPtr->uMod) / 20000;
	servoPtr->max_uCnv = (maxPulseWidth_us * servoPtr->uMod) / 20000;
	servoCycle = (float) (servoPtr->max_uCnv - servoPtr->min_uCnv);
	servoPtr->stepVal = (uint16_t) (servoCycle / 180);
}


/**
 * @brief	Set the position of the servo
 * @param[servoPtr] Pointer to the struct servo handler
 * @param[angle] 0 to 180 degree
 * @return	tpm_status_t
 */
tpm_status_t SERVO_Write(SERVO_HANDLER_PTR servoPtr, uint8_t angle)
{
    uint16_t uMod, uCnv;

    assert(servoPtr->instance < TPM_INSTANCE_COUNT);
    assert(angle <= 180);
    assert(servoPtr->channel < g_tpmChannelCount[servoPtr->instance]);

    TPM_Type *tpmBase = g_tpmBase[servoPtr->instance];

    /* When settings mode, disable channel first  */
   // TPM_HAL_DisableChn(tpmBase, channel);
    if(servoPtr == NULL){
    	return kStatusTpmFail;
    }

    if(servoPtr->param->mode == kTpmEdgeAlignedPWM){
    	uMod = servoPtr->uMod;
    	uCnv = servoPtr->min_uCnv + (angle * servoPtr->stepVal);
		if (uCnv >= uMod) {
			uCnv = uMod + 1;
		}
		TPM_HAL_SetMod(tpmBase, uMod);
		TPM_HAL_SetChnCountVal(tpmBase, servoPtr->channel, uCnv);
    }

    return kStatusTpmSuccess;
}



