/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:24:05 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/25 16:58:05 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_player_screen(t_data *data)
{
	t_vt_d	p;

	p.y = 0;
	while (p.y < TILE_SIZE / 2)
	{
		p.x = 0;
		while (p.x < TILE_SIZE / 2)
		{
			img_draw_pixel(&data->img, data->plyr->pos.x + p.x,\
							data->plyr->pos.y + p.y, RED);
			p.x++;
		}
		p.y++;
	}
}

void	draw_line_screen(int p_y, int p_x, t_image *img, double dir)
{
	t_line	line;

	line.x0 = p_x + TILE_SIZE / 4;
	line.y0 = p_y + TILE_SIZE / 4;
	line.x1 = p_x + cos(dir) * 200;
	line.y1 = p_y + sin(dir) * 200;
	brasenham(line, img, WHITE);
}

void	hit_wall(t_data *data, double new_x, double new_y)
{
	t_vt_d	p;

	p.x = floor(new_x / TILE_SIZE);
	p.y = floor(new_y / TILE_SIZE);
	if (map()->map[p.y][p.x] != '0')
	{
		printf("WALL\n");
		data->cast->flag = 1;
	}
}
