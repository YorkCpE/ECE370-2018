

#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_i2c.h"


#include <stdint.h>
#include <stdbool.h>
#include <cmath>


#include "LIS3DH.h"

/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/

LIS3DH accel;

int main(void)
{

	/* Chip errata */
	CHIP_Init();

	/**
	 * Setup for default operation.
	 * 2MHz operation SPI bus;
	 * Use USART1 and Pin Location #1
	 */
	accel.initialize();

	/**
	 * Perform a self-test. This will attempt to
	 * read a fixed register on the LIS3DH. If the
	 * self-test fails, then your program should not proceed.
	 */
	bool selfTest=accel.selfTest();
	if(!selfTest)
	{
		while(1){};
	}

	/**
	 * Once you've passed the self test. Attempt to read
	 * the acceleration from each axis. The magnitude of
	 * all accelerations should be close to 1g. Your result
	 * should not differ by more than 5%.
	 */
	float x=accel.getXAcceleration();
	float y=accel.getYAcceleration();
	float z=accel.getZAcceleration();

	/**
	 * Use illegal math functions to calculate a square root.
	 * This is possibly OK since this is a high-performance
	 * microprocessor and we only perform this operation once.
	 */
	float mag = sqrt(x*x+y*y+z*z);

	int counter=0;
	while(true)
	{
		counter++;
	}

}
