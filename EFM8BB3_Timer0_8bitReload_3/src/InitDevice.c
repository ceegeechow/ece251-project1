//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8BB3_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	// Save the SFRPAGE
	uint8_t SFRPAGE_save = SFRPAGE;
	WDT_0_enter_DefaultMode_from_RESET();
	PORTS_1_enter_DefaultMode_from_RESET();
	PORTS_2_enter_DefaultMode_from_RESET();
	PBCFG_0_enter_DefaultMode_from_RESET();
	TIMER01_0_enter_DefaultMode_from_RESET();
	TIMER_SETUP_0_enter_DefaultMode_from_RESET();
	EXTINT_0_enter_DefaultMode_from_RESET();
	INTERRUPT_0_enter_DefaultMode_from_RESET();
	// Restore the SFRPAGE
	SFRPAGE = SFRPAGE_save;
	// [Config Calls]$

}

//================================================================================
// WDT_0_enter_DefaultMode_from_RESET
//================================================================================
extern void WDT_0_enter_DefaultMode_from_RESET(void) {
	// $[WDTCN - Watchdog Timer Control]
	SFRPAGE = 0x00;
	//Disable Watchdog with key sequence
	WDTCN = 0xDE; //First key
	WDTCN = 0xAD; //Second key
	// [WDTCN - Watchdog Timer Control]$

}

//================================================================================
// PORTS_2_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTS_2_enter_DefaultMode_from_RESET(void) {
	// $[P2 - Port 2 Pin Latch]
	// [P2 - Port 2 Pin Latch]$

	// $[P2MDOUT - Port 2 Output Mode]
	/***********************************************************************
	 - P2.0 output is open-drain
	 - P2.1 output is open-drain
	 - P2.2 output is open-drain
	 - P2.3 output is push-pull
	 - P2.4 output is open-drain
	 - P2.5 output is open-drain
	 - P2.6 output is open-drain
	 ***********************************************************************/
	P2MDOUT = P2MDOUT_B0__OPEN_DRAIN | P2MDOUT_B1__OPEN_DRAIN
			| P2MDOUT_B2__OPEN_DRAIN | P2MDOUT_B3__PUSH_PULL
			| P2MDOUT_B4__OPEN_DRAIN | P2MDOUT_B5__OPEN_DRAIN
			| P2MDOUT_B6__OPEN_DRAIN;
	// [P2MDOUT - Port 2 Output Mode]$

	// $[P2MDIN - Port 2 Input Mode]
	// [P2MDIN - Port 2 Input Mode]$

	// $[P2SKIP - Port 2 Skip]
	/***********************************************************************
	 - P2.0 pin is not skipped by the crossbar
	 - P2.1 pin is not skipped by the crossbar
	 - P2.2 pin is not skipped by the crossbar
	 - P2.3 pin is skipped by the crossbar
	 ***********************************************************************/
	SFRPAGE = 0x20;
	P2SKIP = P2SKIP_B0__NOT_SKIPPED | P2SKIP_B1__NOT_SKIPPED
			| P2SKIP_B2__NOT_SKIPPED | P2SKIP_B3__SKIPPED;
	// [P2SKIP - Port 2 Skip]$

	// $[P2MASK - Port 2 Mask]
	// [P2MASK - Port 2 Mask]$

	// $[P2MAT - Port 2 Match]
	// [P2MAT - Port 2 Match]$

}

//================================================================================
// PBCFG_0_enter_DefaultMode_from_RESET
//================================================================================
extern void PBCFG_0_enter_DefaultMode_from_RESET(void) {
	// $[XBR2 - Port I/O Crossbar 2]
	/***********************************************************************
	 - Weak Pullups enabled 
	 - Crossbar enabled
	 - UART1 I/O unavailable at Port pin
	 - UART1 RTS1 unavailable at Port pin
	 - UART1 CTS1 unavailable at Port pin
	 ***********************************************************************/
	SFRPAGE = 0x00;
	XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED
			| XBR2_URT1E__DISABLED | XBR2_URT1RTSE__DISABLED
			| XBR2_URT1CTSE__DISABLED;
	// [XBR2 - Port I/O Crossbar 2]$

	// $[PRTDRV - Port Drive Strength]
	// [PRTDRV - Port Drive Strength]$

	// $[XBR0 - Port I/O Crossbar 0]
	// [XBR0 - Port I/O Crossbar 0]$

	// $[XBR1 - Port I/O Crossbar 1]
	// [XBR1 - Port I/O Crossbar 1]$

}

