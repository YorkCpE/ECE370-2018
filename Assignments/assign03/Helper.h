/*
 * Helper.h
 *
 *  Created on: Jun 7, 2017
 *      Author: Jason Forsyth
 */

#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_


/**
 * Helper function take from em_bus.h
 */
unsigned int readBit(volatile const uint32_t *addr, uint32_t bit)
{
	return ((*addr)>>bit) & 0x1;
}

/**
 * Helper function take from em_bus.h
 */
void writeBit(volatile uint32_t *addr, uint32_t bitPos, uint32_t val)
{
	uint32_t tmp = *addr;
	*addr = (tmp & ~(1 << bitPos)) | ((val & 0x1) << bitPos);
	return;
}


#endif /* SRC_HELPER_H_ */
