/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:38:23 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/05 16:19:38 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void  set_grid_cell(t_image *img, int x, int y)
{

  (void)img;
  // Converting pixel coordinates into tab coordinates
  t_vt_d map_pos = {
    x / TILE_SIZE, // x
    y / TILE_SIZE // y
  };
  printf("x: %d, y: %d\n\n", map_pos.x, map_pos.y);
  
  // // Checking out of range coordinates
  // if (map_pos.x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
  //   return;

  // // Changing cell value according to mouse button
  if (img->mouse_button == MOUSE_LEFT_BUTTON)
    map()->map[map_pos.y][map_pos.x] = '1';
  else if (img->mouse_button == MOUSE_RIGHT_BUTTON)
    map()->map[map_pos.y][map_pos.x] = '0';
}
