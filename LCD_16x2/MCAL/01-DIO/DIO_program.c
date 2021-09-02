/*
 * DIO_program.c
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */


#include "../../Services/STD_TYPES.h"
#include "DIO_PRIVATE.h"
#include "../../Services/BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include <util/delay.h>



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
		case DIO_u8_INPUT:
			clear_bit(DDRA, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRA, Copy_u8Pin);
			break;
		}
		break;

	case DIO_u8_PORTB:
		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			clear_bit(DDRB, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRB, Copy_u8Pin);
			break;
		}
		break;

	case DIO_u8_PORTC:
		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			clear_bit(DDRC, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			set_bit(DDRC, Copy_u8Pin);
			break;
		}
		break;

	case DIO_u8_PORTD:
		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
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
