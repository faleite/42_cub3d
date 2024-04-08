/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:32:19 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/08 22:31:44 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		render_player(t_img *img, float p_y, float p_x);
static int	draw_minimap(t_img *img, int p_y, int p_x, int color);

int	render_minimap(t_img *img)
{
	t_pix_pos	p;

	p.y = 0;
	while (p.y <= parse()->map_height)
	{
		p.x = 0;
		while (p.x < (int)ft_strlen(parse()->map[p.y]))
		{
			if (parse()->map[p.y][p.x] == '1')
				draw_minimap(img, p.y, p.x, 4473924);
			if (parse()->map[p.y][p.x] == '0' || \
				is_player(parse()->map[p.y][p.x]))
				draw_minimap(img, p.y, p.x, 9211020);
			if (is_player(parse()->map[p.y][p.x])) // Temp...
				render_frame_player(img, (float)(p.y + 0.5), \
									(float)(p.x + 0.5));
			p.x++;
		}
		p.y++;
	}
	return (0);
}

static int	draw_minimap(t_img *img, int p_y, int p_x, int color)
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
 * @param p_y - Scaled Y-coordinate of the player's position.
 * @param p_x - Scaled X-coordinate of the player's position.
 */
void	render_player(t_img *img, float p_y, float p_x)
{
	t_pix_pos	p;
	int			x_end;
	int			y_end;

	x_end = p_x * MINIMAP_SCALE + MINIMAP_SCALE / 3;
	y_end = p_y * MINIMAP_SCALE + MINIMAP_SCALE / 3;
	p.y = p_y * MINIMAP_SCALE - MINIMAP_SCALE / 3;
	while (p.y < y_end)
	{
		p.x = p_x * MINIMAP_SCALE - MINIMAP_SCALE / 3;
		while (p.x < x_end)
		{
			img_draw_pixel(img, p.x, p.y, 13395456);
			p.x++;
		}
		p.y++;
	}
}

int	paint_ceiling_floor(t_img *img)
{
	t_pix_pos	pos;

	pos.y = -1;
	while (++pos.y < W_HEIGHT / 2)
	{
		pos.x = -1;
		while (++pos.x < W_WIDTH)
			img_draw_pixel(img, pos.x, pos.y, parse()->color_c);
	}
	while (pos.y < W_HEIGHT)
	{
		pos.x = -1;
		while (++pos.x < W_WIDTH)
			img_draw_pixel(img, pos.x, pos.y, parse()->color_f);
		++pos.y;
	}
	return (0);
}
