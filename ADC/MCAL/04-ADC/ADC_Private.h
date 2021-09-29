/*
 * ADC_Private.h
 *
 *  Created on: Sep 28, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef MCAL_04_ADC_ADC_PRIVATE_H_
#define MCAL_04_ADC_ADC_PRIVATE_H_

/***			Registers Pointers		***/
#define ADMUX 		*((volatile u8 *)  0x27)
#define ADCSRA 		*((volatile u8 *)  0x26)
#define SFIOR 		*((volatile u8 *)  0x50)

#define ADCL 		*((volatile u8 *)  0x24)
#define ADCH 		*((volatile u8 *)  0x25)


/***			ADC Multiplexer Selection Register [ADMUX]		***/
// Analog Channel and Gain Selection Bits
#define MUX0_BIT	0
#define MUX1_BIT	1
#define MUX2_BIT	2
#define MUX3_BIT	3
#define MUX4_BIT	4
// ADC Left Adjust Result Bit
#define ADLAR_BIT 	5
// Reference Selection Bits
#define REFS0_BIT	6
#define REFS1_BIT	7
////////////////////////////////////////////////////////////////////

/***			ADC Control and status register [ADSCRA]		***/
// Prescaler Bits
#define ADPS0_BIT 	0
#define ADPS1_BIT 	1
#define ADPS2_BIT 	2
// ADC Interrupt Enable Bit
#define ADIE_BIT	3
// ADC Interrupt Flag Bit
#define ADIF_BIT 	4
// ADC Auto Trigger Enable Bit (For free running mode)
#define ADATE_BIT 	5
// ADC Start Conversion Bit
#define ADSC_BIT	6
// ADC Enable Bit
#define ADEN_BIT 	7
////////////////////////////////////////////////////////////////////


/***			Special FunctionIO Register [SFIOR]		***/
// ADC Auto Trigger Source
#define ADTS0		5
#define ADTS1		6
#define ADTS2		7
////////////////////////////////////////////////////////////



/***						ADC  Division Factors  						***/
#define 	ADC_u8Factor2		(1<<ADPS0_BIT | 0<<ADPS1_BIT | 0<<ADPS2_BIT)
#define 	ADC_u8Factor4		(0<<ADPS0_BIT | 1<<ADPS1_BIT | 0<<ADPS2_BIT)
#define 	ADC_u8Factor8		(1<<ADPS0_BIT | 1<<ADPS1_BIT | 0<<ADPS2_BIT)
#define 	ADC_u8Factor16		(0<<ADPS0_BIT | 0<<ADPS1_BIT | 1<<ADPS2_BIT)
#define 	ADC_u8Factor32		(1<<ADPS0_BIT | 0<<ADPS1_BIT | 1<<ADPS2_BIT)
#define 	ADC_u8Factor64		(0<<ADPS0_BIT | 1<<ADPS1_BIT | 1<<ADPS2_BIT)
#define 	ADC_u8Factor128		(1<<ADPS0_BIT | 1<<ADPS1_BIT | 1<<ADPS2_BIT)
////////////////////////////////////////////////////////////////////////////


/***	 ADC Voltage Reference Selection Modes  	 ***/
#define	ADC_u8External  ((1<<REFS0_BIT)|(0<<REFS1_BIT))
#define ADC_u8Internal  ((1<<REFS0_BIT)|(1<<REFS1_BIT))
#define ADC_u8AREF  	((0<<REFS0_BIT)|(0<<REFS1_BIT))
////////////////////////////////////////////////////////


#endif /* MCAL_04_ADC_ADC_PRIVATE_H_ */
