#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "bsp.h"
#include "bsp_trace.h"
#include "em_gpio.h"
#include "em_timer.h"

#include <stdint.h>
#include <stdbool.h>

/**
 * Helper function take from em_bus.h
 */
unsigned int readBit(volatile const uint32_t *addr, unsigned int bit)
{
	return ((*addr)>>bit) & 0x1;
}

/**
 * Helper function take from em_bus.h
 */
void writeBit(volatile uint32_t *addr, unsigned int bitPos, unsigned int val)
{
	uint32_t tmp = *addr;
	*addr = (tmp & ~(1 << bitPos)) | ((val & 0x1) << bitPos);
	return;
}

/**
 * TIMER0 interrupt handler. Will pop on any
 * interrupt enabled with TIMER0
 */
void TIMER0_IRQHandler(void)
{
	//Must still clear associated flag in TIMER0 or we will keep ending up here


	//stop the timer


	//read the value just for fun (to create a breakpoint)
	//CNT should be value approx. for one second delay


}


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

	//double check that clock is 14 MHz
	unsigned int timerClock = CMU_ClockFreqGet(cmuClock_TIMER0);

	/**
	 * Dumb Method 1: Manually start/top the timer and peek at it's value
	 * Use the Application note as a reference
	 */

	//(a) set timer MODE UP, if needed

	//(b) set timer clksel HFPER, if needed

	//(c) set prescale to 1024

	//(d) enable debugRun

	//(e) enable the timer and start counting

	/* (f)
	 * threshold = (duration * clock freq) / pre-scaler
	 * Set this to the value of a 1s timer
	 */
	unsigned int timerThershold = 0000;

	//make a dummy loop and wait until we hit the
	//threshold
	while(TIMER0->CNT<=timerThershold){}

	//(e) stop the timer


	//(f) see what value we actually stopped at
	//should only off by 1-2 values but should we waste our time
	//constantly polling a variable?
	unsigned int value = TIMER0->CNT;

	// (g) reset timer count register to 0
	
	////////////////////////// END TASK 1 //////////////////////////

	/**
	 * Smarter Method 2: Set a top value in the timer and look for the overflow flag
	 */

	//(a) set a threshold in top that will
	//cause an overflow when we reach one second


	//(b) start the timer

	//(c) poll/wait until the IF flag occurs

	//(d) stop the timer

	//(e) clear the IF flag
	
	////////////////////////// END TASK 2 //////////////////////////

	/**
	 * Real Engineer Method 3: Create an interrupt handler to deal with the overflow
	 */

	//(a) clear the counter from the previous step

	//(b) enable OVERFLOW interrupt in the TIMER
	//IEN register

	/* (c) Enable TIMER0 interrupt vector in NVIC */
	NVIC_EnableIRQ(TIMER0_IRQn);

	// (d) start the timer
	TIMER0->CMD=0x1;


	/*
	 * The TIMER0 interrupt handler should now pop one second later
	 */

	//(e) complete implementation of TIMER0_IRQHandler interrupt handler above. Do not write your
	// code here. It should go in the TIMER0 function above main()

	////////////////////////// END TASK 3 //////////////////////////
	while(1)
	{

	}
}

