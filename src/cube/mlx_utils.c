/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:34:03 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/11 09:09:08 by marvin           ###   ########.fr       */
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

unsigned int	wall_draw_pixel(t_texture texture, int x, int y)
{
	return (*(int *)(texture.img.addr + 4 * (x + y * texture.width)));
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
	destroy_image(cube);
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	mlx_destroy_image(cube->mlx_ptr, cube->img.mlx_img);
	mlx_destroy_display(cube->mlx_ptr);
	free(cube->mlx_ptr);
	free_data(cube);
	free_parse();
	exit(0);
}
