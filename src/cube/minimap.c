/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:32:19 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/11 15:15:02 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	draw_minimap(t_image *img, int p_y, int p_x, int color);

int	render_minimap(t_cube *cube)
{
	t_vector_2int	p;
	t_image			*img;

	img = &cube->img;
	p.y = 0;
	while (p.y <= parse()->map_height)
	{
		p.x = 0;
		while (p.x < (int)ft_strlen(parse()->map[p.y]))
		{
			if (parse()->map[p.y][p.x] == '1')
				draw_minimap(img, p.y, p.x, BROWN);
			if (parse()->map[p.y][p.x] == '0' || \
				is_player(parse()->map[p.y][p.x]))
				draw_minimap(img, p.y, p.x, WOOD);
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
	t_vector_2int	p;
	int				x_end;
	int				y_end;
	int				scale;

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

void	draw_player(t_cube *cube, float x, float y)
{
	t_vector_2int	p;
	t_vector_2int	end;
	int				scale;

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
			img_draw_pixel(&cube->img, p.x, p.y, ORANGE);
			p.x++;
		}
		p.y++;
	}
}
