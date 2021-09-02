/*
 * SEV_SEG_program.c
 *
 *  Created on: Sep 2, 2021
 *      Author: Muhannad Shmouty
 */

#include "../Services/STD_TYPES.h"
#include "../MCAL/DIO_PRIVATE.h"
#include "../Services/BIT_MATH.h"
#include "../MCAL/DIO_INTERFACE.h"

#include "SEV_SEG_config.h"
#include "SEV_SEG_interface.h"
#include "SEV_SEG_private.h"


u8 digits[11] = {
//  a  b  c  d  e  f  g  .
  0b11111100,  // 0
  0b01100000,  // 1
  0b11011010,  // 2
  0b11110010,  // 3
  0b01100110,  // 4
  0b10110110,  // 5
  0b10111110,  // 6
  0b11100000,  // 7
  0b11111110,  // 8
  0b11110110,  // 9
  0b00000001   // .
};
