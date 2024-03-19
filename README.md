```bash
 ██████╗██╗   ██╗██████╗     ██████╗ ██████╗ 
██╔════╝██║   ██║██╔══██╗    ╚════██╗██╔══██╗
██║     ██║   ██║██████╔╝     █████╔╝██║  ██║
██║     ██║   ██║██╔══██╗     ╚═══██╗██║  ██║
╚██████╗╚██████╔╝██████╔╝    ██████╔╝██████╔╝
 ╚═════╝ ╚═════╝ ╚═════╝     ╚═════╝ ╚═════╝ 
```

*This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you'll have to find your way.*

 Skills | Grade |
:------:|:-----:|
[**Graphics**] [**Imperative programming**] [**Rigor**] [**Algorithms & AI**] | **Subscribed :atom:**
<!-- **:white_check_mark: 100%** -->

<!-- * ### [Introduction]() -->
* ### [Mandatory part](#mandatory-part-1)
<!-- * ### [Mind Map](./dcs/readme/mind_map.md) -->
<!-- * ### [Mind Map](#mind-map-1) -->
<!-- * ### [Overview](./dcs/readme/bash_brief.md) -->
<!-- * ### [Overview](#overview-1) -->
<!-- * ### [Usage]() -->
* ### [Study resources](#study-resources-1)
<!-- * ### [Tools]() -->
* ### [Workflow](#workflow-1)

## Mandatory part
<!-- *Subject Comentado** -->

Program name | cub3D
------------ | ---------
Turn in files| All your files
Makefile     | all, clean, fclean, re, bonus
Arguments    | a map in format *.cub
External functs.| open, close, read, write, printf, malloc, free, perror, strerror, exit
External functs.| All functions of the math library (-lm man man 3 math)
External functs.| All functions of the MinilibX
Libft authorized | Yes
Description  | You must create a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective.  You have to create this representation using the Ray-Casting principles mentioned earlier.

### Regras para implementação do projeto
- Você deve usar o miniLibX. Ou a versão que está disponível no sistema operacional ou de suas fontes. Se você optar por trabalhar com as fontes, precisará aplicar as mesmas regras para o seu libft que as escritas acima na parte de Instruções Comuns.
- O gerenciamento da sua janela deve permanecer suave: mudando para outro ganho, minimizando, etc.
- Exiba diferentes texturas de parede (a escolha é sua) que variam dependendo de qual lado a parede está voltada (Norte, Sul, Leste, Oeste).
- Seu programa deve ser capaz de definir as cores do piso e do teto para duas diferentes.
- O programa exibe a imagem em uma janela e respeita as seguintes regras:
  - As teclas de seta esquerda e direita do teclado devem permitir que você olhe para a esquerda e para a direita no labirinto. 
  - As teclas W, A, S e D devem permitir que você mova o ponto de vista pelo labirinto. 
  - Pressionar ESC deve fechar a janela e sair do programa de forma limpa. 
  - Clicar na cruz vermelha na moldura da janela deve fechar a janela e sair do programa de forma limpa. - O uso de imagens do minilibX é altamente recomendado.
- Seu programa deve ter como primeiro argumento um arquivo de descrição de cena com a extensão .cub.
  - O mapa deve ser composto por apenas 6 caracteres possíveis: **0** para um espaço vazio, **1** para uma parede e **N,S, E** ou **W** para a posição inicial e orientação de desova do jogador.\
  Este é um mapa simples e válido:
  ```
  111111
  100101
  101001
  1100N1
  111111
  ```
  - O mapa deve ser fechado/cercado por paredes, caso contrário, o programa deve retornar um erro. 
  - Exceto pelo conteúdo do mapa, cada tipo de elemento pode ser separado por uma ou mais linhas vazias. - Exceto pelo conteúdo do mapa, que sempre tem que ser o último, cada tipo de elemento pode ser definido em qualquer ordem no arquivo. 
  - Exceto pelo mapa, cada tipo de informação de um elemento pode ser separado por um ou mais espaços. 
  - O mapa deve ser analisado como aparece no arquivo. Os espaços são uma parte válida do mapa e depende de você lidar. Você deve ser capaz de analisar qualquer tipo de mapa, desde que respeite as regras do mapa.
  - Cada elemento (exceto o mapa) primeira informação é o identificador de tipo (composto por um ou dois caracteres), seguido por todas as informações específicas para cada objeto em uma ordem estrita, como:
    - Textura Norte: `NO ./path_to_the_north_texture` 
      - identificador: `NO` 
      - caminho para a textura norte 
    - Textura Sul: `SO ./path_to_the_south_texture`
      - identificador: `SO` 
      - caminho para a textura sul
    - Textura Oeste: `WE ./path_to_the_west_texture`
      - identificador: `WE` 
      - caminho para a textura oeste
    - Textura Leste: `EA ./path_to_the_east_texture`
      - identificador: `EA` 
      - caminho para a textura leste
    - Textura do chão: `F 220,100,0`
      - identificador: `F` 
      - Cores R, G, B na faixa [0,255], no formato `0,255,255`
    - Textura do teto: `C 225,30,0`
      - identificador: `C` 
      - Cores R, G, B na faixa [0,255], no formato `0,255,255`
    - Exemplo da parte obrigatória com uma cena minimalista .cub:
    ```
    NO ./path_to_the_north_texture
    SO ./path_to_the_south_texture
    WE ./path_to_the_west_texture
    EA ./path_to_the_east_texture
    F 220,100,0
    C 225,30,0
    1111111111111111111111111
    1000000000110000000000001
    1011000001110000000000001
    1001000000000000000000001
    111111111011000001110000000000001
    100000000011000001110111111111111
    11110111111111011100000010001
    11110111111111011101010010001
    11000000110101011100000010001
    10000000000000001100000010001
    10000000000000001101010010001
    11000001110101011111011110N0111
    11110111 1110101 101111010001
    11111111 1111111 111111111111
    ```
  - Se qualquer configuração incorreta de qualquer tipo for encontrada no arquivo, o programa deve sair corretamente e retornar "Erro\n" seguido de uma mensagem de erro explícita de sua escolha.

