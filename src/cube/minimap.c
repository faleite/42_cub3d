/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:32:19 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/24 18:23:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	draw_minimap(t_image *img, int p_y, int p_x, int color);
static void	draw_player(t_data *data, float x, float y);

int	render_minimap(t_image *img)
{
	t_vt_d	p;

	p.y = 0;
	while (p.y <= parse()->map_height)
	{
		p.x = 0;
		while (p.x < (int)ft_strlen(parse()->map[p.y]))
		{
			if (parse()->map[p.y][p.x] == '1')
				draw_minimap(img, p.y, p.x, DARK);
			if (parse()->map[p.y][p.x] == '0' || \
				is_player(parse()->map[p.y][p.x]))
				draw_minimap(img, p.y, p.x, GRAY);
			p.x++;
		}
		p.y++;
	}
	return (0);
}

int	render_player(t_data *data)
{
	t_vt_d	p;

	p.y = 0;
	while (p.y <= parse()->map_height)
	{
		p.x = 0;
		while (p.x < (int)ft_strlen(parse()->map[p.y]))
		{
			if (is_player(parse()->map[p.y][p.x]))
				draw_player(data, (p.x + 0.5), (p.y + 0.5));
			p.x++;
		}
		p.y++;
	}
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

	scale = MM_SCALE;
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
static void	draw_player(t_data *data, float x, float y)
{
	t_vt_d	p;
	t_vt_d	end;
	int		scale;

	scale = MM_SCALE;
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
			draw_circle(p, RED, 2, &data->img);
			draw_line(y, x, &data->img, data->plyr->angle);
			p.x++;
		}
		p.y++;
	}
}
