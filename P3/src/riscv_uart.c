#include "riscv_uart.h"

struct UART_regs
{
	/** \brief UART  Data Register */
	volatile uint32_t Data;   	/* 0xFC001000 */
	/** \brief UART  Status Register */
	volatile uint32_t Status; 	/* 0xFC001004 */
	/** \brief UART  Control Register */
	volatile uint32_t Ctrl; 	/* 0xFC001008 */
	/** \brief UART  Scaler Register */
	volatile uint32_t Scaler; 	/* 0xFC00100C */
};

volatile struct UART_regs * const pUART_REGS = (struct UART_regs *) 0xFC001000;

//***************************
#define riscv_UART_TF_IS_FULL() ( pUART_REGS->Status & RISCV_UART_TF)

//***************************
int8_t riscv_putchar(char c)
{
	uint32_t write_timeout=0;

	while( (riscv_UART_TF_IS_FULL()) && (write_timeout < 0xAAAAA))
	{
		write_timeout++;
	}

	if(write_timeout < 0xAAAAA)
		pUART_REGS->Data = c;

	// return !0 (true) if write_timeout reach maximun value
	// 0 (false) otherwise
	return (write_timeout >= 0xAAAAA);
}


//***************************
int8_t riscv_uart_tx_fifo_is_empty()
{
   // Return 0 if TE Status bit is not set, !0 otherwise
   return ( pUART_REGS->Status & RISCV_UART_TE);
}

//***************************
void riscv_uart_enable_TX()
{
    // Set TE bit in Control register
    pUART_REGS->Ctrl |= RISCV_UART_TXE;
}

//***************************
void riscv_uart_disable_TX()
{
    pUART_REGS->Ctrl &= ~RISCV_UART_TXE;
}

uint8_t riscv_print_string (char * pchar)
{
	uint8_t error = 0;
	uint32_t i = 0;

	while(pchar[i] != '\0' && !error)
	{
		error = riscv_putchar(pchar[i]);
		i++;
	}

	while(!riscv_uart_tx_fifo_is_empty());

	return error;
}

void riscv_uart_enable_RX()
{
	pUART_REGS->Ctrl |= RISCV_UART_RXE;
}

void riscv_uart_disable_RX()
{
	pUART_REGS->Ctrl &= ~RISCV_UART_RXE;
}

int32_t riscv_getchar()
{
	int32_t uart_data = -1;

	if(pUART_REGS->Ctrl & RISCV_UART_DR)
		uart_data = pUART_REGS->Data;

	return uart_data;
}

void riscv_uart_enable_RI()
{
	pUART_REGS->Ctrl |= RISCV_UART_RI;
}

void riscv_uart_disable_RI()
{
	pUART_REGS->Ctrl &= ~RISCV_UART_RI;
}


