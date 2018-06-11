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
 * Helper function take from em_bus.h
 */
unsigned int readBit(volatile const uint32_t *addr, uint32_t bit)
{
	return ((*addr)>>bit) & 0x1;
}

/**
 * Helper function take from em_bus.h
 */
void writeBit(volatile uint32_t *addr, uint32_t bitPos, uint32_t val)
{
	uint32_t tmp = *addr;
	*addr = (tmp & ~(1 << bitPos)) | ((val & 0x1) << bitPos);
	return;
}

/**
 * Start a specified timer
 * @param timer A TIMER_TypeDef object for the timer you wish to modify
 */
inline void startTimer(TIMER_TypeDef* timer){};

/**
 * Stop a specified timer
 * @param timer A TIMER_TypeDef object for the timer you wish to modify
 */
inline void stopTimer(TIMER_TypeDef* timer){};

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
	 * When using functions like readBit and writeBit you
	 * need to pass a pointer to the register you're accessing
	 */

	//Imagine that you want to start a time by writing to bit 0
	//This function will not work because TIMER0->CMD is the actual register
	writeBit(TIMER0->CMD,0,1);

	//You must reference (&) the register to ensure the function works
	writeBit(&TIMER0->CMD,0,1);

	//Each data structure is different. You can also pass the structure to
	//a function while naming the correct structure

	//This line is correct as startTimer takes a TIMER_TypeDef*
	startTimer(TIMER0);

	//This line is NOT correct as you are now passing a pointer
	//to a pointer
	startTimer(&TIMER0);

	while(1)
	{

	}
}

