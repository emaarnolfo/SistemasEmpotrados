#include "riscv_types.h"
#include "riscv_uart.h"
#include "dispatch.h"
#include "log.h"

//--- Definicioes para las interrupciones
#define ESC 27

char car;
volatile uint32_t flag = 0;
uint32_t end  = 0;

// UART ISR handler
// It is going to be called each time a new car is received
void uart_rx_irq_handler (void)
{
   car = (char)riscv_getchar();
   flag = 1;
}
//---------------------------------------

int main()
{
	// TX/RX enable
	riscv_uart_enable_TX();
	riscv_uart_enable_RX();

	// Install uart handler
	install_irq_handler( UART_IRQ, uart_rx_irq_handler );

	riscv_uart_enable_RI();       // Enable RX irq
	plic_irq_unmask( UART_IRQ );  // PLIC UART irq unmask
	enable_ext_irq();    	      // Enable MIE.MEI
	enable_irq();	              // Global interrupt enable

	riscv_print_string("Embedded Systems\n");

	while( !end )
	{
		if ( flag )
		{
			printf("%d: ", car);
			if ( car == ESC ) // ESC
			{
 			    end = 1;
			}
			else
			{
 			    printf("%c\n", car);
 			    riscv_putchar(car);
 			    flag = 0;
			}
		}
		// else do nothing
	}

	printf("Program end\n");
	return 0;
}
