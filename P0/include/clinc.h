#ifndef CLINC_H
#define CLINC_H

#define CLINC_BASE		0x02000000
#define MSIP_BASE		0x0
#define MTIMECMP_BASE	0x4000
#define MTIME_BASE		0xbff8

#define RISCV_MACHINE_TIMER_IRQ (7)
#define RISCV_MACHINE_SW_IRQ    (3)

extern volatile uint32_t *p_clinc_msip;
extern volatile uint64_t *p_clinc_timecmp;
extern volatile uint64_t *p_clinc_mtime;

#endif /* CLINC_H */
