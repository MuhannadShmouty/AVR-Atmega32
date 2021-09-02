/*
 * CLCD_config.h
 *
 *  Created on: Aug 30, 2021
 *      Author: Muhannad Shmouty
 */

#ifndef HAL_CLCD_CLCD_CONFIG_H_
#define HAL_CLCD_CLCD_CONFIG_H_


/*
 * CLCD_DATA_PORT Options
 *
 * - DIO_u8_PORTA
 * - DIO_u8_PORTB
 * - DIO_u8_PORTC
 * - DIO_u8_PORTD
 */

#define CLCD_DATA_PORT	 DIO_u8_PORTA

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

#define CLCD_RS_PIN		DIO_u8_PIN_00
#define CLCD_EN_PIN		DIO_u8_PIN_01



#endif /* HAL_CLCD_CLCD_CONFIG_H_ */
