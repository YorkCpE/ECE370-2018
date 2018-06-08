#include <em_device.h>
#include <em_chip.h>
#include <em_cmu.h>
#include <em_emu.h>
#include <bsp.h>
#include <bsp_trace.h>
#include <em_gpio.h>
#include <em_timer.h>

#include <stdint.h>
#include <stdbool.h>

/**
 * Use these header files to contain functions and constants that will be useful
 * to you.
 */

#include "GPIO.h"
#include "Timer.h"
#include "Helper.h"


/**
 * Interrupt handler for all Timer0 interrupts
 */
void TIMER0_IRQHandler(void);


/**
 * Interrupt handler for all Timer1 interrupts
 */
void TIMER1_IRQHandler(void);


/**
 * GPIO Odd Interrupt Handler
 */
void GPIO_ODD_IRQHandler();

/**
 * GPIO Even Interrupt Handler
 */
void GPIO_EVEN_IRQHandler();



/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{
	/* Chip errata */
	CHIP_Init();

	//enable the clock for the High-Frequency Peripherals
	CMU_ClockEnable(cmuClock_HFPER, true);

	//enable the specific clock for the TIMER0
	CMU_ClockEnable(cmuClock_TIMER0, true);

	//enable GPIO clock
	CMU_ClockEnable(cmuClock_GPIO,true);


	/**
	 * Setup PB9 as Input. Attach to interrupt handler.
	 */

	/**
	 * Setup PB10 as Input. Attach to interrupt handler.
	 */



	///////////No Student Code Below This Point///////////
	/**
	 * Dummy variables in while(1) so you can set break points
	 */
	int counter=0;
	while(1)
	{
		counter++;
		///Place no code in the while(1) loop///
	}
}

