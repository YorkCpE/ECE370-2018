#include "em_device.h"
#include "em_chip.h"

#define RAM_SIZE_ADDRESS 0xFE081FAUL
#define PART_NUM_REG_ADDR 0xFE081FCUL
#define PART_FAMILY_REG_ADDR 0xFE081FEUL

int main(void)
{
  /* Chip errata */
  CHIP_Init();

  volatile uint32_t* ramSizePtr = (uint32_t*)RAM_SIZE_ADDRESS;
  volatile uint32_t* partNumPtr = (uint32_t*)PART_NUM_REG_ADDR;
  volatile uint32_t* partFamily = (uint32_t*)PART_FAMILY_REG_ADDR;

  unsigned int ram = *ramSizePtr;
  unsigned int partNum = *partNumPtr;
  unsigned int family = *partFamily;



  /* Infinite loop */
  while (1) {
  }
}
