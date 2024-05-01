#include <stdio.h>
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>

#define W_WIDTH 1280
#define W_HEIGHT 750

typedef struct s_data {
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
}			t_data;

int render_next_frame(t_data *img)
{

}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
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

int init_tab(t_data *data)
{
  // Setting initial tab dimensions
  data->tab_height = 15;
  data->tab_width = 20;

  // Allocating tab
  data->tab = malloc(sizeof(int *) * data->tab_height);
  if (data->tab == NULL) // Checking allocation error
    return (1);

  for (int y = 0; y < data->tab_height; y++)
  {
    data->tab[y] = malloc(sizeof(int) * data->tab_width);
    if (data->tab[y] == NULL) // Checking allocation error
      return (1);

    // Putting values in tab
    for (int x = 0; x < data->tab_width; x++)
    {
      data->tab[y][x] = (y % 2 + x) % 2;
    }
  }
  return (0);
}

void  print_grid(t_data *data)
{
  for (int y = 0; y < tab_height; y++)
  {
    for (int x = 0; x < tab_width; x++)
    {
      // Calculating square coordinates
      t_vector2_d top_left = {
        x * data->cell_size, // x
        y * data->cell_size // y
      };
      t_vector2_d bottom_right = {
        top_left.x + data->cell_size,
        top_left.y + data->cell_size
      };

      // Drawing square
      if (data->tab[y][x] == 1) // If the cell is a wall
      {
        draw_rect_color(data, top_left, bottom_right, PINK);
      }
    }
  }
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	mlx = mlx_init();
	mlx_loop_hook(mlx, &render_next_frame, &img);
	mlx_hook(mlx_win, 2, 0, key_press, &img);
//   mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "A simple window");
//   img.img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
//   img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//   my_mlx_pixel_put(&img, 100, 100, 0x00FF0000);
//   mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

