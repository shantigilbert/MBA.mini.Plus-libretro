#pragma once

#ifndef __M68000_H__
#define __M68000_H__


/* There are 7 levels of interrupt to the 68K.
 * A transition from < 7 to 7 will cause a non-maskable interrupt (NMI).
 */
#define M68K_IRQ_NONE	0
#define M68K_IRQ_1	1
#define M68K_IRQ_2	2
#define M68K_IRQ_3	3
#define M68K_IRQ_4	4
#define M68K_IRQ_5	5
#define M68K_IRQ_6	6
#define M68K_IRQ_7	7

/* CPU types for use in m68k_set_cpu_type() */
enum
{
	M68K_CPU_TYPE_INVALID,
	M68K_CPU_TYPE_68000,
	M68K_CPU_TYPE_68008
};

/* The M68000 is a 16/32-bit CISC microprocessor,
   which implements a 32-bit instruction set,
   with 32-bit registers and 32-bit internal data bus,
   but with a 16-bit data ALU and two 16-bit arithmetic ALUs
   and a 16-bit external data bus / a 24-bit address bus.
*/
DECLARE_LEGACY_CPU_DEVICE(M68000, m68000);

/* Except for its smaller data and address buses,
   (an 8-bit external data bus / a 20-bit address bus)
   the 68008 behaved identically to the 68000
   and had the same internal organization and microarchitecture.
*/
DECLARE_LEGACY_CPU_DEVICE(M68008, m68008);

/* Special interrupt acknowledge values.
 * Use these as special returns from the interrupt acknowledge callback
 * (specified later in this header).
 */

/* Causes an interrupt autovector (0x18 + interrupt level) to be taken.
 * This happens in a real 68K if VPA or AVEC is asserted during an interrupt
 * acknowledge cycle instead of DTACK.
 */
#define M68K_INT_ACK_AUTOVECTOR    0xffffffff

/* Causes the spurious interrupt vector (0x18) to be taken
 * This happens in a real 68K if BERR is asserted during the interrupt
 * acknowledge cycle (i.e. no devices responded to the acknowledge).
 */
#define M68K_INT_ACK_SPURIOUS      0xfffffffe

enum
{
	/* NOTE: M68K_SP fetches the current SP, be it USP, ISP, or MSP */
	M68K_PC, M68K_SP, M68K_ISP, M68K_USP, M68K_MSP, M68K_SR, M68K_VBR,
	M68K_SFC, M68K_DFC, M68K_CACR, M68K_CAAR, M68K_PREF_ADDR, M68K_PREF_DATA,
	M68K_D0, M68K_D1, M68K_D2, M68K_D3, M68K_D4, M68K_D5, M68K_D6, M68K_D7,
	M68K_A0, M68K_A1, M68K_A2, M68K_A3, M68K_A4, M68K_A5, M68K_A6, M68K_A7,
	M68K_FP0, M68K_FP1, M68K_FP2, M68K_FP3, M68K_FP4, M68K_FP5, M68K_FP6, M68K_FP7,
	M68K_FPSR, M68K_FPCR,

	M68K_GENPC = STATE_GENPC,
	M68K_GENSP = STATE_GENSP,
	M68K_GENPCBASE = STATE_GENPCBASE
};

typedef void (*m68k_bkpt_ack_func)(running_device *device, UINT32 data);
typedef void (*m68k_reset_func)(running_device *device);
typedef void (*m68k_cmpild_func)(running_device *device, UINT32 data, UINT8 reg);
typedef void (*m68k_rte_func)(running_device *device);
typedef int (*m68k_tas_func)(running_device *device);

void m68k_set_encrypted_opcode_range(running_device *device, offs_t start, offs_t end);
void m68k_set_reset_callback(running_device *device, m68k_reset_func callback);
void m68k_set_cmpild_callback(running_device *device, m68k_cmpild_func callback);
void m68k_set_rte_callback(running_device *device, m68k_rte_func callback);
void m68k_set_tas_callback(running_device *device, m68k_tas_func callback);

#endif /* __M68000_H__ */
