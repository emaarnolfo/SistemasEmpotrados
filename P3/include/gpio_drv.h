/*
 * gpio_drv.h
 *
 *  Created on: <creation date>
 *      Author: <student name>
 */

#ifndef _GPIO_DRV_H_
#define _GPIO_DRV_H_

#define INPUT     0	// Input reg
#define OUTPUT    1	// Output reg
#define DIRECTION 2	// Direction

#define SW_0_MASK 0x00000001 // First  switch
#define SW_1_MASK 0x00000002 // Second switch
#define SW_2_MASK 0x00000004 // Third  switch
#define SW_3_MASK 0x00000008 // Fourth switch

#define BTN_0_MASK 0x00000010
#define BTN_1_MASK 0x00000020
#define BTN_2_MASK 0x00000040
#define BTN_3_MASK 0x00000080

#define LED_0_MASK 0x00010000 // First  led
#define LED_1_MASK 0x00020000 // Second led
#define LED_2_MASK 0x00040000 // Third  led
#define LED_3_MASK 0x00080000 // Fourth led

void gpio_set_direction( uint32_t direction );
uint32_t gpio_get_direction( void );

void gpio_write( uint32_t output );
uint32_t gpio_read();

#endif /* _GPIO_DRV_H_ */
