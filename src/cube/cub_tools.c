/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:34:03 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/09 19:37:25 by faaraujo         ###   ########.fr       */
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
	exit(0);
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
