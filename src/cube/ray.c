/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:38:23 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/06 07:52:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void  print_player(t_image *img);

void	draw_rectangle(t_image *img, int color, t_vt_f init, t_vt_f end)
{
	t_line	vector;

	vector.y0 = init.y;
	while (vector.y0 < end.y)
	{
		vector.x0 = init.x;
		while (vector.x0 < end.x)
		{
			if (vector.x0 < end.x - 1)
			{
				vector.x1 = vector.x0 + 1;
				vector.y1 = vector.y0;
				brasenham(vector, img, color);
			}
			if (vector.y0 < end.y - 1)
			{
				vector.x1 = vector.x0;
				vector.y1 = vector.y0 + 1;
				brasenham(vector, img, color);
			}
			vector.x0++;
		}
		vector.y0++;
	}
}

void  print_grid(t_image *img)
{
  for (int y = 0; y <= map()->map_height; y++)
  {
    for (int x = 0; x <= map()->map_width; x++)
    {
      // Calculating square coordinates
      t_vt_f top_left = {
        x * 12, // x
        y * 12 // y
      };
      t_vt_f bottom_right = {
        top_left.x + 12,
        top_left.y + 12
      };

      // t_vt_f top_left_p = {
      //   x * TILE_SIZE + TILE_SIZE / 2 , // x
      //   y * TILE_SIZE + TILE_SIZE / 2 // y
      // };
      // Drawing square
      if (map()->map[y][x] == '1') // If the cell is a wall
      {
        draw_rectangle(img, GREEN, top_left, bottom_right);
      }
      else
        draw_rectangle(img, BLACK, top_left, bottom_right);
      // if (is_player(map()->map[y][x]))
      //   print_player(img);
    }
  }
}

// void  set_grid_cell(t_image *img, int x, int y)
// {

//   (void)img;
//   // Converting pixel coordinates into tab coordinates
//   t_vt_d map_pos = {
//     x / TILE_SIZE, // x
//     y / TILE_SIZE // y
//   };
  // printf("x: %d, y: %d\n\n", map_pos.x, map_pos.y);
  
  // // Checking out of range coordinates
  // if (map_pos.x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
  //   return;

  // // Changing cell value according to mouse button
//   if (img->mouse_button == MOUSE_LEFT_BUTTON)
//     map()->map[map_pos.y][map_pos.x] = '1';
//   else if (img->mouse_button == MOUSE_RIGHT_BUTTON)
//     map()->map[map_pos.y][map_pos.x] = '0';
// }

void  print_player(t_cube *cube, t_image *img)
{
  t_vt_d  pos;
  
  // pos.x = cube->p->player_map.x;
  // pos.y = cube->p->player_map.y;
  pos.x = cube->p->pos.x;
  pos.y = cube->p->pos.y;
  for (int y = -2; y <2; y++)
  {
    for (int x = -2; x < 2; x++)
    {
     img_draw_pixel(img, pos.x + x, pos.y + y, PINK);
     }
  }
}

void	print_ray(t_cube *cube, t_image *img)
{
	t_vt_d	p1;
	t_vt_d	p2;

	p1.x = (int)cube->p->pos.x;
	p1.y = (int)cube->p->pos.y;
	p2.x = p1.x + 100 * cube->p->dir.x;
	p2.y = p1.y + 100 * cube->p->dir.y;
	ft_bresenham(img, p1, p2, WHITE);
}
