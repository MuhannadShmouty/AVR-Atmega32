/*
 * GIE_program.c
 *
*  Created on: Sep 12, 2021
 *      Author: Muhannad Shmouty
 */

#include "../../Services/BIT_MATH.h"
#include "../../Services/STD_TYPES.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"


void GIE_voidEnable(void){
	set_bit(SREG_REG , GIE_BIT);
}

void GIE_voidDisable(void){
	clear_bit(SREG_REG , GIE_BIT);
}

