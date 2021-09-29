/*
 * ADC_Program.c
 *
 *  Created on: Sep 28, 2021
 *      Author: Muhannad Shmouty
 */


#include "../../Services/BIT_MATH.h"
#include "../../Services/STD_TYPES.h"

#include "ADC_Config.h"
#include "ADC_Inteface.h"
#include "ADC_Private.h"

void ADC_voidInit(void){
	// AVCC with external capacitor at AREF pin
	ADMUX |= ADC_RefV;

	// Setting the prescaler bits to obtain 128 division factor
	ADCSRA |= ADC_u8Prescaler;

	// Enable ADC
	ADC_voidEnable();
}

void ADC_voidEnable(void){
	// Writing this bit to one enables the ADC
	set_bit(ADCSRA, ADEN_BIT);
}

void ADC_voidDisable(void){
	// By writing it to zero, the ADC is turned off.
	// Turning the ADC off while a conversion is in progress, will terminate this conversion.
	clear_bit(ADCSRA, ADEN_BIT);
}


u16  ADC_u16GetChannelResult(u8 Copy_u8ADC_Channel){

	u16 ADC_Reading;

	// Selecting channel
	ADMUX = (ADMUX & 0xE0) | Copy_u8ADC_Channel;
	ADC_Reading = ADCL | (ADCH << 8);


	// Start conversion
	set_bit(ADCSRA, ADSC_BIT);

	// Wait until conversion is completed
	while(!get_bit(ADCSRA, ADIF_BIT));

	// Clear ADC Flag
	set_bit(ADCSRA, ADIF_BIT);

	// return value
	return ADC_Reading;
}
