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
<!-- * ### [Mandatory part](#mandatory-part-1) -->
<!-- * ### [Mind Map](./dcs/readme/mind_map.md) -->
<!-- * ### [Mind Map](#mind-map-1) -->
<!-- * ### [Overview](./dcs/readme/bash_brief.md) -->
<!-- * ### [Overview](#overview-1) -->
<!-- * ### [Usage]() -->
* ### [Study resources](#study-resources-1)
<!-- * ### [Tools]() -->
<!-- * ### [Workflow]() -->

<details>
  <summary>Workflow</summary>

## Parser

1. Encontar primeira e ultima linha (parede) do map
2. Checar linhas **NO**, **SO**, **WE**, **EA**
3. Checar linhas **F** e **C**
4. Checar linhas do mapa
  - Checar se tem caracteres invalidos
  - Flud fill nao e preciso para checar se o mapa é valido

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
- [Resources jotavare 42 Porto](https://github.com/jotavare/42-resources?tab=readme-ov-file#04-cub3d)
- [Formula](https://lodev.org/cgtutor/raycasting.html)
- [Raycasting](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [Video Vetores](https://youtube.com/playlist?list=PLLFRf_pkM7b7UEvWsq6KuANoOYELMnd_y&si=e0ZaC3PnAJQeOEEc)
- [Engine de Raycasting](https://youtube.com/playlist?list=PLLFRf_pkM7b6rBRoTOW64NKdltCLQNpW5&si=WxdLm-7wXSuAkzdU)
