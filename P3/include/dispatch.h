#ifndef DISPATCH_H
#define DISPATCH_H

#define RISCV_MACHINE_CALL_M_MODE (11)

void syscall_dispatch(uint32_t code, uint32_t param);
void excepcion_dispatch(uint32_t code);
void irq_dispatch(uint32_t code);

void install_irq_handler( uint32_t irq_num, void (*f)(void) );
void uninstall_irq_handler( uint32_t irq_num );

void install_local_timer_handler( void (*f)(void) );
void uninstall_local_timer_handler();
void local_timer_set_gap( uint64_t gap );

void raise_SW_interrupt( uint32_t hart );

// SET STATUS REG MIE BIT (Global IRQ enable)
void enable_irq(void);

// CLEAR STATUS REG MIE BIT (Global IRQ disable)
void disable_irq(void);

// SET MIE REG EXT_IRQ BIT (EXT IRQ enable)
void enable_ext_irq(void);

// CLEAR MIE REG EXT_IRQ BIT (EXT IRQ disable)
void disable_ext_irq(void);

// SET MIE REG TIMER BIT (Timer irq enable)
void enable_timer_clinc_irq(void);

// CLEAR MIE REG TIMER BIT (Timer irq disable)
void disable_timer_clinc_irq(void);

// SET MIE REG SW BIT
void enable_SW_IRQ(void);

// CLEAR MIE REG SW BIT
void disable_SW_IRQ(void);

// MASK PLIC external IRQ
void plic_irq_mask(uint32_t source);

// UNMASK PLIC external IRQ
void plic_irq_unmask(uint32_t source);

// syscall (Executive call)
void syscall(uint32_t N, uint32_t param );

#endif /* DISPATCH_H */
