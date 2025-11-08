#include "board.h"

#include "cubemx.h"

#include <lame/port/Pin_Impl.h>

Event keyPress;
Led   led;

void board_init()
{
    Event_Init(&keyPress);

    MX_Init();

    static struct Pin_Impl pinImpl;

    pinImpl.GPIO_Pin = LED_Pin;
    pinImpl.GPIOx    = LED_GPIO_Port;

    led = Led_Create(&pinImpl, false);
}

void Error_Handler(void)
{
    __disable_irq();
    while (1) {
    }
}
