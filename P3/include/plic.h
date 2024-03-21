#ifndef PLIC_H
#define PLIC_H

#define PLIC_BASE	    0x0C000000
#define PLIC_CONTEXT    0x200000	// PLIC CONTEXT offset
#define MAX_CONTEXT     15872       // MAX IRQ CONTEXT


#define RISCV_MACHINE_EXTERNAL_IRQ (11)

extern  struct plic_regs *p_plic;
extern  struct plic_context_regs *p_plic_context;

struct plic_context_regs {
        /*
         * The PLIC will mask all PLIC interrupts of a priority less than or
         * equal to threshold.
         */
        uint32_t priority_threshold;
        /* Interrupt Claim/Complete Process for context i */
        uint32_t claim_complete;
        uint32_t _dummy[1022];
};

struct plic_regs_old {
        /*
         * interrupt source i priority. i: 0 to 1023 and i=0 does not exist
         * one register per interrupt source
         */
        uint32_t priority[1024];
        /* one pending bit per interrupt source: 32 sources per register */
        uint32_t pending[1024/32];
        uint32_t _rsv0[1024 - 1024/32];
        uint32_t enable[16320][32];
        /* one field per context */
        struct plic_context_regs context[15872];
};

struct plic_regs {
        /*
         * interrupt source i priority. i: 0 to 1023 and i=0 does not exist
         * one register per interrupt source
         */
        uint32_t  priority[1024];

        /* one pending bit per interrupt source: 32 sources per register */
        uint32_t  pending[1024/32];                          // Offset 0x1000
        uint32_t  _dummy_0[1024 - 1024/32];

        uint32_t  enable[MAX_CONTEXT][1024/32];       // Offset 0x2000
        uint32_t  _dummy_1[16320-MAX_CONTEXT][1024/32];

        /* one field per context */
        struct plic_context_regs context[MAX_CONTEXT];  // Offset 0x200000
};

#endif /* PLIC_H */
