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
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_gpio.h"
#include "em_timer.h"
#include "bsp.h"
#include "bsp_trace.h"


/**
 * Place definitions of useful registers below using the
 * #define methods described in class.
 */

//Port B definitions and addresses. Ensure UL is added to address
//for correct calculation!
#define GPIO_BASE_ADDRESS 0x40006000UL
#define GPIO_PB_DIN_OFFSET 0x040UL
#define GPIO_PB_DIN_ADDR (GPIO_BASE_ADDRESS+GPIO_PB_DIN_OFFSET)


/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{
	/* Chip errata */
	CHIP_Init();

	//enable the clock for the High-Frequency Peripherals
	CMU_ClockEnable(cmuClock_HFPER, true);


	//enable GPIO clock
	CMU_ClockEnable(cmuClock_GPIO,true);


	/**
	 * Use the #define above to "calculate" your address. Then create
	 * a uint32_t* and cast it as the address
	 */

	uint32_t* pointerToPortB_DIN = (uint32_t*)GPIO_PB_DIN_ADDR;

	/**
	 * Now you can use the pointer to access the register.
	 */

	unsigned int value = *pointerToPortB_DIN;

	//value now contains the contents of Port B DIN Register. You can
	//read the individual bits to get the state.

	while(1)
	{

	}
}

