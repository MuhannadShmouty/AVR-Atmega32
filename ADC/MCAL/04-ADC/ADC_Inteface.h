/*
 * ADC_Inteface.h
 *
 *  Created on: Sep 28, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef MCAL_04_ADC_ADC_INTEFACE_H_
#define MCAL_04_ADC_ADC_INTEFACE_H_

void ADC_voidInit(void);
void ADC_voidEnable(void);
void ADC_voidDisable(void);
u16  ADC_u16GetChannelResult(u8 Copy_u8ADC_Channel);



#endif /* MCAL_04_ADC_ADC_INTEFACE_H_ */
