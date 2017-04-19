#include <SI_EFM8BB3_Register_Enums.h>

#define SYSCLK             3062000

// Configurator set for timer overflow every 100 ms / 10 Hz.
#define PERIOD           100  //  toggle rate in milliseconds
                                       // if PERIOD = 1, the LED will
                                       // be on for 1 millisecond and off for
                                       // 1 millisecond

//-----------------------------------------------------------------------------
// Pin Declarations
//-----------------------------------------------------------------------------
//SI_SBIT (LED_GREEN, SFR_P1, 4);           // green LED
//SI_SBIT (LED_BLUE,  SFR_P1, 5);           // blue LED
//SI_SBIT (LED_RED,  SFR_P1, 6);           // red LED
SI_SBIT (OUT,  SFR_P0, 1);

SI_INTERRUPT (INT0_ISR, INT0_IRQn)
{
   IE_ET0 = !IE_ET0;	//toggle interrupt enable for timer0
}


SI_INTERRUPT (TIMER0_ISR, TIMER0_IRQn)
{
   static uint16_t counter = 0;

   counter++;

   if(counter == PERIOD)
   {
	  OUT = !OUT;                    // Toggle the output pin
	  counter = 0;
   }
}

