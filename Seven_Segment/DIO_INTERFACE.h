/*
 * DIO_INTERFACE.h
 *
 *  Created on: Aug 28, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

#define DIO_u8_PORT_OUTPUT 0xFF
#define DIO_u8_INTPUT 0
#define DIO_u8_OUTPUT 1

#define DIO_u8_LOW 0
#define DIO_u8_HIGH 1

#define DIO_u8_PIN_0 0
#define DIO_u8_PIN_1 1
#define DIO_u8_PIN_2 2
#define DIO_u8_PIN_3 3
#define DIO_u8_PIN_4 4
#define DIO_u8_PIN_5 5
#define DIO_u8_PIN_6 6
#define DIO_u8_PIN_7 7

void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 DIO_u8ReadPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin);
void DIO_voidActivatePullup(u8 Copy_u8Port ,u8 Copy_u8Pin);

#endif /* DIO_INTERFACE_H_ */