//================================================================================
// TIMER01_0_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER01_0_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	//Save Timer Configuration
	uint8_t TCON_save;
	TCON_save = TCON;
	//Stop Timers
	TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;

	// [Timer Initialization]$

	// $[TH0 - Timer 0 High Byte]
	/***********************************************************************
	 - Timer 0 High Byte = 0xC0
	 ***********************************************************************/
	TH0 = (0xC0 << TH0_TH0__SHIFT);
	// [TH0 - Timer 0 High Byte]$

	// $[TL0 - Timer 0 Low Byte]
	// [TL0 - Timer 0 Low Byte]$

	// $[TH1 - Timer 1 High Byte]
	// [TH1 - Timer 1 High Byte]$

	// $[TL1 - Timer 1 Low Byte]
	// [TL1 - Timer 1 Low Byte]$

	// $[Timer Restoration]
	//Restore Timer Configuration
	TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);

	// [Timer Restoration]$

}

//================================================================================
// TIMER_SETUP_0_enter_DefaultMode_from_RESET
//================================================================================
extern void TIMER_SETUP_0_enter_DefaultMode_from_RESET(void) {
	// $[CKCON0 - Clock Control 0]
	/***********************************************************************
	 - System clock divided by 48
	 - Counter/Timer 0 uses the clock defined by the prescale field, SCA
	 - Timer 2 high byte uses the clock defined by T2XCLK in TMR2CN0
	 - Timer 2 low byte uses the clock defined by T2XCLK in TMR2CN0
	 - Timer 3 high byte uses the clock defined by T3XCLK in TMR3CN0
	 - Timer 3 low byte uses the clock defined by T3XCLK in TMR3CN0
	 - Timer 1 uses the clock defined by the prescale field, SCA
	 ***********************************************************************/
	CKCON0 = CKCON0_SCA__SYSCLK_DIV_48 | CKCON0_T0M__PRESCALE
			| CKCON0_T2MH__EXTERNAL_CLOCK | CKCON0_T2ML__EXTERNAL_CLOCK
			| CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
			| CKCON0_T1M__PRESCALE;
	// [CKCON0 - Clock Control 0]$

	// $[CKCON1 - Clock Control 1]
	// [CKCON1 - Clock Control 1]$

	// $[TMOD - Timer 0/1 Mode]
	/***********************************************************************
	 - Mode 2, 8-bit Counter/Timer with Auto-Reload
	 - Mode 0, 13-bit Counter/Timer
	 - Timer Mode
	 - Timer 0 enabled when TR0 = 1 irrespective of INT0 logic level
	 - Timer Mode
	 - Timer 1 enabled when TR1 = 1 irrespective of INT1 logic level
	 ***********************************************************************/
	TMOD = TMOD_T0M__MODE2 | TMOD_T1M__MODE0 | TMOD_CT0__TIMER
			| TMOD_GATE0__DISABLED | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
	// [TMOD - Timer 0/1 Mode]$

	// $[TCON - Timer 0/1 Control]
	/***********************************************************************
	 - Start Timer 0 running
	 ***********************************************************************/
	TCON |= TCON_TR0__RUN;
	// [TCON - Timer 0/1 Control]$

}

