#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "bsp.h"
#include "bsp_trace.h"
#include "em_gpio.h"

/**
 * Place definitions of useful registers below using the
 * #define methods described in class.
 */



//Port B definitions and addresses


//Port E definitions and addresses


/**
 * Helper functions defined below. Use at your own discretion.
 */

/**
 * Read the value of a single bit from a memory address
 * @param addr pointer to 32-bit memory location
 * @param pos bit-wise position [31-0] of the bit to read
 * @return value of that bit as an unsigned integer
 */
//unsigned int readBit(volatile const uint32_t *addr, unsigned int pos)


/**
 * Write a single bit into a memory location
 * @param addr pointer to a 32-bit memory location
 * @param bitPos the bit-wise position [31-0] of the bit to be written
 * @param val the value to be written into the bit position
 * @return void
 */
//void writeBit(volatile uint32_t *addr, unsigned int bitPos, unsigned int val)

/**
 * Set the output value of the in the DOUT register for a GPIO
 * @param addr pointer to the DOUT register of a GPIO port
 * @param value the unsigned value to be written to the pin
 * @param pinNum the pin number [15-0] where the value should be written
 */
//void setPinOutputValue(volatile uint32_t* addr, uint32_t value, uint32_t pinNum)


/**
 * Set pin mode. Only works if correct Port Mode register address is provided
 * @param addr address of the MODE register for a particular port
 * @param mode mode value to be written into the pin
 * @param pinNum the pin number [15-0] where the mode should be set
 */
//void setPinMode(volatile uint32_t *addr, uint32_t mode, uint32_t pinNum)


int main(void)
{
	/* Chip errata */
	CHIP_Init();

	/**
	 * Enable the peripheral clocks to the GPIO
	 * Not messing with the clocks by hand, they crazy
	 */

	//enable the clock for the High-Frequency Peripherals
	CMU_ClockEnable(cmuClock_HFPER, true);

	//enable the specific clock for the GPIO
	CMU_ClockEnable(cmuClock_GPIO, true);

	/**
	 * LED0 <-> PE2
	 * LED1 <-> PE3
	 */
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * Task 1: Easiest method using the EMLIB calls
	 * Read the Application Note 12 involving GPIO and
	 * use the built in calls to turn on LED1/PE3
	 *
	 *Application Note on GPIO: https://www.silabs.com/documents/public/application-notes/AN0012.pdf
	 * Documentation for GPIO Lib: https://siliconlabs.github.io/Gecko_SDK_Doc/efm32gg/html/group__GPIO.html
	 */

	/**
	 * Your code here
	 */

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/**
	 * Task 2: Typical Method using the GPIO data structures
	 * Read application Note 12 and determine that Port E is Enumeration 4 in the
	 * GPIO->P arrays. Use this to configure LED0/PE2 as an output. Make sure to comment
	 * out Task 1 above.
	 */

	/**
	 * Your code here
	 */

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Task 3: Pure Pointer Math. Calculate the addresses for PE_MODEL
	 * and PE_DOUT to manually configure the bits for LED1/PE3
	 */

	/**
	 * Your code here
	 */

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/**
	 * Task #4 Control LEDs with Push Buttons
	 */

	/**
	 * Your code here
	 */


	while (1)
	{
		/**
		 * Your code here
		 */
	}
}
