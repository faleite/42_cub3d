/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/31 21:55:04 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

	cub()->mlx_ptr = mlx_init();
	if (!cub()->mlx_ptr)
		return (1);
	window = mlx_new_window(cub()->mlx_ptr, 1440, 830, "cub3D");
	cub()->win_ptr = window;
	if (!cub()->win_ptr)
	{
		mlx_destroy_display(cub()->mlx_ptr);
		free(cub()->mlx_ptr);
		return (1);
	}
	// get_image();
	// put_image();
	mlx_hook(cub()->win_ptr, 2, 1L, (void *) moves, cub());
	mlx_hook(cub()->win_ptr, 17, 0L, \
			(int (*)(void))destroy_window, cub());
	mlx_loop(cub()->mlx_ptr);
	return (0);
}