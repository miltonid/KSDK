/*
 * TsiMQX_Kl25z.c
 *
 *  Created on: 16/02/2017
 *      Author: milton
 */



#include "rtos_main_task.h"
#include "os_tasks.h"
#include "TsiMQX_Kl25z.h"
#include <stdint.h>
#include <stdio.h>

/* ----------------- PRIVATE FUCTIONS  ----------------------------  */


/**
 * @brief	Read average value for TSI Channels
 * @param[in,out] tsiH pointer to tsi status handler
 * @param[in] Numbers of reads for calculate average of TSI channels
 * @return	Return average value or FALSE for error
 */
uint32_t readElectrodes(TSI_STATUS_PTR tsiH, uint8_t samples){
	uint8_t i, j;
	uint32_t sum = 0, avg = 0;
	uint32_t result;
	uint16_t measureResult[QTD_ELECTRODES];

	 // Measures average value of untouched state.
	result = TSI_DRV_MeasureBlocking(tsi1_IDX);
	if (result != kStatus_TSI_Success) {
		printf("\r\nThe measure of TSI failed. ");
		return FALSE;
	}

	for (i = 0; i < samples; i++) {
		for (j = 0; j < QTD_ELECTRODES; j++) {
			result = TSI_DRV_GetCounter(tsi1_IDX, tsiH->tsiChannel[j],
					&measureResult[j]);
			if (result != kStatus_TSI_Success) {
				printf("\r\nThe read of TSI channel %d failed.",
						tsiH->tsiChannel[j]);
				return FALSE;
			}
			// Calculates sum of average values.
			sum += measureResult[j];
		}
	}

	// Calculates average value afer samples measurement.
	avg = sum/(samples * QTD_ELECTRODES);
	return avg;
}
/* -------------------------------------------------------------------*/



/* ----------------- PUBLIC FUCTIONS  ----------------------------  */

/**
 * @brief	Initialization and calculates the untouched mode for TSI
 * @param[in,out] tsiH pointer to tsi status handler
 * @return	Return TRUE for success or false for error.
 */
bool TsiMQXKl25z_Init(TSI_STATUS_PTR tsiH){
	uint8_t i;
	uint32_t result;
	tsiH->tsiChannel[0] = CHANNEL_9;
	tsiH->tsiChannel[1] = CHANNEL_10;

	// Enable electrodes for normal mode
	for (i = 0; i < QTD_ELECTRODES; i++) {
		result = TSI_DRV_EnableElectrode(tsi1_IDX, tsiH->tsiChannel[i], true);
		if (result != kStatus_TSI_Success) {
			printf("\r\nThe initialization of TSI channel %d failed \r\n",
					tsiH->tsiChannel[i]);
			return FALSE;
		}
	}

	// Measures average value in untouched mode.
	tsiH->avgUntouch = readElectrodes(tsiH, SAMPLES_FOR_CALIBRATE);
	if(tsiH->avgUntouch == 0){
		return FALSE;
	}
	return TRUE;
}

/**
 * @brief	Initialization and calculates the untouched mode for TSI
 * @param[in,out] tsiH pointer to tsi status handler
 * @return	Return TOUCHED, UNTOUCHED or ERROR_TSI.
 */
uint8_t TsiMQXKl25z_GetElectrodesStatus(TSI_STATUS_PTR tsiH){
	if(tsiH->avgUntouch == 0) {
		return ERROR_TSI;
	}

	tsiH->avgMeasure = readElectrodes(tsiH, ONE_READ);

	if (tsiH->avgMeasure != ERROR_TSI) {
		if (tsiH->avgMeasure > tsiH->avgUntouch + THERESHOLD_FOR_TOUCH) {
			//printf("new measure %d\r\n", (int) tsiH->avgMeasure);
			return TOUCHED;
		}else{
			return UNTOUCHED;
		}
	}else{
		return ERROR_TSI;
	}

}


