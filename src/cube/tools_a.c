/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:34:03 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/06 19:42:46 by faaraujo         ###   ########.fr       */
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

void	clear_img(t_image img)
{
	char	*pixel;
	int		total;
	int		i;

	pixel = img.addr;
	total = W_WIDTH * W_HEIGHT;
	i = -1;
	while (++i < total)
	{
		*(int *)pixel = 0;
		pixel += 4;
	}
}

int	destroy_window(t_cube *cube)
{
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	mlx_destroy_image(cube->mlx_ptr, cube->img.mlx_img);
	mlx_destroy_display(cube->mlx_ptr);
	free(cube->mlx_ptr);
	free_data(cube);
	free_parse();
	exit(0);
}

void	draw_circle(t_vt_d center, int color, int radius, t_image *img)
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
