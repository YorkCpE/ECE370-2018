/*
 * main.cpp
 *
 *  Created on: Jun 19, 2018
 *      Author: Jason Forsyth
 */

#include <em_device.h>
#include <em_chip.h>
#include <em_cmu.h>
#include <em_emu.h>
#include <bsp.h>
#include <bsp_trace.h>
#include <em_gpio.h>
#include <em_timer.h>

#include <stdint.h>
#include <stdbool.h>

#include "GPIO.h"
#include "Helper.h"


/**************************************************************************//**
 * @brief  Main function
 *****************************************************************************/
int main(void)
{
	/* Chip errata */
	CHIP_Init();

	//enable the clock for the High-Frequency Peripherals
	CMU_ClockEnable(cmuClock_HFPER, true);

	//enable GPIO clock
	CMU_ClockEnable(cmuClock_GPIO,true);

	//enable USART1 clock
	CMU_ClockEnable(cmuClock_USART1,true);


	///////////////////BEGIN USART0 CONFIGURATION///////////////////

	/**
	 * Begin configuration of USART1
	 * Set for 9600 8N1
	 */

	//Double check that USART frequency is 14MHz with CMU_ClockFreqGet

	//Select an oversample rate and assume f_clock=14MHz. Calculate the
	//required DIV value. Set in correct location in CLKDIV
	/**
	 * Your code here
	 */

	//Configure FRAME register for the number of
	//data bits
	/**
	 * Your code here
	 */

	//Configure FRAME register for the number of
	//stop bits
	/**
	 * Your code here
	 */

	//Configure FRAME register for the number of
	//parity bits
	/**
	 * Your code here
	 */

	//Use ROUTE register to select Location #1 (PD0 and PD1)
	/**
	 * Your code here
	 */

	//Enable TX Pin in ROUTE register
	/**
	 * Your code here
	 */

	//Enable RX Pin in ROUTE register
	/**
	 * Your code here
	 */

	//Enable TXEN and TXEN in CMD
	/**
	 * Your code here
	 */

	///////////////////END USART0 CONFIGURATION///////////////////

	///////////////////BEGIN GPIO CONFIGURATION///////////////////

	//Configure the TX Pin (PD0) on Location #1 as an output
	/**
	 * Your code here
	 */


	//Configure the RX Pin (PD1) on Location #1 as an input
	/**
	 * Your code here
	 */

	///////////////////END GPIO CONFIGURATION///////////////////

	///////////////////BEGIN USART LOOP BACK///////////////////

	/**
	 * Task 1: Transmit a single byte
	 */

	//create a uint8_t variable and set it equal to some number of your choice
	uint8_t txNum;

	//write your variable into the TXDATA register of the USART
	/**
	 * Your code here
	 */

	//poll on the RXDATAV bit in STATUS (indicates there's data in the buffer)
	//wait for data to be received
	/**
	 * Your code here
	 */

	//Read data out of RXDATA. Should read the same value as your "number" above
	uint8_t rxNum;

	//Do not modify this block as it will be used to check your solution
	bool task1Success=false;
	if(rxNum==txNum)
	{
		task1Success=true;
	}

	/**
	 * Task 2: Transmit multiple bytes. Write to TXDATA twice in a row
	 * to send two packets. You should receive two bytes as well.
	 */

	//create a uint8_t array with two elements. Set each element to an
	//arbitrary number
	uint8_t array[];

	//write your variable into the TXDATA register of the USART
	/**
	 * Your code here
	 */

	//write the second variable into TXDOUBLE but left shifted by
	//8 bits. So array[1]<<8
	/**
	 * Your code here
	 */

	//poll on the RXFULL bit in STATUS (indicates the FIFO is full)
	//wait for data to be received
	/**
	 * Your code here
	 */

	//Read data out RX FIFO. Read once from RXDATA and then from RXDOUBLE.
	//These values should correspond to the two values you sent.
	uint8_t value1;

	uint8_t value2;

	//Do not modify this block as it will be used to check your solution
	bool task2Success=false;
	if(value1==array[0] && value2==array[1])
	{
		task2Success=true;
	}

	//Do not modify this block as it will be used to check your solution
	if(task1Success==true && task2Success==true)
	{
		//then you've completed the lab
	}

	/**
	 * Leave this code below to give the processor "something" to do.
	 * If there's an empty loop is may optimize away lines of code from above.
	 * Just keep it here for a sanity check.
	 */
	int counter=0;
	while(1)
	{
		counter++;
	}
}

