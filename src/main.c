#include "cubemx.h"

#include <stdbool.h>

#if 1
// Приложение обычного блинка на HAL

volatile bool keyPress = false;

int main()
{
    MX_Init();
    uint32_t delay = 500;
    while (1) {
        if (keyPress) {
            keyPress = false;
            delay = delay != 500 ? 500 : 100; 
        }

        HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
        HAL_Delay(delay);
    }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    UNUSED(GPIO_Pin);
    keyPress = true;
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
