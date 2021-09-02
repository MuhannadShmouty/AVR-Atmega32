/*
 * main.c
 *
 *  Created on: Aug 28, 2021
 *      Author: Muhannad Shmouty
 */

#include "STD_TYPES.h"
#include "DIO_PRIVATE.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "SEV_SEG.h"
#include <util/delay.h>


#define green_led 0
#define yellow_led 1
#define red_led 2


void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {
	switch (Copy_u8Port) {
	case DIO_u8_PORTA:
		DDRA = Copy_u8Direction;
		break;
	case DIO_u8_PORTB:
		DDRB = Copy_u8Direction;
		break;
	case DIO_u8_PORTC:
		DDRC = Copy_u8Direction;
		break;
	case DIO_u8_PORTD:
		DDRD = Copy_u8Direction;
		break;
	}
}

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) {
	switch (Copy_u8Port) {
	case DIO_u8_PORTA:
		PORTA = Copy_u8Value;
		break;
	case DIO_u8_PORTB:
		PORTB = Copy_u8Value;
		break;
	case DIO_u8_PORTC:
		PORTC = Copy_u8Value;
		break;
	case DIO_u8_PORTD:
		PORTD = Copy_u8Value;
		break;
	}
}

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {
	switch (Copy_u8Port) {
	case DIO_u8_PORTA:
		switch (Copy_u8Direction) {
		case DIO_u8_INTPUT:
			clear_bit(DDRA, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRA, Copy_u8Pin);
			break;
		}
		break;

	case DIO_u8_PORTB:
		switch (Copy_u8Direction) {
		case DIO_u8_INTPUT:
			clear_bit(DDRB, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRB, Copy_u8Pin);
			break;
		}
		break;

	case DIO_u8_PORTC:
		switch (Copy_u8Direction) {
		case DIO_u8_INTPUT:
			clear_bit(DDRC, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRC, Copy_u8Pin);
			break;
		}
		break;

	case DIO_u8_PORTD:
		switch (Copy_u8Direction) {
		case DIO_u8_INTPUT:
			clear_bit(DDRD, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRD, Copy_u8Pin);
			break;
		}
		break;
	}
}

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {
	switch (Copy_u8Port) {
		case DIO_u8_PORTA:
			switch (Copy_u8Value) {
			case DIO_u8_LOW:
				clear_bit(PORTA, Copy_u8Pin);
				break;
			case DIO_u8_HIGH:
				set_bit(PORTA, Copy_u8Pin);
				break;
			}
			break;

		case DIO_u8_PORTB:
			switch (Copy_u8Value) {
			case DIO_u8_LOW:
				clear_bit(PORTB, Copy_u8Pin);
				break;
			case DIO_u8_HIGH:
				set_bit(PORTB, Copy_u8Pin);
				break;
			}
			break;

		case DIO_u8_PORTC:
			switch (Copy_u8Value) {
			case DIO_u8_LOW:
				clear_bit(PORTC, Copy_u8Pin);
				break;
			case DIO_u8_HIGH:
				set_bit(PORTC, Copy_u8Pin);
				break;
			}
			break;

		case DIO_u8_PORTD:
			switch (Copy_u8Value) {
			case DIO_u8_LOW:
				clear_bit(PORTD, Copy_u8Pin);
				break;
			case DIO_u8_HIGH:
				set_bit(PORTD, Copy_u8Pin);
				break;
			}
			break;
		}
}

u8 DIO_u8ReadPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin){
	u8 LOC_u8_pinState = 0;
	switch (Copy_u8Port) {
		case DIO_u8_PORTA:
			LOC_u8_pinState = 3;//get_bit(PINA, Copy_u8Pin);
			break;
		case DIO_u8_PORTB:
			LOC_u8_pinState = get_bit(PINB, Copy_u8Pin);
			break;
		case DIO_u8_PORTC:
			LOC_u8_pinState = get_bit(PINC, Copy_u8Pin);
			break;
		case DIO_u8_PORTD:
			LOC_u8_pinState = get_bit(PIND, Copy_u8Pin);
			break;
		}
	return LOC_u8_pinState;
}


void DIO_voidActivatePullup(u8 Copy_u8Port ,u8 Copy_u8Pin){
	switch (Copy_u8Port) {
			case DIO_u8_PORTA:
				clear_bit(DDRA, Copy_u8Pin);
				set_bit(PORTA, Copy_u8Pin);
				break;
			case DIO_u8_PORTB:
				clear_bit(DDRB, Copy_u8Pin);
				set_bit(PORTB, Copy_u8Pin);
				break;
			case DIO_u8_PORTC:
				clear_bit(DDRC, Copy_u8Pin);
				set_bit(PORTC, Copy_u8Pin);
				break;
			case DIO_u8_PORTD:
				clear_bit(DDRD, Copy_u8Pin);
				set_bit(PORTD, Copy_u8Pin);
				break;
			}
}



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
