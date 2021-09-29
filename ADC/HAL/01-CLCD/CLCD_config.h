/*
 * CLCD_config.h
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef HAL_01_CLCD_CLCD_CONFIG_H_
#define HAL_01_CLCD_CLCD_CONFIG_H_


/*
 * CLCD_DATA_PORT Options
 *
 * - DIO_u8_PORTA
 * - DIO_u8_PORTB
 * - DIO_u8_PORTC
 * - DIO_u8_PORTD
 */

#define CLCD_DATA_PORT	 DIO_u8_PORTD

/*
 * CLCD_CONTROL_PORT Options
 *
 * - DIO_u8_PORTA
 * - DIO_u8_PORTB
 * - DIO_u8_PORTC
 * - DIO_u8_PORTD
 */

#define CLCD_CONTROL_PORT	 DIO_u8_PORTB


/*
 * CLCD_RS_PIN, CLCD_EN_PIN	 Options
 *
 * - DIO_u8_PIN_00
 * - DIO_u8_PIN_01
 * - DIO_u8_PIN_02
 * - DIO_u8_PIN_03
 * - DIO_u8_PIN_04
 * - DIO_u8_PIN_05
 * - DIO_u8_PIN_06
 * - DIO_u8_PIN_07
 */

#define CLCD_RS_PIN		DIO_u8_PIN_B0
#define CLCD_EN_PIN		DIO_u8_PIN_B1

static u8 LOC_u8StaticArray[] = {
  0x00,0x00,0x00,0x00,0x1F,0x05,0x05,0x07,
  0x00,0x0E,0x0A,0x0A,0x1F,0x0A,0x0A,0x0E,
  0x00,0x0A,0x02,0x02,0x1F,0x00,0x00,0x00,
  0x00,0x02,0x02,0x02,0x1F,0x00,0x00,0x00,
  0x00,0x02,0x02,0x02,0x1F,0x00,0x00,0x00,
  0x00,0x02,0x02,0x02,0x1F,0x00,0x00,0x00,
  0x00,0x02,0x02,0x02,0x1F,0x00,0x00,0x00,
  0x00,0x02,0x02,0x02,0x1F,0x00,0x00,0x00
};



/* CLCD_u8_INTERFACE_DATA_LENGTH -> options:
 * 1- CLCD_u8_4_DATA_LENGTH
 * 2- CLCD_u8_8_DATA_LENGTH
 */
#define CLCD_u8_INTERFACE_DATA_LENGTH 		CLCD_u8_8_DATA_LENGTH

#endif /* HAL_01_CLCD_CLCD_CONFIG_H_ */
