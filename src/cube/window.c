/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/02 20:23:25 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <stdint.h>

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	render_background(int color)
{
	int	i;
	int	j;

	if (!cub()->mlx_ptr)
		return (1);
	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
			mlx_pixel_put(cub()->mlx_ptr, cub()->win_ptr, j++, i, color);
		++i;
	}
	return (0);
}

int	destroy_window(void)
{
	// destroy_image();
	mlx_destroy_window(cub()->mlx_ptr, cub()->win_ptr);
	mlx_destroy_display(cub()->mlx_ptr);
	free(cub()->mlx_ptr);
	free_cub();
	exit(0);
}

void	moves(int keycode)
{
	// if (field()->moves == 0)
	// 	field()->moves = 1;
	// display();
	if (keycode == ESC)
		destroy_window();
	// else if (keycode == W || keycode == UP)
	// 	move_up();
	// else if (keycode == S || keycode == DOWN)
	// 	move_down();
	// else if (keycode == D || keycode == RIGHT)
	// 	move_right();
	// else if (keycode == A || keycode == LEFT)
	// 	move_left();
}

int	build_window(void)
{
	void	*window;
	int		color;

	cub()->mlx_ptr = mlx_init();
	if (!cub()->mlx_ptr)
		return (1);
	window = mlx_new_window(cub()->mlx_ptr, W_WIDTH, W_HEIGHT, "cub3D");
	cub()->win_ptr = window;
	if (!cub()->win_ptr)
	{
		mlx_destroy_display(cub()->mlx_ptr);
		free(cub()->mlx_ptr);
		return (1);
	}
	// get_image();
	// put_image();
	color = encode_rgb(190, 190, 255);
	render_background(color);
	// mlx_loop_hook(cub()->mlx_ptr, render_background(color), cub());
	mlx_hook(cub()->win_ptr, 2, 1L, (void *) moves, cub());
	mlx_hook(cub()->win_ptr, 17, 0L, \
			(int (*)(void))destroy_window, cub());
	mlx_loop(cub()->mlx_ptr);
	return (0);
}