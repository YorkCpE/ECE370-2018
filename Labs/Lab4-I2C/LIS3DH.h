/**
 * LIS3DH.h
 *
 *  Created on: Jul 9, 2017
 *      Author: Jason Forsyth
 */

#ifndef USER_SRC_LIS3DH_H_
#define USER_SRC_LIS3DH_H_

/**
 * Necessary includes
 */
#include <stdint.h>
#include <assert.h>

#include "em_usart.h"
#include "em_gpio.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"

/**
 * Include to CustomI2C class that will handle all i2c operations.
 * There is no need to modify the LIS3DH class at all. All functionality
 * has been included for you.
 */
#include "CustomI2C.h"

/**
 * Common register addresses for LIS3DH
 */

/**
 * LIS3DH i2c Address
 */
#define LIS3DH_I2C_ADDRESS 

#define WHO_AM_I_REG 0x0Fu

#define CTRL_REG_1 0x20u
#define CTRL_REG_2 0x21u
#define CTRL_REG_3 0x22u
#define CTRL_REG_4 0x23u
#define CTRL_REG_5 0x24u
#define CTRL_REG_6 0x25u

#define OUT_X_L 0x28u
#define OUT_X_H 0x29u

#define OUT_Y_L 0x2Au
#define OUT_Y_H 0x2Bu

#define OUT_Z_L 0x2Cu
#define OUT_Z_H 0x2Du

class LIS3DH {
public:
	LIS3DH();
	virtual ~LIS3DH();

	/**
	 * Initialize LIS3DH to sample at 50Hz, enable
	 * all axis, full power on. Set the FIFO to Bypass Mode (default). High Resolution Mode.
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

private:

	/**
	 * Handle to my I2C Interface. Enables to be used with any I2C
	 * in the system. Will be set to I2C1 for now. But will be a
	 * place holder for future expansion
	 */
	CustomI2C* i2c;

	/**
	 * Read a single register on the LIS3DH and return its value
	 * @param address 8-bit address of internal register to read
	 * @return	the value that was contained in that register
	 */
	uint8_t readRegister(uint8_t address);

	/**
	 * Write a single register on the LIS3DH
	 * @param address 8-bit address of internal register to read
	 * @param data 8-bit data value that should be written to the register
	 */
	void writeRegister(uint8_t address , uint8_t data);

	/**
	 * Setup accelerometer to default parameters
	 * defined in project specification
	 */
	void setupLIS3DH();

	/**
	 * Convert int16_t reading into floating. Assumes +/-2g range and 1mg/digit
	 * point acceleration value
	 * @param reading 2's complement signed value to be converted in a floating point acceleration
	 * @return floating point value expressing an acceleration
	 */
	float convertReadingToAccel(int16_t reading);
};

#endif /* USER_SRC_LIS3DH_H_ */
