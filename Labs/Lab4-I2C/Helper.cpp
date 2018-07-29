/*
 * Helper.cpp
 *
 *  Created on: Jul 28, 2018
 *      Author: jforsyth
 */

#include "Helper.h"

/**
 * Helper function to read single bit from from a register
 * @param addr Pointer to register
 * @param bitPos Bit position to be written
 * @return Value of the selected bit
 */
unsigned int Helper::readBit(volatile const uint32_t *addr, uint32_t bitPos)
{
	return ((*addr)>>bitPos) & 0x1;
}

/**
 * Helper function to write a value to a specific bit in a register
 * @param addr Pointer to register
 * @param bitPos Bit position to be written
 * @param val Value to be written into position. Should be 0x0 or 0x1
 */
void Helper::writeBit(volatile uint32_t *addr, uint32_t bitPos, uint32_t val)
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
void Helper::modifyBitField(volatile uint32_t *addr, uint32_t mask, uint32_t value, uint32_t bitPos)
{
	*addr = (*addr & ~(mask << bitPos))|(value << bitPos);
}

/**
 * Dummy/bad delay function. Will wait num*1000 cycles
 * @param num Number of cycles to delay
 */
void Helper::delay(int num)
{
	int counter=0;
	for(int i=0;i<num*1000;i++)
	{
		counter++;
	}
}
