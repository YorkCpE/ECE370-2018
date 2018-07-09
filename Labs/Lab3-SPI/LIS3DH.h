/**
 * LIS23DH.h
 *
 *  Created on: <SUBMISSION DATE>
 *      Author: <YOUR NAME HERE>
 */

#ifndef USER_SRC_LIS3DH_H_
#define USER_SRC_LIS3DH_H_

#include <stdint.h>

#include "em_usart.h"
#include "em_gpio.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"

/**
 * Sample #define showing register definition
 */
#define WHO_AM_I_REG 0x0Fu

/**
 * @brief Sample driver for LIS3DH 3-axis accelerometer. Basic functionality
 * of sampling each axis is implemented along with self-test using WHO_AM_I register.
 * Other place holders available for expansion.
 */
class LIS3DH {
public:
	/**
	 * Default constructor
	 */
	LIS3DH();

	/**
	 * Default destructor. Does nothing.
	 */
	virtual ~LIS3DH();

	/**
	 * Initialize SPI device to communicate 2 MHz, sample at 50Hz, enable
	 * all axis measurements, full power on. Set the FIFO to Bypass Mode (default)
	 *
	 *@return result returns true if initialization completed successfully, otherwise false
	 */
	bool initialize();

	/**
	 * Perform a self-test by reading the WHO_AM_I
	 * register.
	 * @return returns true is self-test was completed successfully, otherwise false
	 */
	bool selfTest();

	/**
	 * Get X-axis acceleration and convert to a floating point
	 * @return x-axis acceleration expressed as a floating point
	 */
	float getXAcceleration();

	/**
	 * Get Y-axis acceleration and convert to a floating point
	 * @return y-axis acceleration expressed as a floating point
	 */
	float getYAcceleration();


	/**
	 * Get Z-axis acceleration and convert to a floating point
	 * @return z-axis acceleration expressed as a floating point
	 */
	float getZAcceleration();

	/**
	 * Place accelerometer in power down mode (Optional Bonus)
	 */
	void enablePowerDown();

	/**
	 * Disable power down mode and return the accelerometer
	 * Normal power at 50Hz sampling rate (Optional Bonus)
	 */
	void disablePowerDownMode();


private:
	/**
	 * Bus speed that SPI should operate
	 */
	int busSpeed;

	/**
	 * Handle to my USART. Enables to be used with any USART
	 * in the system. Will be set to USART1 for now. But will be a
	 * place holder for future expansion
	 */
	USART_TypeDef* usart;

	/**
	 * Pin location to be used for USART. Will be set to Location 1 for
	 * now but will be place holder for future expansion
	 */
	int pinLocation;

	/**
	 * Set value for acceleration range. Acceptable values
	 * are 2, 4, 6, and 8g. Default is +/- 2g.
	 */
	int scaleRange;

	/**
	 * Sampling sensitivity for the accelerometer based upon
	 * scale range. Default is 1mg/digit.
	 */
	int sensitivity;

	/**
	 * Read a single register and return its value
	 * @param address 8-bit address of internal register to read
	 * @return	the value that was contained in that register
	 */
	uint8_t readRegister(uint8_t address);

	/**
	 * Write a single register
	 * @param address 8-bit address of internal register to read
	 * @param data 8-bit data value that should be written to the register
	 */
	void writeRegister(uint8_t address , uint8_t data);

	/**
	 * Conduct transfer on SPI bus with included data
	 * @param data 8-bit data that should be transmitted over the SPI bus
	 * @return received 8-bits as result of transmission
	 */
	uint8_t SPI_Transfer(uint8_t data);

	/**
	 * Helper function to setup the associated clocks
	 */
	void setupClocks();

	/**
	 * Helper function to setup the associated GPIO
	 */
	void setupGPIO();

	/**
	 * Helper function to setup the USART
	 * for SPI operation
	 */
	void setupUSART();

	/**
	 * Setup accelerometer to default parameters
	 * defined in project specification
	 */
	void setupLIS3DH();

	/**
	 * Standard delay function to ensure proper power up
	 * and power down times
	 * @param num number of milliseconds (approximately) to delay
	 */
	void delay(int num);

	/**
	 * Convert int16_t reading into floating point acceleration value
	 * @param  2's complement signed value to be converted in a floating point acceleration
	 * @return floating point value expressing an acceleration
	 */
	float convertReadingToAccel(int16_t reading);
};

#endif
