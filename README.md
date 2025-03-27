# Projeto LIBS Teste

<img src="https://github.com/user-attachments/assets/13c50e37-8d64-4bce-8d36-23cbdecc2178" width="400">

## Descrição
Este repositório contém um jogo da memória, desenvolvido para testar bibliotecas criadas por alunos do VIRTUS-CC para a BitDogLab V6.0. O jogo utiliza um display, botões e sinais sonoros com os buzzers, permitindo a verificação do funcionamento e desempenho das bibliotecas em um ambiente prático e interativo.

## Objetivo
O principal objetivo deste projeto é fornecer uma plataforma para testar e validar bibliotecas desenvolvidas pelos alunos, garantindo sua compatibilidade e eficiência em sistemas embarcados.

## Componentes Utilizados
- **Display**: Exibição das informações do jogo (Aryelson - [Display OLED](https://github.com/aryelson1/Display_Oled_BitDogLab.git))

- **Botões**: Interação do usuário com o jogo (Guilherme Santos Silva - [Botões](https://github.com/aryelson1/Buzzer_BitDogLab.git))

- **Buzzer**: Geração de sinais sonoros para feedback ao jogador (Aryelson - [Buzzer](https://github.com/GuilhermexL/Botoes_BitDogLab.git))

## Estrutura do Projeto
O repositório está organizado da seguinte forma:
- `src/` - Código-fonte do jogo e integração com as bibliotecas
- `inc/` - Bibliotecas em teste
- `docs/` - Documentação e materiais de referência

## Funcionamento do Jogo

O jogo consiste em uma sequência de sons emitidos pelos buzzers, cada um associado a um botão específico. O jogador deve repetir a sequência corretamente pressionando os botões correspondentes.

1 - O jogo inicia quando o jogador pressiona qualquer botão.

2 - O display exibe mensagens orientando o jogador.

3 - O nível começa em 1 e aumenta a cada rodada bem-sucedida.

4 - A cada nível, uma nova sequência de botões é gerada aleatoriamente.

5 - O jogador deve pressionar os botões na ordem correta.

6 - Caso erre, o jogo termina e toca a "Marcha Imperial". Caso acerte, o nível aumenta e o jogo continua.

