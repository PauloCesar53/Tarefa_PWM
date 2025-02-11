/*
 *                    Funcionamento do programa 
 *O programa  inicialmente mostra o Servomotor na posição de 180°, por cinco segundos,
 posteriormente a posição é alterada para 90°, ficando por 5 segundos nessa posição, 
 depois  a posição é alterada para 0°, ficando  por 5 segundos nessa posição. 
 Após as etapas acima, o programa inicia o loop principal onde ocorre a mudança gradativa 
 do ângulo, inicialmente de  0° a 180°, e ao atingir essa posição retorna gradativamente 
 para 0°, repetindo este ciclo constantemente.  
*/
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

//#define PWM_GPIO 12 //apenas para teste no LED azul da BitDogLab (comentar linha 6 para usar essa)
#define PWM_GPIO 22 // Pino GPIO conectado ao servo motor
#define PWM_DIVISER 125 // Divisor de clock para 125 (125 MHz / 125 = 1 MHz)
#define WRAP_PERIOD 20000 // Período de 20 ms (20000 µs)

// Função para definir o  duty cycle
void duty_cycle_atual(uint slice, uint gpio_pin, uint duty) {
    pwm_set_gpio_level(gpio_pin, duty);// duty cicle  é duty / 20000 * 100%
}
//função para configurar o módulo PWM com frequência de 50 Hz
uint pwm_setup()
{
    gpio_set_function(PWM_GPIO, GPIO_FUNC_PWM); //habilitar o pino GPIO como PWM
    
    uint slice = pwm_gpio_to_slice_num(PWM_GPIO); //obter o canal PWM da GPIO
    
    pwm_set_clkdiv(slice, PWM_DIVISER); //define o divisor de clock do PWM

    pwm_set_wrap(slice, WRAP_PERIOD); //definir o valor de wrap

    pwm_set_enabled(slice, true); //habilita o pwm no slice correspondente
    return slice;// retorna o slice do gpio 22
}
int main() {
    stdio_init_all();

    uint slice=pwm_setup();

    // 1) Ajusta o ciclo ativo para 2400 µs (180°)
    duty_cycle_atual(slice, PWM_GPIO, 2400);
    sleep_ms(5000); // Aguarda 5 segundos

    // 2) Ajusta o ciclo ativo para 1470 µs (90°)
    duty_cycle_atual(slice, PWM_GPIO, 1470);
    sleep_ms(5000); // Aguarda 5 segundos

    // 3) Ajusta o ciclo ativo para 500 µs (0°)
    duty_cycle_atual(slice, PWM_GPIO, 500);
    sleep_ms(5000); // Aguarda 5 segundos

    // 4) Movimentação suave entre 0° e 180°
    uint add_duty = 500; // Começa em 0° (500 µs)
    int lado = 1;       // Direção do movimento (1 para aumentar, -1 para diminuir)

    while (true) {
        // Atualiza o ciclo ativo
        duty_cycle_atual(slice, PWM_GPIO, add_duty);

        // Ajusta o ciclo ativo em ±5 µs
        add_duty += 5 * lado;//5 para incremento recomendado 

        // Inverte a direção ao atingir os limites
        if (add_duty >= 2400) {
            lado = -1; // Move para 0°
        } else if (add_duty <= 500) {
            lado = 1; // Move para 180°
        }

        // Aguarda 10 ms para suavizar o movimento
        sleep_ms(10);//atraso recomendo para rotina
    }
    return 0;
}
