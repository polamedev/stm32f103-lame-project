#include "cubemx.h"
#include "interrupt.h"

#include <lame/drivers/Pin.h>
#include <lame/drivers/Pin_Impl.h>

#include <stdbool.h>

#if 1
// Приложение обычного блинка на Lame Pin

int main()
{
    interrupt_init();
    MX_Init();

    struct Pin_Impl pin;
    pin.GPIO_Pin = LED_Pin;
    pin.GPIOx    = LED_GPIO_Port;

    uint32_t delay = 500;

    while (1) {
        if (Event_Take(&keyPress)) {
            delay = delay != 500 ? 500 : 100;
        }

        Pin_Toggle(&pin);
        HAL_Delay(delay);
    }
}

#endif

#if 0
// Приложение обычного блинка на HAL

int main()
{
    interrupt_init();
    MX_Init();
    uint32_t delay = 500;
    while (1) {
        if (Event_Take(&keyPress)) {
            delay = delay != 500 ? 500 : 100;
        }

        HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
        HAL_Delay(delay);
    }
}

#endif

#if 0
// Приложение обычного блинка на HAL
int main()
{
    MX_Init();
    while (1) {
        HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
        HAL_Delay(500);
    }
}
#endif

void Error_Handler(void)
{
    __disable_irq();
    while (1) {
    }
}
