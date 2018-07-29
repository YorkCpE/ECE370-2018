/*
 * Helper Class
 *
 * All helper functions turned into a class to avoid massive
 * include/linker errors and dependencies
 *
 *
 *  Created on: July 28, 2018
 *      Author: Jason Forsyth
 */

#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <stdint.h>


class Helper {
public:

	/**
	 * Helper function to modify an arbitrary bit field in a register
	 * @param addr Pointer to register
	 * @param mask Bitmask corresponding to the field that is modified (0x1, 0x3, 0xF...etc.)
	 * @param value Value that should be written into the field. Must be same bit width as mask.
	 * @param bitPos Lower bit position of field to be modified
	 */
	static void modifyBitField(volatile uint32_t *addr, uint32_t mask, uint32_t value, uint32_t bitPos);

	/**
	 * Helper function to write a value to a specific bit in a register
	 * @param addr Pointer to register
	 * @param bitPos Bit position to be written
	 * @param val Value to be written into position. Should be 0x0 or 0x1
	 */
	static void writeBit(volatile uint32_t *addr, uint32_t bitPos, uint32_t val);

	/**
	 * Helper function to read single bit from from a register
	 * @param addr Pointer to register
	 * @param bitPos Bit position to be written
	 * @return Value of the selected bit
	 */
	static unsigned int readBit(volatile const uint32_t *addr, uint32_t bitPos);

	/**
	 * Dummy/bad delay function. Will wait num*1000 cycles
	 * @param num Number of cycles to delay
	 */
	static void delay(int num);
};
#endif /* SRC_HELPER_H_ */

