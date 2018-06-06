/*
 * Helper.h
 *
 *  Created on: Jun 7, 2017
 *      Author: Jason Forsyth
 */

#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_


/**
 * Helper function to read single bit from from a register
 * @param addr Pointer to register
 * @param bitPos Bit position to be written
 * @return Value of the selected bit
 */
unsigned int readBit(volatile const uint32_t *addr, uint32_t bitPos)
{
	return ((*addr)>>bitPos) & 0x1;
}

/**
 * Helper function to write a value to a specific bit in a register
 * @param addr Pointer to register
 * @param bitPos Bit position to be written
 * @param val Value to be written into position. Should be 0x0 or 0x1
 */
void writeBit(volatile uint32_t *addr, uint32_t bitPos, uint32_t val)
{
	uint32_t tmp = *addr;
	*addr = (tmp & ~(1 << bitPos)) | ((val & 0x1) << bitPos);
	return;
}

/**
 * Helper function to modify an arbitrary bit field in a register
 * @param addr Pointer to register
 * @param mask Bitmask corresponding to the field that is modified (0x1, 0x3, 0xF...etc.)
 * @param value Value that should be written into the field. Must be same bit width as mask.
 * @param bitPos Lower bit position of field to be modified
 */
void modifyBitField(volatile uint32_t *addr, uint32_t mask, uint32_t value, uint32_t bitPos);

#endif /* SRC_HELPER_H_ */
