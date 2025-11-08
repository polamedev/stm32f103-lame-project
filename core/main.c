#include "bsp/board.h"

#include <lame/device/Led.h>

int main()
{
    board_init();

    Led_SetBlinkCount(led, 1);
    Led_StartBlink(led);

    while (1) {
        Led_Task();
        if (Event_Take(&keyPress)) {
            unsigned newCount = Led_GetBlinkCount(led) + 1;
            if (newCount > 5) {
                newCount = 1;
            }
            Led_SetBlinkCount(led, newCount);
        }
    }
}
