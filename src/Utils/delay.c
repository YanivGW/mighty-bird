/*****************************************************************************/
/* Delay helper                                                              */
/*****************************************************************************/

/*****************************************************************************/
/* Includes                                                                  */
/*****************************************************************************/

/* Own header */
#include "delay.h"

/* BSP headers */
#include "em_cmu.h"
#include "em_emu.h"

/*****************************************************************************/
/* Variables                                                                 */
/*****************************************************************************/

volatile uint32_t msTickCount; /* Counts 1ms time ticks */

/*****************************************************************************/
/* Interface functions                                                       */
/*****************************************************************************/

/******************************************************************************
* @brief
*    Sets up the SysTick timer for 1ms interrupts and initializes and starts
*    the RTC timer
*
* @return
*    Returns zero on OK, non-zero otherwise
 *****************************************************************************/
uint32_t Delay_Init(void)
{
  uint32_t stat;
  uint32_t ticks;

  /* Setup SysTick Timer for 1 msec interrupts  */
  ticks = CMU_ClockFreqGet(cmuClock_CORE) / 1000;
  stat = SysTick_Config(ticks);

  return stat;
}

/******************************************************************************
* @brief
*    Interrupt Service Routine for system tick counter
*
* @return
*    None
 *****************************************************************************/
void SysTick_Handler(void)
{
  msTickCount++;

  return;
}

/******************************************************************************
* @brief
*    Delays number of msTick Systicks (1 ms)
*
* @param[in] ms
*    Number of ticks (ms) to delay
*
* @return
*    None
 ******************************************************************************/
void Delay(uint32_t ms)
{
  uint32_t curTicks;

  curTicks = msTickCount;
  while ( (msTickCount - curTicks) < ms ) {
    EMU_EnterEM1();
  }

  return;
}