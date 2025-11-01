#include "cubemx.h"

#if 1
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
