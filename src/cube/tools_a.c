/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:34:03 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/17 19:49:37 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * * Sets the color of a single pixel on the frame at the specified 
 * position x and y. It directly modifies the frame's memory to change
 * the pixel color.
 *
 * @param img   The image to draw the pixel on.
 * @param x     The x-coordinate of the pixel.
 * @param y     The y-coordinate of the pixel.
 * @param color The color of the pixel.
 */
void	img_draw_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

int	destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_parse();
	free_map(plyer()->map);
	exit(0);
}

t_plyr	*plyer(void)
{
	static t_plyr	p;

	return (&p);
}

/*
	Brasenham's algorithme draws lines between two points
*/
void	brasenham(t_line line, t_image *img, int color)
{
	t_line	*tmp;

	tmp = &line;
	tmp->delta_x = (tmp->x1 - tmp->x0);
	tmp->delta_y = (tmp->y1 - tmp->y0);
	tmp->max = ft_max(ft_mod(tmp->delta_x), ft_mod(tmp->delta_y));
	tmp->delta_x /= tmp->max;
	tmp->delta_y /= tmp->max;
	while ((int)(tmp->x0 - tmp->x1) || (int)(tmp->y0 - tmp->y1))
	{
		img_draw_pixel(img, tmp->x0, tmp->y0, color);
		tmp->x0 += tmp->delta_x;
		tmp->y0 += tmp->delta_y;
	}
}

void	draw_circle(t_pix_pos center, int color, int radius, t_image *img)
{
	int	radius_squared;
	int	x;
	int	y;

	radius_squared = pow(radius, 2);
	x = center.x - radius;
	y = center.y - radius;
	while (y <= center.y + radius)
	{
		while (x <= center.x + radius)
		{
			if ((pow(x - center.x, 2) + pow(y - center.y, 2)) <= radius_squared)
				img_draw_pixel(img, x, y, color);
			x++;
		}
		y++;
		x = center.x - radius;
	}
}

// void	clear_frame(t_image frame)
// {
// 	char	*pixel;
// 	int		total;
// 	int		i;

// 	pixel = frame.addr;
// 	total = W_WIDTH * W_HEIGHT;
// 	i = 0;
// 	while (i < total)
// 	{
// 		*(int *)pixel = 0;
// 		pixel += 4;
// 		i++;
// 	}
// }