#include "board.h"

#include "cubemx.h"

#include <lame/port/Pin_Impl.h>

Event keyPress;

static struct Pin_Impl pinImpl;
const Pin                    pin = &pinImpl;

void board_init()
{
    Event_Init(&keyPress);

    MX_Init();

    pinImpl.GPIO_Pin = LED_Pin;
    pinImpl.GPIOx    = LED_GPIO_Port;
}

