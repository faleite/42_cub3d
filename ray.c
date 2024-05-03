#include <stdio.h>
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>

#define W_WIDTH 1280
#define W_HEIGHT 750

typedef struct s_cube {
	// MiniLibX
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_height;
	int		win_width;

	// Tab
	int  	**tab;
	int  	tab_width;
	int  	tab_height;
}			t_cube;

int render_next_frame(t_cube *img)
{

}

void my_mlx_pixel_put(t_cube *cube, int x, int y, int color)
{
  char *dst;

  dst = cube->addr + (y * cube->line_length + x * (cube->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

/**
 * 02: Tecla do teclado pressionada
 * 03: Tecla do teclado liberada
 * 04: Botão do mouse pressionado
 * 05: Botão do mouse liberado
 * 06: Movimento do mouse
 * 17: Clique na cruz vermelha na janela
*/
int  key_press(int keycode, t_struct *prg_struct)
{
  if (keycode < 200)
    prg_struct->keyboard[keycode] = 1;

  return (0);
}

int  key_release(int keycode, t_struct *prg_struct)
{
  if (keycode < 200)
    prg_struct->keyboard[keycode] = 0;

  return (0);
}

int init_tab(t_cube *cube)
{
  // Setting initial tab dimensions
  cube->tab_height = 15;
  cube->tab_width = 20;

  // Allocating tab
  cube->tab = malloc(sizeof(int *) * cube->tab_height);
  if (cube->tab == NULL) // Checking allocation error
    return (1);

  for (int y = 0; y < cube->tab_height; y++)
  {
    cube->tab[y] = malloc(sizeof(int) * cube->tab_width);
    if (cube->tab[y] == NULL) // Checking allocation error
      return (1);

    // Putting values in tab
    for (int x = 0; x < cube->tab_width; x++)
    {
      cube->tab[y][x] = (y % 2 + x) % 2;
    }
  }
  return (0);
}

void  print_grid(t_cube *cube)
{
  for (int y = 0; y < tab_height; y++)
  {
    for (int x = 0; x < tab_width; x++)
    {
      // Calculating square coordinates
      t_vector2_d top_left = {
        x * cube->cell_size, // x
        y * cube->cell_size // y
      };
      t_vector2_d bottom_right = {
        top_left.x + cube->cell_size,
        top_left.y + cube->cell_size
      };

      // Drawing square
      if (cube->tab[y][x] == 1) // If the cell is a wall
      {
        draw_rect_color(cube, top_left, bottom_right, PINK);
      }
    }
  }
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_cube img;
	mlx = mlx_init();
	mlx_loop_hook(mlx, &render_next_frame, &img);
	mlx_hook(mlx_win, 2, 0, key_press, &img);
//   mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "A simple window");
//   img.img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
//   img.addr = mlx_get_cube_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//   my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
//   mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

