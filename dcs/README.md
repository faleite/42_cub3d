```bash
 ██████╗██╗   ██╗██████╗     ██████╗ ██████╗ 
██╔════╝██║   ██║██╔══██╗    ╚════██╗██╔══██╗
██║     ██║   ██║██████╔╝     █████╔╝██║  ██║
██║     ██║   ██║██╔══██╗     ╚═══██╗██║  ██║
╚██████╗╚██████╔╝██████╔╝    ██████╔╝██████╔╝
 ╚═════╝ ╚═════╝ ╚═════╝     ╚═════╝ ╚═════╝ 
```

<!-- * ### [Workflow](#workflow-1)
* ### [Study resources](#study-resources-1) -->

## Study resources
Resource | Source
-------- | ------
[Notion](https://martinxz.notion.site/Cube-3D-fc961ff69d23448383b40611bebe6ca8) | `Website`

## Workflow
<details>
  <summary>Expand here</summary>

### Task
#### [Engine RayCasting Manual do Codigo](https://editor.p5js.org/ManualDoCodigo/sketches/)

</details>

### Fixed bug with wall deformation

Fixed bug with wall deformation when passing close to it

Na linha que calcula a posição y inicial da textura, a largura da janela `(W_WIDTH)` é usada em vez da altura `(W_HEIGHT)`:

```c
1 // Em src/cube/render.c, dentro da função draw_wall
2 position_o.y = (pix.top - (W_WIDTH / 2) + (wall_height / 2)) * ratio;
```

Isso está incorreto. Como estamos calculando uma coordenada vertical (Y) da textura, a altura da janela `(W_HEIGHT)` deve ser usada. Esse erro causa uma distorção no mapeamento da textura: insignificante à distância, mas severa de perto, criando a curvatura em "V".

A solução é corrigir esse erro de digitação. substituir `W_WIDTH` por `W_HEIGHT` nessa linha.

```c
// file src/cube/render.c:                 
ratio = (double)texture_painter.height / wall_height;                                                  
position_o.x = ft_get_postion(cube, texture_painter);                                           
text_adrr = (int *)texture_painter.img.addr;                                                          
- position_o.y = (pix.top - (W_WIDTH / 2) + (wall_height / 2)) * ratio;     
+ position_o.y = (pix.top - (W_HEIGHT / 2) + (wall_height / 2)) * ratio;                   
if (position_o.y < 0)               
  position_o.y = 0;                                                                                            
while (pix.top < pix.bottom)
```

[↑ Index ↑](#mandatory-part)