
#include <SI_EFM8BB3_Register_Enums.h>

//-----------------------------------------------------------------------------
// Global Constants
//-----------------------------------------------------------------------------
// Configurator set for HFOSC0/8
#define SYSCLK             3062000

// Configurator set for timer overflow every 100 ms / 10 Hz.
#define TOGGLE_RATE           100      // toggle rate in milliseconds

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------
SI_SBIT (LED_GREEN, SFR_P1, 4);           // green LED
SI_SBIT (LED_BLUE,  SFR_P1, 5);           // blue LED
SI_SBIT (LED_RED,  SFR_P1, 6);           // red LED

//-----------------------------------------------------------------------------
// TIMER0_ISR - timer overflow interrupt
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER0_ISR, TIMER0_IRQn)
{
   static uint16_t counter = 0;

   counter++;

   if(counter == TOGGLE_RATE)
   {
	  LED_GREEN = !LED_GREEN;
	  totalTime++;
	  counter = 0;
   }
}

//-----------------------------------------------------------------------------
// INT0_ISR - lap interrupt
//-----------------------------------------------------------------------------
SI_INTERRUPT (INT0_ISR, INT0_IRQn)
{
  LED_BLUE = !LED_BLUE;
  lapTimes[lap] = totalTime;
  lap++;
}

//-----------------------------------------------------------------------------
// INT1_ISR - start/stop interrupt
//-----------------------------------------------------------------------------
SI_INTERRUPT (INT1_ISR, INT1_IRQn)
{
   IE_ET0 = !IE_ET0;
}

