#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define servo 22
#define LED 12
#define duty_cycle_1 12 
#define duty_cycle_2 7.35 
#define duty_cycle_3 2.5 
#define wrap 9999
#define clk_div 250 
float duty_cycle = 2.5;
float step = 0.025;


//Inicialização do PWM
void pwm_setup(){
    //Colocando o servo motor como PWM
    gpio_set_function(servo, GPIO_FUNC_PWM);
    uint slice_servo = pwm_gpio_to_slice_num(servo);
    pwm_set_clkdiv(slice_servo, clk_div);
    pwm_set_wrap(slice_servo, wrap);
    pwm_set_enabled(slice_servo, true);

    //Colocando o LED azul como PWM
    gpio_set_function(LED, GPIO_FUNC_PWM);
    uint slice_LED = pwm_gpio_to_slice_num(LED);
    pwm_set_clkdiv(slice_LED, clk_div);
    pwm_set_wrap(slice_LED, wrap);
    pwm_set_enabled(slice_LED, true);

}


//Atualiza o duty cycle
void define_duty_cycle(float duty_cycle){
    uint int_cycle = (uint16_t)((duty_cycle / 100) * wrap);
    pwm_set_gpio_level(servo, int_cycle);
    pwm_set_chan_level(pwm_gpio_to_slice_num(LED), PWM_CHAN_A, int_cycle);
}

int main()
{
    stdio_init_all();
    sleep_ms(1000); //Espera 1 segundo antes de iniciar
    pwm_setup();

    //Proposições 2, 3 e 4 ta tarefa:
    define_duty_cycle(duty_cycle_1); //Deixa o servo motor e o LED no duty cycle de 12% (180°)
    sleep_ms(5000);
    define_duty_cycle(duty_cycle_2); //Deixa o servo motor e o LED no duty cycle de 7,35% (90°)
    sleep_ms(5000);
    define_duty_cycle(duty_cycle_3); //Deixa o servo motor e o LED no duty cycle de 2,5% (0°)
    sleep_ms(5000);

    uint up_down = 1; 

    while (true) {
        if (up_down){
            duty_cycle = duty_cycle + step;
            if (duty_cycle >= duty_cycle_1){
                up_down = 0;
            }
        } else {
            duty_cycle = duty_cycle - step;
            if (duty_cycle <= duty_cycle_3){
                up_down = 1;
            }
        }

        define_duty_cycle(duty_cycle);
        sleep_ms(10);
        
    }   
}