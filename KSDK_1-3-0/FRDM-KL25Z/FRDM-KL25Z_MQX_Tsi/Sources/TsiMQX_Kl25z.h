/*
 * TsiMQX_Kl25z.h
 *
 *  Created on: 16/02/2017
 *      Author: milton
 */

#ifndef SOURCES_TSIMQX_KL25Z_H_
#define SOURCES_TSIMQX_KL25Z_H_

#define QTD_ELECTRODES 	2
#define CHANNEL_9 		9
#define CHANNEL_10 		10
#define SAMPLES_FOR_CALIBRATE 		100u
#define ONE_READ 1
#define THERESHOLD_FOR_TOUCH 10

#define TOUCHED 1
#define UNTOUCHED 2
#define ERROR_TSI 0


/**
 * @brief This struct has the settings for TSI module.
 *
 * Channel IDs and average in untouched mode
 */
typedef struct{
	uint8_t tsiChannel[QTD_ELECTRODES]; /**<  Handler for each TSI channel */
	uint32_t avgMeasure; /**<  Average of the last tsi measure  */
	uint32_t avgUntouch; /**< Average in untouched mode*/
}TSI_STATUS_T, *TSI_STATUS_PTR;


/**
 * @brief	Initialization and calculates the untouched mode for TSI
 * @param[in,out] tsiH pointer to tsi status handler
 * @return	Return TRUE for success or false for error.
 */
bool TsiMQXKl25z_Init(TSI_STATUS_PTR tsiH);


/**
 * @brief	Initialization and calculates the untouched mode for TSI
 * @param[in,out] tsiH pointer to tsi status handler
 * @return	Return TOUCHED, UNTOUCHED or ERROR_TSI.
 */
uint8_t TsiMQXKl25z_GetElectrodesStatus(TSI_STATUS_PTR tsiH);

#endif /* SOURCES_TSIMQX_KL25Z_H_ */
