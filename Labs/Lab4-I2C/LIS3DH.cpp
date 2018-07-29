/**
 * LIS23DH.cpp
 *
 *  Created on: Jul 9, 2017
 *      Author: Jason Forsyth
 */

#include "LIS3DH.h"
#include "Helper.h"

/**
 * Default constructor. Acquires and configures
 * custom I2C interface
 */
LIS3DH::LIS3DH() {


	i2c=CustomI2C::getInstance();

}

LIS3DH::~LIS3DH() {

}

/**
 * Initialize LIS3DH to:
 * 	-FIFO in Bypass Mode
 * 	- 50 Hz sampling and normal mode (Set LPEN, BDR, XYZEN, and HR)
 *
 * 	All other parameters are defaults
 */
void LIS3DH::setupLIS3DH()
{
	/**
	 * Default power mode after reset is Power Down Mode.
	 * Must set HR to 1 and LPen to 0 to get into Normal
	 * High Resolution mode. All axis must be enabled and desired
	 * sampling rate is 50Hz. Thus CTRL1 looks like:
	 * [ORD3-ORD0][LPen][ZYXen]
	 * [0100][0][111] = 0x47
	 */

	uint8_t ctrl1Config = readRegister(CTRL_REG_1);

	writeRegister(CTRL_REG_1, 0x47u);

	//delay 5ms to ensure switch over time. See application note
	Helper::delay(7);

	/**
	 *Get the current value of the control register
	 */
	uint8_t ctrl4Config = readRegister(CTRL_REG_4);

	/**
	 * Set HR[3] bit in CTRL4
	 */

	ctrl4Config|=(0x1<<3);

	/**
	 * Set BDU[7] in CTRL_REG_4
	 * This needs to be set to read good
	 * values from the accel readings. Probably
	 * could be removed if paid attention to the RDY bit.
	 */
	ctrl4Config|=(0x1<<7);

	writeRegister(CTRL_REG_4,ctrl4Config);
}


/**
 * Initialize SPI device with default parameters with
 * the associated bus speed. Set the FIFO to Bypass Mode
 * and enable the temperature sensor.
 */
bool LIS3DH::initialize()
{
	//ensure device has sufficient time to power on
	//and load configuration information
	Helper::delay(5);

	//This can be commented out until you
	//have completed the writeRegister function in 
	//CustomI2C
	//configure the LIS3DH
	setupLIS3DH();

	return true;
}

bool LIS3DH::selfTest()
{
	if(readRegister(WHO_AM_I_REG)==0x33)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void LIS3DH::writeRegister(uint8_t address, uint8_t value)
{
	bool success=i2c->writeRegister(LIS3DH_I2C_ADDRESS,address,value);

	//if the write failed...
	if(!success)
	{
		//do something
	}
}

uint8_t LIS3DH::readRegister(uint8_t address)
{
	//create a uint8_t and pass as point to function so that
	//can be "passed back" via the parameter
	uint8_t rtr;
	bool success = i2c->readRegister(LIS3DH_I2C_ADDRESS,address,&rtr);

	//if the read failed...
	if(!success)
	{
		//do something...
	}
	return rtr;
}



/**
 * Convert int16_t reading into floating. Assumes +/-2g range and 1mg/digit
 * point acceleration value
 * @param reading 2's complement signed value to be converted in a floating point acceleration
 * @return floating point value expressing an acceleration
 */
float LIS3DH::convertReadingToAccel(int16_t reading) {
	return (float)reading/(float)16383;
}

/**
 * Get X-axis acceleration and convert to a floating point
 */
float LIS3DH::getXAcceleration()
{
	uint16_t lowerByte = readRegister(OUT_X_L);
	uint16_t upperByte = readRegister(OUT_X_H);

	int16_t reading = upperByte<<8|lowerByte;

	float accel = convertReadingToAccel(reading);

	return accel;
}

/**
 * Get Y-axis acceleration and convert to a floating point
 */
float LIS3DH::getYAcceleration()
{

	uint16_t lowerByte = readRegister(OUT_Y_L);
	uint16_t upperByte = readRegister(OUT_Y_H);

	int16_t reading = upperByte<<8|lowerByte;

	float accel = convertReadingToAccel(reading);

	return accel;
}


/**
 * Get Z-axis acceleration and convert to a floating point
 */
float LIS3DH::getZAcceleration()
{
	uint16_t lowerByte = readRegister(OUT_Z_L);
	uint16_t upperByte = readRegister(OUT_Z_H);

	int16_t reading = upperByte<<8|lowerByte;

	float accel = convertReadingToAccel(reading);

	return accel;
}
