/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:32:19 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/17 21:14:56 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	draw_minimap(t_image *img, int p_y, int p_x, int color);
static void	render_player(t_image *img, float x, float y);

int	render_minimap(t_image *img)
{
	t_pix_pos	p;

	p.y = 0;
	while (p.y <= parse()->map_height)
	{
		p.x = 0;
		while (p.x < (int)ft_strlen(parse()->map[p.y]))
		{
			if (parse()->map[p.y][p.x] == '1')
				draw_minimap(img, p.y, p.x, 1515552);
			if (parse()->map[p.y][p.x] == '0' || \
				is_player(parse()->map[p.y][p.x]))
				draw_minimap(img, p.y, p.x, 8421504);
			if (is_player(parse()->map[p.y][p.x]))
				render_player(img, (p.x + 0.5), (p.y + 0.5));
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
	t_pix_pos	p;
	int			x_end;
	int			y_end;
	int			scale;

	scale = 12;
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

static void	draw_line(float p_y, float p_x, float scale, t_image *img)
{
	t_line		line;

	line.x0 = p_x * scale;
	line.y0 = p_y * scale;
	line.x1 = p_x + cos(player_direction()) * 2;
	line.x1 *= scale;
	line.y1 = p_y + sin(player_direction()) * 2;
	line.y1 *= scale;
	brasenham(line, img, 16519760);
}

// static void	draw_rays(float p_y, float p_x, float scale, t_image *img)
// {
// 	int			i;
// 	int			num_rays;
// 	t_line		ray;
// 	t_pix_pos	*rays;
// 	// t_raycast	*rays;

// 	num_rays = parse()->map_width / 2;
// 	rays = malloc(num_rays * sizeof(t_pix_pos));
// 	if (!rays)
// 		exit(1);
// 	i = 0;
// 	while (i < num_rays)
// 	{
// 		rays[i].x = i;
// 		rays[i].y = i;
// 		ray.x0 = p_x * scale;
// 		ray.y0 = p_y * scale;
// 		ray.x1 = rays[i].x * scale;
// 		ray.y1 = rays[i].y * scale;
// 		brasenham(ray, img, 2293538);
// 		i++;
// 	}
// }

/** WORKING***
 * Draws the player's position on the minimap.
 * The player's position is scaled and represented with a specific color.
 *
 * @param img - A pointer to the img structure.
 * @param y - Scaled Y-coordinate of the player's position.
 * @param x - Scaled X-coordinate of the player's position.
 */
static void	render_player(t_image *img, float x, float y)
{
	t_pix_pos	p;
	t_pix_pos	end;
	int			scale;

	scale = 12;
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
			draw_circle(p, 16519760, 2, img);
			draw_line(y, x, scale, img);
			// draw_rays(y, x, scale, img);
			p.x++;
		}
		p.y++;
	}
}
