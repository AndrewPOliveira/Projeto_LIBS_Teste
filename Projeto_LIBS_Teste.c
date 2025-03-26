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
#include "inc/button.h"
#include "inc/buzzer.h"


int main()
{
    stdio_init_all();

    display_init();
    display_clear();

    // print_text_display((char *[]){"text"}, 1);

    //pwm_init_buzzer(21);

    //marcha_imperial();

    button_init(BUTTON_A_PIN);
    button_init(BUTTON_B_PIN);

    // Configurar a interrupção no pino do botão
    // gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    // Configuração dos LEDs RGB como saída
    const uint BLUE_LED_PIN = 12;  // LED azul no GPIO 12
    const uint RED_LED_PIN = 13;   // LED vermelho no GPIO 13
    const uint GREEN_LED_PIN = 11; // LED verde no GPIO 11

    // Função para inicializar os LEDs
    gpio_init(RED_LED_PIN);
    gpio_init(GREEN_LED_PIN);
    gpio_init(BLUE_LED_PIN);

    gpio_set_dir(RED_LED_PIN, GPIO_OUT);
    gpio_set_dir(GREEN_LED_PIN, GPIO_OUT);
    gpio_set_dir(BLUE_LED_PIN, GPIO_OUT);

    // Inicialmente, desligar o LED RGB
    gpio_put(RED_LED_PIN, 0);
    gpio_put(GREEN_LED_PIN, 0);
    gpio_put(BLUE_LED_PIN, 1);

    while (true)
    {

        // Verifica se o botão B foi pressionado
        if (button_pressed(BUTTON_B_PIN))
        {
            printf("Botão B foi pressionado!\n");
            gpio_put(BLUE_LED_PIN, 0);  // Desliga o LED azul
            gpio_put(RED_LED_PIN, 0);   // Desliga o LED vermelho
            gpio_put(GREEN_LED_PIN, 1); // Liga o LED verde
        }

        // Verifica se o botão B foi solto
        if (button_released(BUTTON_A_PIN))
        {
            printf("Botão A solto!\n");
            gpio_put(RED_LED_PIN, 1);   // Liga o LED vermelho
            gpio_put(GREEN_LED_PIN, 0); // Desliga o LED verde
            gpio_put(BLUE_LED_PIN, 0);  // Desliga o LED azul
        }

        sleep_ms(50); // Pequeno delay para evitar leituras erradas
    }
}
