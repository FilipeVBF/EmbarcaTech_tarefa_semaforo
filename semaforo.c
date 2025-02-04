#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13

static volatile uint semaforo = 1;

// Função para inicializar o pino do LED
void init_gpio_led(int led_pin, bool is_output, bool state) {
    gpio_init(led_pin);                                         // Inicializa o pino do LED
    gpio_set_dir(led_pin, is_output ? GPIO_OUT : GPIO_IN);      // Configura o pino como saída ou entrada
    gpio_put(led_pin, state);                                   // Garante que o LED inicie apagado
}

// Função para acender o LED
void semaforo_led(int led_pin, int led_pin2, int led_pin3) {
    gpio_put(led_pin, true);
    gpio_put(led_pin2, false);
    gpio_put(led_pin3, false);
}

// Função de callback que será chamada a cada 3 segundo
bool repeating_timer_callback(struct repeating_timer *t) {
    switch (semaforo)
    {
    case 0:
        // Apaga todos os LEDs e acende o LED vermelho.
        semaforo_led(LED_PIN_RED, LED_PIN_YELLOW, LED_PIN_GREEN);
        semaforo++;
        break;

    case 1:
        // Apaga os LEDs e acende o LED amarelo.
        semaforo_led(LED_PIN_YELLOW, LED_PIN_RED, LED_PIN_GREEN);
        semaforo++;
        break;

    case 2:
        // Apaga os LEDs e acende o LED verde.
        semaforo_led(LED_PIN_GREEN, LED_PIN_RED, LED_PIN_YELLOW);
        semaforo = 0;
        break;
    
    default:
        break;
    }

    return true;
}

int main() {
    // Inicializa a comunicação serial, permitindo o uso de funções como printf.
    stdio_init_all();

    // Inicializando pino do LED RGB
    init_gpio_led(LED_PIN_RED, true, true);
    init_gpio_led(LED_PIN_YELLOW, true, false);
    init_gpio_led(LED_PIN_GREEN, true, false);

    // Declaração de uma estrutura de temporizador de repetição.
    // Esta estrutura armazenará informações sobre o temporizador configurado.
    struct repeating_timer timer;

    // Configura o temporizador para chamar a função de callback a cada 3 segundo.
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop infinito que mantém o programa em execução.
    while (true) {
        // Pausa de 1 segundos para reduzir o uso da CPU.
        sleep_ms(1000);
        printf("rotina de repetição\n");
    }
    return 0;
}
