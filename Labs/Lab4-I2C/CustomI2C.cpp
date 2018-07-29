/*
 * I2C.cpp
 *
 *  Created on: Jul 28, 2018
 *      Author: jforsyth
 */

#include "CustomI2C.h"

#include "em_i2c.h"
#include "em_gpio.h"
#include "em_device.h"
#include "em_chip.h"
#include "em_cmu.h"

#include "Helper.h"

/**
 * Static instance that we'll pass around. This may be dangerous
 * as ChipInit() has yet to be called... Could use dynamic invocation
 * to fix this but seems to work so far :)
 */
CustomI2C CustomI2C::singleton;

/**
 * Constructor for class. Use to setup clocks, GPIO, and I2C.
 */
CustomI2C::CustomI2C()
{
	setupClocks();

	setupGPIO();

	setupI2C();
}

CustomI2C::~CustomI2C()
{
	//do nothing
}


CustomI2C* CustomI2C::getInstance()
{
	/**
	 * Return a pointer to the singleton.
	 * Already constructed via static allocation.
	 */
	return &singleton;
}

/**
 * TODO: Implement this function
 */
void CustomI2C::setupClocks()
{
	
}

/**
 * TODO: Implement this function
 */
void CustomI2C::setupGPIO()
{
	
}

/**
 * TODO: Implement this function
 */
void CustomI2C::setupI2C()
{
	/**
	 * Setup I2C
	 */

	
	/**
	* Do this last. No code below here.
	*/
	//send abort as bus is busy by default
	// abort[5] in CMD
	I2C1->CMD |= (0x1) << 5;
}


I2C_State CustomI2C::getI2CState()
{
	//Grab the STATE[7:5] bits from the STATE register
	uint8_t stateBits = (I2C1->STATE>>5)&0x7;

	//Cast these bits as I2C_State enum. Because I2C_State
	//is the exact order as STATE field. Then ENUM will directly
	//correspond to the state. i.e. stateBits=0x0->IDLE; stateBits=0x4->ADDRACK
	return (I2C_State)(stateBits);
}

/**
 * TODO: Implement this function
 */
bool CustomI2C::writeRegister(uint8_t i2cAddress, uint8_t internalRegAddr, uint8_t value)
{
	
	//successful, return true
	return true;
}

/**
 * TODO: Implement this function
 */
bool CustomI2C::readRegister(uint8_t i2cAddress, uint8_t internalRegAddr, uint8_t* rtr)
{
	
	//successful, return true
	return true;
}

bool CustomI2C::isNacked()
{
	//read bit 3 of the STATE register
	if(Helper::readBit(&I2C1->STATE,3)==0x1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool CustomI2C::isBusy()
{
	//read bit 0 of the STATE register
	if(Helper::readBit(&I2C1->STATE,0)==0x1)
	{
		return true;
	}
	else
	{
		return false;
	}


}

bool CustomI2C::isDataValid()
{
	//read bit 8 of the STATUS register
	if(Helper::readBit(&I2C1->STATUS,8)==0x1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
