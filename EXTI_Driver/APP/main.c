/*
 * main.c
 *
*  Created on: Sep 12, 2021
 *      Author: Muhannad Shmouty
 */


#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATH.h"
#include "../MCAL/01-DIO/DIO_interface.h"


#include "../MCAL/02-GIE/GIE_interface.h"
#include "../MCAL/03-EXTI/EXTI_interface.h"

#include <util/delay.h>

void TOG_LED_ISR(void);
void TOG_LED_ISR_1(void);

int main(void){
	DIO_voidSetPinDirection(DIO_u8_PORTA , DIO_u8_PIN_00 , DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTA , DIO_u8_PIN_07 , DIO_u8_OUTPUT);
	DIO_voidActivePullUp(DIO_u8_PORTD , DIO_u8_PIN_02);
	DIO_voidActivePullUp(DIO_u8_PORTD , DIO_u8_PIN_03);


	EXTI_voidCallBack(TOG_LED_ISR , EXTI_u8_LINE0);
	EXTI_voidCallBack(TOG_LED_ISR_1 , EXTI_u8_LINE1);
	EXTI_voidInit();
	GIE_voidEnable();
	EXTI_voidEnable(EXTI_u8_LINE0, EXTI_u8_ON_CHANGE);
	EXTI_voidEnable(EXTI_u8_LINE1, EXTI_u8_ON_CHANGE);
	while(1){
		_delay_ms(500);
	}
}


void TOG_LED_ISR(void){
	DIO_voidTogglePin(DIO_u8_PORTA , DIO_u8_PIN_07);
}

void TOG_LED_ISR_1(void){
	DIO_voidTogglePin(DIO_u8_PORTA , DIO_u8_PIN_00);
}
