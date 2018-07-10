#include "em_device.h"
#include "em_chip.h"

#include <stdint.h>
#include <stdbool.h>
#include <cmath>

#include "LIS3DH.h"

/**
 * Instantiate a copy of the accelerometer
 * driver. You CANNOT call NEW! This is not
 * a desktop PC. Make the context static so it's not placed on the stack.
 */
LIS3DH accel;

/**
 * @brief Main function for SPI lab. Modify at your own risk as it will be
 * used as the test bed for your lab. I will only copy over your .h and .cpp files
 * when grading the lab.
 * @return Should never return....
 */
int main(void)
{
	/**
	 * Chip errata
	 */
	CHIP_Init();

	/**
	 * Setup for default operation.
	 * 2MHz operation SPI bus;
	 * Use USART1 and Pin Location #1
	 */
	//accel.initialize();

	/**
	 * Perform a self-test. This will attempt to
	 * read a fixed register on the LIS3DH. If the
	 * self-test fails, then your program should not proceed.
	 */
	/*bool selfTest=accel.selfSelf();
	if(!selfTest)
	{
		while(1){};
	}*/

	/**
	 * Once you've passed the self test. Attempt to read
	 * the acceleration from each axis. The magnitude of
	 * all accelerations should be close to 1g. Your result
	 * should not differ by more than 5%.
	 */
	/*float x=accel.getXAcceleration();
	float y=accel.getYAcceleration();
	float z=accel.getZAcceleration();*/

	/**
	 * Use illegal math functions to calculate a square root.
	 * This is possibly OK since this is a high-performance
	 * microprocessor and we only perform this operation once.
	 */
	//float mag = sqrt(x*x+y*y+z*z);

	while(true)
	{
		/**
		 * Dummy instruction so the compiler
		 * doesn't optimize this loop away and
		 * we restart at main()
		 */
		int counter=0;

	}
}

