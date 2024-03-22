/*
 * gpio_drv.c
 *
 *  Created on: <creation date>
 *      Author: <student name>
 */

#include "riscv_types.h"
#include "gpio_drv.h"

volatile uint32_t *GPIO = (uint32_t *) 0xFC083000;

void gpio_set_direction( uint32_t direction )
{
	GPIO[DIRECTION] = direction;
}

uint32_t gpio_get_direction( void )
{
	return GPIO[DIRECTION];
}

void gpio_write( uint32_t output )
{
	GPIO[OUTPUT] = output;
}

uint32_t gpio_read( void )
{
    return GPIO[INPUT];
}




