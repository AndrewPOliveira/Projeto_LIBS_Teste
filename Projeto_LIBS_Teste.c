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

#define ARRAY_SIZE 50



int main()
{
    // Get seed
    srand(time_us_32()); 

    bool bool_sequence[ARRAY_SIZE];
    int  button_sequence[ARRAY_SIZE];

    // Fill the array with random sequence
    for (int i = 0; i < ARRAY_SIZE; i++) {
        bool_sequence[i] = rand() % 2;  // Generate random 0 or 1
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        // True maps buzzer A with button A 
        if(bool_sequence[i]){
            button_sequence[i] = BUTTON_A_PIN;
        } else { // False maps buzzer B with button B 
            button_sequence[i] = BUTTON_B_PIN;
        }
    }

    stdio_init_all();

    display_init();
    display_clear();
    

    pwm_init_buzzer(BUZZER_PIN);
    pwm_init_buzzer(BUZZER_PIN2);

    button_init(BUTTON_A_PIN);
    button_init(BUTTON_B_PIN);

    // Configurar a interrupção no pino do botão
    gpio_set_irq_enabled_with_callback(BUTTON_B_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);
    gpio_set_irq_enabled_with_callback(BUTTON_A_PIN, GPIO_IRQ_EDGE_FALL, true, &button_callback);

    int game_level = 1;
    int count = 0;
    bool button_a_pressed = false;
    bool button_b_pressed = false;

    print_text_display((char *[]){"O jogo vai comecar", "Preste atencao"}, 2);
    sleep_ms(2000); 
    display_clear();

    while (true)
    {   

        count = 0; // Zero counter every game  
        char string [10];
        sprintf(string, "Nivel %d", game_level);
        print_text_display((char *[]){"Ouca bem", string}, 2);
        for(int i=0; i<game_level; i++){
            if(bool_sequence[i]){
                playTone(BUZZER_PIN, 294, 500);
                sleep_ms(1000);
            } else {
                playTone(BUZZER_PIN2, 330, 500);
                sleep_ms(1000);
            }
        }

        for(int j=0; j<game_level; j++){
            
            button_a_pressed = false;
            button_b_pressed = false;
            display_clear();
            print_text_display((char *[]){"Pressione", "o botao certo"}, 2);
            // Wait untill one of the buttons to be pressed
            while (!button_a_pressed || !button_b_pressed) {
                button_a_pressed = button_pressed(BUTTON_A_PIN);
                button_b_pressed = button_pressed(BUTTON_B_PIN);
                if(button_a_pressed || button_b_pressed){
                    break;
                }
                sleep_ms(10);  
            }


            if(button_a_pressed){
                if(button_sequence[j] == BUTTON_A_PIN){
                    // Correct 
                    display_clear();
                    count += 1;
                    char str[7];
                    sprintf(str, "%d de %d", count, game_level);
                    display_clear();
                    print_text_display((char *[]){"Botao certo", str}, 2);
                } else {
                    // Wrong 
                    display_clear();
                    print_text_display((char *[]){"Botao errado", " ", "Voce perdeu"}, 3);
                    sleep_ms(3000);
                    break;
                }
            } else if (button_b_pressed) {
                if(button_sequence[j] == BUTTON_B_PIN){
                    // Correct 
                    display_clear();
                    count += 1;
                    char str[7];
                    sprintf(str, "%d de %d", count, game_level);
                    print_text_display((char *[]){"Botao certo", str}, 2);
                } else {
                    // Wrong 
                    display_clear();
                    print_text_display((char *[]){"Botao errado", " ", "Voce perdeu"}, 3);
                    sleep_ms(3000);
                    break;
                }
            }

            // Wait 1s untill next button ask to be presssed 
            sleep_ms(1000);

        }

        // Aumenta o nivel se acertar todas
        if(count == game_level){
            game_level += 1; 
        }
        display_clear();
        sleep_ms(50);
    }
}
