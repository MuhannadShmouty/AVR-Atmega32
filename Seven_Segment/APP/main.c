/*
 * main.c
 *
 *  Created on: Aug 28, 2021
 *      Author: Muhannad Shmouty
 */

#include "../Services/STD_TYPES.h"
#include "../MCAL/DIO_PRIVATE.h"
#include "../Services/BIT_MATH.h"
#include "../MCAL/DIO_INTERFACE.h"
#include "../HAL/SEV_SEG_interface.h"
#include <util/delay.h>


#define green_led 0
#define yellow_led 1
#define red_led 2



int main(void) {
	// Set pins to output
	DIO_voidSetPortDirection(DIO_u8_PORTA, DIO_u8_PORT_OUTPUT);
	DIO_voidSetPortDirection(DIO_u8_PORTB, DIO_u8_PORT_OUTPUT);
	DIO_voidSetPortDirection(DIO_u8_PORTD, DIO_u8_PORT_OUTPUT);


	DIO_voidSetPortValue(DIO_u8_PORTB, DIO_u8_LOW);

	u8 green_timer = 60;
	u8 yellow_timer = 10;
	u8 red_timer = 60;


	while (1) {

		// Turn green lights on
		DIO_voidSetPinValue(DIO_u8_PORTB, green_led, DIO_u8_HIGH);
		// start timer
		for (int i = 0; i < green_timer; i++)
		{
			//wait
			DIO_voidSetPortValue(DIO_u8_PORTD, digits[(green_timer-i) % 10]);
			DIO_voidSetPortValue(DIO_u8_PORTA, digits[((green_timer-i) / 10) % 10]);
			_delay_ms(150);
		}
		DIO_voidSetPinValue(DIO_u8_PORTB, green_led, DIO_u8_LOW); // Turn green lights off


		// Turn yellow lights on
		DIO_voidSetPinValue(DIO_u8_PORTB, yellow_led, DIO_u8_HIGH);
			// start timer
			for (int i = 0; i < yellow_timer; i++)
			{
				//wait
				DIO_voidSetPortValue(DIO_u8_PORTD, digits[(yellow_timer-i) % 10]);
				DIO_voidSetPortValue(DIO_u8_PORTA, digits[((yellow_timer-i) / 10) % 10]);
				_delay_ms(150);
			}
		DIO_voidSetPinValue(DIO_u8_PORTB, yellow_led, DIO_u8_LOW);


		// Turn red lights on
		DIO_voidSetPinValue(DIO_u8_PORTB, red_led, DIO_u8_HIGH);
			// start timer
			for (int i = 0; i < red_timer; i++)
			{
				//wait
				DIO_voidSetPortValue(DIO_u8_PORTD, digits[(red_timer-i) % 10]);
				DIO_voidSetPortValue(DIO_u8_PORTA, digits[((red_timer-i) / 10) % 10]);
				_delay_ms(150);
			}
		DIO_voidSetPinValue(DIO_u8_PORTB, red_led, DIO_u8_LOW);
	}

}
