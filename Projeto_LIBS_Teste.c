#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "hardware/pio.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "hardware/i2c.h"

#include "pico/stdlib.h"

#include "inc/ssd1306.h"
#include "inc/display.h"


int main()
{
    stdio_init_all();

    display_init();
    display_clear();

    print_text_display((char *[]){"text"}, 1);

    while (true) {
        
        sleep_ms(1000);
    }
}
