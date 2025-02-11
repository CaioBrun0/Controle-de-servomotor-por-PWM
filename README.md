# Controle de Servo Motor e LED com PWM no Raspberry Pi Pico

## Descrição
Este projeto utiliza a Raspberry Pi Pico para controlar um servo motor e um LED via PWM (Pulse Width Modulation). O programa ajusta dinamicamente o duty cycle do PWM para alterar a posição do servo motor e a intensidade do LED.

## Hardware Utilizado
- Raspberry Pi Pico
- Servo motor
- LED azul
- Resistores e fios para conexões

## Configuração do PWM
O PWM é configurado para operar com:
- Frequência de clock reduzida por um divisor (`clk_div = 250`)
- Um período definido pelo `wrap = 9999`

As larguras de pulso definidas para o servo motor são:
- **12% (180°) - `duty_cycle_1`**
- **7,35% (90°) - `duty_cycle_2`**
- **2,5% (0°) - `duty_cycle_3`**

O LED também é controlado pelo mesmo sinal PWM.

## Funcionamento
1. O programa inicializa o PWM e define os pinos GPIO do servo motor e do LED.
2. Alterna entre três duty cycles fixos (12%, 7,35% e 2,5%) para testar o servo motor.
3. Entra em um loop que varia gradualmente o duty cycle entre os limites de 2,5% a 12%.

## Como Executar
1. Compile o código para a Raspberry Pi Pico.
2. Carregue o arquivo `.uf2` na Pico conectada via USB.
3. O servo motor e o LED iniciarão automaticamente o movimento.

## Dependências
- SDK do Raspberry Pi Pico
- Biblioteca `hardware/pwm.h`
- Biblioteca `pico/stdlib.h`

## Autor
Desenvolvido para estudos e aplicações práticas com Raspberry Pi Pico e controle de dispositivos via PWM.

