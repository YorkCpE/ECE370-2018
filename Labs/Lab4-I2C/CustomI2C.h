/*
 * I2C.h
 *
 *  Created on: Jul 28, 2018
 *      Author: jforsyth
 */

#ifndef USER_SRC_I2C_H_
#define USER_SRC_I2C_H_

#include <stddef.h>
#include <stdint.h>

#include "em_i2c.h"
#include "em_gpio.h"

/**
 * Enumerate the possible states of the I2C bus. Function call getI2CState()
 * will return one of these enumerations
 * IDLE: No Transmission is being performed
 * WAIT: Waiting for Idle state
 * START: Start Bit was sent/received
 * ADDR: Bus address was sent/received
 * ADDRACK: NACK/ACK was sent/received following recent ADRR transmission
 * DATA: Data was sent/received
 * DATAACK: NACK/ACK was sent/received following recent DATA transmission
 * UNKNOWN: This state is not possible. Added as fail safe.
 */
enum I2C_State {IDLE, WAIT, START, ADDR, ADDRACK, DATA, DATAACK, UNKNOWN};

class CustomI2C {
public:

	/**
	 * Virtual Destructor. Nothing to see here.
	 */
	virtual ~CustomI2C();

	/**
	 * Get handle to CustomI2C instance
	 * @return Pointer to CustomI2C singleton
	 */
	static CustomI2C* getInstance();

	/**
	 * Write to an internal register of an i2c device
	 * @param i2cAddress Bus address of device to be written to
	 * @param internalRegAddr Internal address of register on device
	 * @param value Data to be written into the internal register
	 * @return True if successful, False if NACKED on ADRR or DATA
	 */
	bool writeRegister(uint8_t i2cAddress, uint8_t internalRegAddr, uint8_t value);

	/**
	 * Read from an internal register of an i2c device
	 * @param i2cAddress Bus address of device to be read from
	 * @param internalRegAddr Internal address of register on device
	 * @param rtr Pointer to byte where returned/read value will be stored
	 * @return True if successful, False if NACKED on ADDR or DATA
	 */
	bool readRegister(uint8_t i2cAddress, uint8_t internalRegAddr, uint8_t* rtr);

private:
	/**
	 * Default constructor. Nothing to see here. Private
	 * so can only be invoked by this class
	 */
	CustomI2C();

	/**
	 * Setup all clocks associated with GPIO and i2C
	 */
	void setupClocks();

	/**
	 * Setup all GPIO needed for i2c. Use i2c #1 Location #0
	 */
	void setupGPIO();

	/**
	 * Configure I2C1 for 50KHz (approx.) operation.
	 */
	void setupI2C();


	/**
	 * Determine whether data is valid in the I2C receive buffer
	 * @return True if valid data in i2C receive buffer
	 */
	bool isDataValid();

	/**
	 * Determine whether the I2C bus is busy or not
	 * @return True if bus is busy, false otherwise
	 */
	bool isBusy();

	/**
	 * Determine whether recent ADDR/DATA transaction was NACKED
	 * @return True if recent data/address transmission was NACKED
	 */
	bool isNacked();

	/**
	 *Get the current state of the I2C bus as I2C_State Enum
	 * @return Current state of the I2C bus
	 */
	I2C_State getI2CState();


	/**
	 * Singleton of CustomI2C. Everyone gets a handle here.
	 */
	static CustomI2C singleton;
};

#endif /* USER_SRC_I2C_H_ */
