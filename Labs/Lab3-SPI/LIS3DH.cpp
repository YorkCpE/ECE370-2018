/**
 * LIS23DH.cpp
 *
 *  Created on: <DATE>
 *      Author: <NAME>
 */

#include "LIS3DH.h"
#include "Helper.h"

/**
 * Default constructor. Sets up default values
 */
LIS3DH::LIS3DH() {
	/**
	 * Default bus speed of 2MHz
	 */
	busSpeed=2000000;

	/**
	 * Default Pin Location #1
	 */
	pinLocation=1;

	/**
	 * Default USART1
	 */
	usart=USART1;

	/**
	 * Default scale range of +/- 2G
	 */
	scaleRange=2;

	/**
	 * Default sensitivity of 1mg/digit
	 */
	sensitivity=1;
}

/**
 * Destructor. Does nothing.
 */
LIS3DH::~LIS3DH() {

}

/**
 * Initialize SPI device to sample at 50Hz, enable
 * all axis, full power on. Set the FIFO to Bypass Mode (default). High Resolution Mode.
 *
 *@return result returns true if initialization completed successfully, otherwise false
 */

bool LIS3DH::initialize()
{
	/**
	 * ensure device has sufficient time to power on
	 * and load configuration information. See datasheet.
	 */
	delay(5);

	/**
	 * Since there is significant setup required for this device
	 * I suggest you break it down into sections/functions to perform each operation.
	 * Below are suggested functions that you can implement. Must declare these functions in the
	 * header file and then implement here.
	 */
	//configure the required clocks
	//setupClocks();

	//configure the required GPIO
	//setupGPIO();

	//configure the USART
	//setupUSART();

	/**
	 * Configure the LIS3DH itself. When switching over to
	 * High Resolution Mode make sure to delay 7ms after switching modes.
	 * See application note for details.
	 */
	//setupLIS3DH();

	return true;
}

/**
 * Perform a self-test by reading the WHO_AM_I
 * register.
 * @return returns true is self-test was completed successfully, otherwise false
 */
bool LIS3DH::selfTest()
{
	/**
	 * Perform a SPI read from the WHO_AM_I register.
	 * The returned value should be 0x33 if successful.
	 * Return true if successful, false otherwise.
	 */

	if(readRegister(WHO_AM_I_REG)==0x33)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * A simple delay function. Do not use for any accurate timing. Not guaranteed to work :)
 * @param num number of milliseconds to delay (approximately)
 */
void LIS3DH::delay(int num)
{
	int counter=0;
	for(int i=0;i<num*1000;i++)
	{
		counter++;
	}
}

void LIS3DH::setupClocks() {
	//enable the clock for the High-Frequency Peripherals

	//enable GPIO clock

	//enable the USART1 clock

}


