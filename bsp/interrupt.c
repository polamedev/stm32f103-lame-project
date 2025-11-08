#include "board.h"

#include <cubemx.h>

/**
 * Генерацию обработчиков прерываний можно выборочно отключаться в cubemx, тогда их можно определять в этом файле  
 */

void EXTI0_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(KEY_Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    UNUSED(GPIO_Pin);
    Event_Set(&keyPress);
}
