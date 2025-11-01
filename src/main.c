#include "cubemx.h"
#include "interrupt.h"

#include <stdbool.h>

#if 1
// Приложение обычного блинка на HAL

int main()
{
    MX_Init();
    uint32_t delay = 500;
    while (1) {
        if (keyPress) {
            keyPress = false;
            delay    = delay != 500 ? 500 : 100;
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
