//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8BB3_Register_Enums.h>
#include "InitDevice.h"

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------
SI_SBIT (DISP_EN, SFR_P3, 4);          // Display Enable
SI_SBIT (S1, SFR_P0, 2);
SI_SBIT (S2, SFR_P0, 3);

#define DISP_BC_DRIVEN   0             // 0 = Board Controller drives display
#define DISP_EFM8_DRIVEN 1             // 1 = EFM8 drives display


//-----------------------------------------------------------------------------
// Main Routine
//-----------------------------------------------------------------------------
void main (void)
{
   enter_DefaultMode_from_RESET();

   DISP_EN = DISP_BC_DRIVEN;           // EFM8 does not drive display

   IE_EA = 1;                          // Enable global interrupts

   while (1) {
	      // Wait for both switches to be released before re-enabling external interrupts
//	      if ((S1 == 0) || (S2 == 0))
//	      {
//	         IE_EX0 = 0;
//	         IE_EX1 = 0;
//	      }
//	      else {
//	    	  IE_EX0 = 1;
//	    	  IE_EX1 = 1;
//	      }
   }
}
