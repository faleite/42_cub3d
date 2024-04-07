/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:32:19 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/07 18:37:59 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	draw_minimap(int p_y, int p_x, int color);

int	render_minimap(void)
{
	t_pix_pos	p;

	p.y = 0;
	while (p.y <= parse()->map_height)
	{
		p.x = 0;
		while (p.x < (int)ft_strlen(parse()->map[p.y]))
		{
			if (parse()->map[p.y][p.x] == '1')
				draw_minimap(p.y, p.x, 4473924);
			if (parse()->map[p.y][p.x] == '0')
				draw_minimap(p.y, p.x, 9211020);
			if (is_player(parse()->map[p.y][p.x])) // Temp...
				draw_minimap(p.y, p.x, 13395507);
			p.x++;
		}
		p.y++;
	}
	return (0);
}

static int	draw_minimap(int p_y, int p_x, int color)
{
	t_pix_pos	p;
	int			x_end;
	int			y_end;

	x_end = p_x * MINIMAP_SCALE + MINIMAP_SCALE;
	y_end = p_y * MINIMAP_SCALE + MINIMAP_SCALE;
	p.y = p_y * MINIMAP_SCALE;
	while (p.y < y_end)
	{
		p.x = p_x * MINIMAP_SCALE;
		while (p.x < x_end)
		{
			mlx_pixel_put(parse()->mlx_ptr, parse()->win_ptr, \
						p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
	return (0);
}
