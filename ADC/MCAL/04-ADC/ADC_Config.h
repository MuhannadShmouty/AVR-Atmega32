/*
 * ADC_Config.h
 *
 *  Created on: Sep 28, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef MCAL_04_ADC_ADC_CONFIG_H_
#define MCAL_04_ADC_ADC_CONFIG_H_

/*
 * Voltage Reference Selections for ADC
 * Options:
 * 		ADC_u8External
 * 		ADC_u8Internal
 * 		ADC_u8AREF
 */
#define ADC_RefV  			ADC_u8External

/*
 * ADC Prescaler Select
 * Options:
 * 		ADC_u8Factor2
 * 		ADC_u8Factor4
 * 		ADC_u8Factor8
 * 		ADC_u8Factor16
 * 		ADC_u8Factor32
 * 		ADC_u8Factor64
 * 		ADC_u8Factor128
 */
#define ADC_u8Prescaler 	ADC_u8Factor128

#endif /* MCAL_04_ADC_ADC_CONFIG_H_ */
