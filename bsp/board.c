#include "board.h"

#include "cubemx.h"

#include <lame/port/PinImpl.h>
#include <lame/utils/option_exist.h>

// #define OLD_BLUE_PILL

#if !OPTION_EXIST(OLD_BLUE_PILL)
#define LED_Pin       GPIO_PIN_2
#define LED_GPIO_Port GPIOB
#else
#define LED_Pin       GPIO_PIN_13
#define LED_GPIO_Port GPIOC
#endif

Event keyPress;
Led   led;

static void ledInit()
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    if (LED_GPIO_Port == GPIOC) {
        __HAL_RCC_GPIOC_CLK_ENABLE();
    }
    else {
        __HAL_RCC_GPIOB_CLK_ENABLE();
    }

    GPIO_InitStruct.Pin   = LED_Pin;
    GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull  = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_GPIO_Port, &GPIO_InitStruct);

    static struct PinImpl pinImpl;
    pinImpl.GPIO_Pin = LED_Pin;
    pinImpl.GPIOx    = LED_GPIO_Port;
    led              = Led_Create(&pinImpl, false);
}

void board_init()
{
    Event_Init(&keyPress);
    MX_Init();

    ledInit();
}

void Error_Handler(void)
{
    __disable_irq();
    while (1) {
    }
}
