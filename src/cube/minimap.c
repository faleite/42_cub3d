/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:32:19 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/04 17:49:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	draw_minimap(t_image *img, int p_y, int p_x, int color);

int	render_minimap(t_cube *cube)
{
	t_vt_d	p;
	t_image *img;

	img = &cube->img;

	p.y = 0;
	while (p.y <= parse()->map_height)
	{
		p.x = 0;
		while (p.x < (int)ft_strlen(parse()->map[p.y]))
		{
			if (parse()->map[p.y][p.x] == '1')
				draw_minimap(img, p.y, p.x, BLACK);
			if (parse()->map[p.y][p.x] == '0' || \
				is_player(parse()->map[p.y][p.x]))
				draw_minimap(img, p.y, p.x, GRAY);
			p.x++;
		}
		p.y++;
	}
	draw_player(cube, (cube->p->pos.x / 64.0), (cube->p->pos.y / 64.0));
	return (0);
}

/*
 Modified: MINIMAP_SCALE for scale
 Look for this: mlx_int_anti_resize_win();
*/
static int	draw_minimap(t_image *img, int p_y, int p_x, int color)
{
	t_vt_d	p;
	int		x_end;
	int		y_end;
	int		scale;

	scale = MAP_SCALE;
	if (parse()->map_height > 20 || parse()->map_width > 40)
		scale /= 2;
	x_end = p_x * scale + scale;
	y_end = p_y * scale + scale;
	p.y = p_y * scale;
	while (p.y < y_end)
	{
		p.x = p_x * scale;
		while (p.x < x_end)
		{
			img_draw_pixel(img, p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
	return (0);
}

/** WORKING***
 * Draws the player's position on the minimap.
 * The player's position is scaled and represented with a specific color.
 *
 * @param img - A pointer to the img structure.
 * @param y - Scaled Y-coordinate of the player's position.
 * @param x - Scaled X-coordinate of the player's position.
 */


void	draw_player(t_cube *cube, float x, float y)
{
	t_vt_d	p;
	t_vt_d	end;
	int		scale;

	t_vt_d line_view;

	t_vt_d pos;

	pos.x = cube->p->pos.x;
	pos.y = cube->p->pos.y;
	
    line_view.x = cube->p->pos.x +  (cos(cube->p->angle) * 80);
    line_view.y = cube->p->pos.y  + (sin(cube->p->angle) * 80);
	scale = MAP_SCALE;
	if (parse()->map_height > 20 || parse()->map_width > 40)
		scale /= 2;
	end.x = x * scale + scale / 5;
	end.y = y * scale + scale / 5;
	p.y = y * scale - scale / 5;
	while (p.y < end.y)
	{
		p.x = x * scale - scale / 5;
		while (p.x < end.x)
		{
			img_draw_pixel(&cube->img, pos.x, pos.y, PINK);
			p.x++;
		}
		p.y++;
	}
	
    ft_bresenham(&cube->img, pos, line_view, RED);

}
