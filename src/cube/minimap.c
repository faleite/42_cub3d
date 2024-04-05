/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:32:19 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/05 21:48:28 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	draw_minimap(int p_y, int p_x, int color);

int	render_minimap(void)
{
	t_pix_pos	p;

	p.y = cub()->start_map - 1;
	while (++p.y <= cub()->end_map)
	{
		p.x = -1;
		while (++p.x < (int)ft_strlen(cub()->scene[p.y]))
		{
			if (cub()->scene[p.y][p.x] == '1')
				draw_minimap(p.y, p.x, 4473924);
			if (cub()->scene[p.y][p.x] == '0')
				draw_minimap(p.y, p.x, 9211020);
		}
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
			mlx_pixel_put(cub()->mlx_ptr, cub()->win_ptr, \
						p.x, p.y, color);
			p.x++;
		}
		p.y++;
	}
	return (0);
}
