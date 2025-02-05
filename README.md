# Semáforo com Temporizador Periódico

## Descrição do Projeto

Este projeto consiste na implementação de um semáforo utilizando o microcontrolador Raspberry Pi Pico W. A transição das cores do semáforo (vermelho, amarelo e verde) é controlada por um temporizador periódico configurado para alternar o estado dos LEDs a cada 3 segundos.

## Funcionalidades

- Alterna automaticamente entre os LEDs vermelho, amarelo e verde seguindo um ciclo de 3 segundos para cada cor.
- Utiliza a função add_repeating_timer_ms() da ferramenta Pico SDK para o controle temporizado.
- Exibe mensagens na porta serial a cada segundo para monitoramento da execução do programa.

## Componentes Utilizados

- Microcontrolador Raspberry Pi Pico W
- 03 LEDs (Vermelho, Amarelo e Verde)
- 03 Resistores
- Software de simulação Wokwi
- BitDogLab (para experimentos com LED RGB nos GPIOs 11, 12 e 13)

## Requisitos Técnicos

- O acionamento dos LEDs deve iniciar na cor vermelha, alterando para amarela e, em seguida, verde.
- O temporizador deve ser ajustado para um atraso de 3 segundos (3.000 ms).
- A mudança de estado dos LEDs deve ser implementada na função de callback do temporizador repeating_timer_callback().
- A rotina principal deve imprimir uma mensagem a cada segundo pela porta serial.
- O código deve ser testado utilizando a ferramenta BitDogLab com um LED RGB nos GPIOs 11, 12 e 13.

## Instrução de Uso

1. Clone o repositório do projeto:
https://github.com/FilipeVBF/EmbarcaTech_tarefa_semaforo.git
2. Importe a pasta do projeto para o ambiente de desenvolvimento do Pico SDK.
3. Carregue o programa no Raspberry Pi Pico W
4. Compile o código
5. Para execução na simulação do Wokwi, abra o arquivo diagram.json e inicie a simulação
6. Conecte o hardware conforme a configuração sugerida.
7. Abra um monitor serial para visualizar as mensagens enviadas a cada segundo.
8. Observe o ciclo de transição dos LEDs seguindo a sequência vermelho -> amarelo -> verde.
