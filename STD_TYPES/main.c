/*
 * main.c
 *
 *  Created on: Aug 25, 2021
 *      Author: Muhannad Shmouty
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#define DDRB  *((u8 *) (0x37))
#define PORTB *((u8 *) (0x38))

int main()
{
	DDRB = 0xFF;  //--> 0b11111111  --> 255
	while(1)
	{
		for (u8 i = 0; i < 8; i++)
		{
			set_bit(PORTB,i);
			_delay_ms(250);
		}
		for (int i = 7; i >= 0; i--)
		{
			clear_bit(PORTB,i);
			_delay_ms(250);
		}

		for (int i = 0; i < 8; i++)
		{
			set_bit(PORTB,i);
			_delay_ms(250);
			clear_bit(PORTB,i);
		}

		for (int i = 6; i >= 0; i--)
		{
			set_bit(PORTB,i);
			_delay_ms(250);
			clear_bit(PORTB,i);
		}
		_delay_ms(250);
	}
	return 0;
}