[↑ Index ↑](#mandatory-part)

## Workflow
<details>
  <summary>Expand here</summary>

### Check map
- [ ] Mapa tem que estar cercado por paredes (1)
  - [ ] Cada liha do mapa tem que iniciar e fechar com 1
  - [ ] Primeira e ultima linha tem que ser 1 e ' '
- [ ] Checar se tem mais de uma posicao inicial
- [ ] Caracteres validos: 0, 1, N, S, E, W
  - [ ] Checar cerco de caracteres validos
    - [ ] ' ' tem que estar cercado por 1 e ' '
    - [ ] 0 tem que estar cercado por 1, 0, N, S, E e W
    - [ ] N, S, E e W tem que estar cercado por 1 e 0
- [ ] Checar quando ha linhas maiores ou menores no inicio e fim da linha
  - [ ] Se a linha anterior for menor que a atual, a parte maior da linha\
    atual so pode conter 1 e ' '
  - [ ] Se a linha anterior for maior que a atual, a parte maior da linha\
    anterior so pode conter 1 e ' '

## Elementos da cena

1. Encontar primeira e ultima linha (parede) do map
2. Checar linhas **NO**, **SO**, **WE**, **EA**
3. Checar linhas **F** e **C**

## Docker
- [Dockerfile](./dcs/Dockerfile)
 - `docker build -t cub3d-env .`
 - `docker run -it --rm -v $(pwd):/home/dev -w /home/dev cub3d-env`
- XQuartz config:
  - Put in file ~/.zshrc: `export DISPLAY=:0`
  - Open XQuartz
  - Exec on mac terminal `/opt/X11/bin/xhost +127.0.0.1`


## Minimap
```
NO ./img/blocks/block.xpm
SO ./img/blocks/command.xpm
WE ./img/blocks/chiseled.xpm
EA ./img/blocks/composter.xpm
F 117, 142, 79
C 135, 245, 251

1111111111111111111111111     1111111111111111
1000000000000000000000001     1000000000000001
1000000000000000000000001     1111111111111101
1000000000000000000000001111111000000000000001
1000000000000000000000000000001000000000000111
10000000000000000000000000000010000000000001
100000000000000S0000000011111110011111111111
1000000000000000000111111     1001
10000000000000000001          1001
1111100000000000000111111111111001
1111100000000000000000000000000001
1111100000000000000000000000000001
1111111111111111111111111111111111
```
</details>

## Study resources
- [MLX42](https://github.com/codam-coding-college/MLX42)
- [Resources jotavare 42 Porto](https://github.com/jotavare/42-resources?tab=readme-ov-file#04-cub3d)
- [Formula](https://lodev.org/cgtutor/raycasting.html)
- [Raycasting](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [Video Vetores](https://youtube.com/playlist?list=PLLFRf_pkM7b7UEvWsq6KuANoOYELMnd_y&si=e0ZaC3PnAJQeOEEc)
- [Engine de Raycasting](https://youtube.com/playlist?list=PLLFRf_pkM7b6rBRoTOW64NKdltCLQNpW5&si=WxdLm-7wXSuAkzdU)

[↑ Index ↑](#mandatory-part)