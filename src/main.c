/*****************************************************************************/
/* Delay helper                                                              */
/*****************************************************************************/

/*****************************************************************************/
/* Includes                                                                  */
/*****************************************************************************/

/* Project headers */
#include <delay.h>

/* BSP headers */
#include <em_chip.h>
#include <em_cmu.h>

int main()
{
    CHIP_Init();

    Delay_Init();

    CMU_ClockEnable(cmuClock_GPIO, true);
    GPIO_PinModeSet(gpioPortD, 9, gpioModePushPull, 1);

    while (true)
    {
        GPIO_PinOutSet(gpioPortD, 9);
        Delay(1000);
        GPIO_PinOutClear(gpioPortD, 9);
        Delay(1000);
    }

    return 0;
}