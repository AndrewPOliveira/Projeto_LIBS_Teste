#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "hardware/pio.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "inc/ssd1306.h"
#include "hardware/i2c.h"
#include "inc/display.h"
#include "tests/display_test.h"


int main()
{
    stdio_init_all();

    display_init();
    display_clear();

    while (true) {
        
        sleep_ms(1000);
    }
}