//================================================================================
// INTERRUPT_0_enter_DefaultMode_from_RESET
//================================================================================
extern void INTERRUPT_0_enter_DefaultMode_from_RESET(void) {
	// $[EIE1 - Extended Interrupt Enable 1]
	// [EIE1 - Extended Interrupt Enable 1]$

	// $[EIE2 - Extended Interrupt Enable 2]
	// [EIE2 - Extended Interrupt Enable 2]$

	// $[EIP1H - Extended Interrupt Priority 1 High]
	// [EIP1H - Extended Interrupt Priority 1 High]$

	// $[EIP1 - Extended Interrupt Priority 1 Low]
	// [EIP1 - Extended Interrupt Priority 1 Low]$

	// $[EIP2 - Extended Interrupt Priority 2]
	// [EIP2 - Extended Interrupt Priority 2]$

	// $[EIP2H - Extended Interrupt Priority 2 High]
	// [EIP2H - Extended Interrupt Priority 2 High]$

	// $[IE - Interrupt Enable]
	/***********************************************************************
	 - Enable each interrupt according to its individual mask setting
	 - Enable interrupt requests generated by the INT0 input
	 - Enable interrupt requests generated by the INT1 input
	 - Disable all SPI0 interrupts
	 - Enable interrupt requests generated by the TF0 flag
	 - Disable all Timer 1 interrupt
	 - Disable Timer 2 interrupt
	 - Disable UART0 interrupt
	 ***********************************************************************/
	IE = IE_EA__ENABLED | IE_EX0__ENABLED | IE_EX1__ENABLED | IE_ESPI0__DISABLED
			| IE_ET0__ENABLED | IE_ET1__DISABLED | IE_ET2__DISABLED
			| IE_ES0__DISABLED;
	// [IE - Interrupt Enable]$

	// $[IP - Interrupt Priority]
	// [IP - Interrupt Priority]$

	// $[IPH - Interrupt Priority High]
	// [IPH - Interrupt Priority High]$

}

extern void PORTS_1_enter_DefaultMode_from_RESET(void) {
	// $[P1 - Port 1 Pin Latch]
	// [P1 - Port 1 Pin Latch]$

	// $[P1MDOUT - Port 1 Output Mode]
	/***********************************************************************
	 - P1.0 output is open-drain
	 - P1.1 output is open-drain
	 - P1.2 output is open-drain
	 - P1.3 output is open-drain
	 - P1.4 output is push-pull
	 - P1.5 output is push-pull
	 - P1.6 output is push-pull
	 - P1.7 output is open-drain
	 ***********************************************************************/
	P1MDOUT = P1MDOUT_B0__OPEN_DRAIN | P1MDOUT_B1__OPEN_DRAIN
			| P1MDOUT_B2__OPEN_DRAIN | P1MDOUT_B3__OPEN_DRAIN
			| P1MDOUT_B4__PUSH_PULL | P1MDOUT_B5__PUSH_PULL
			| P1MDOUT_B6__PUSH_PULL | P1MDOUT_B7__OPEN_DRAIN;
	// [P1MDOUT - Port 1 Output Mode]$

	// $[P1MDIN - Port 1 Input Mode]
	// [P1MDIN - Port 1 Input Mode]$

	// $[P1SKIP - Port 1 Skip]
	/***********************************************************************
	 - P1.0 pin is not skipped by the crossbar
	 - P1.1 pin is not skipped by the crossbar
	 - P1.2 pin is not skipped by the crossbar
	 - P1.3 pin is not skipped by the crossbar
	 - P1.4 pin is skipped by the crossbar
	 - P1.5 pin is skipped by the crossbar
	 - P1.6 pin is skipped by the crossbar
	 - P1.7 pin is not skipped by the crossbar
	 ***********************************************************************/
	P1SKIP = P1SKIP_B0__NOT_SKIPPED | P1SKIP_B1__NOT_SKIPPED
			| P1SKIP_B2__NOT_SKIPPED | P1SKIP_B3__NOT_SKIPPED
			| P1SKIP_B4__SKIPPED | P1SKIP_B5__SKIPPED | P1SKIP_B6__SKIPPED
			| P1SKIP_B7__NOT_SKIPPED;
	// [P1SKIP - Port 1 Skip]$

	// $[P1MASK - Port 1 Mask]
	// [P1MASK - Port 1 Mask]$

	// $[P1MAT - Port 1 Match]
	// [P1MAT - Port 1 Match]$

}

extern void EXTINT_0_enter_DefaultMode_from_RESET(void) {
	// $[IT01CF - INT0/INT1 Configuration]
	/***********************************************************************
	 - INT0 input is active low
	 - Select P0.2
	 - INT1 input is active low
	 - Select P0.3
	 ***********************************************************************/
	IT01CF = IT01CF_IN0PL__ACTIVE_LOW | IT01CF_IN0SL__P0_2
			| IT01CF_IN1PL__ACTIVE_LOW | IT01CF_IN1SL__P0_3;
	// [IT01CF - INT0/INT1 Configuration]$

}

