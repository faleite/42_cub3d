/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/06 21:52:12 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Sets the color of a single pixel on the frame at the specified position 'p'.
 * It directly modifies the frame's memory to change the pixel color.
 *
 * @param frame - The frame where the pixel color is set.
 * @param p - The position (x, y) of the pixel to be colored.
 * @param color - The color value to be set for the pixel.
 */
// inline void	frame_draw_pixel(t_frame frame, t_pixel_pos p, int color)
// {
// 	*(int *)(frame.addr + 4 * (p.x + p.y * WIN_W)) = color;

// 	mlx_get_data_addr()
// }

int	destroy_window(void)
{
	// destroy_image();
	mlx_destroy_window(parse()->mlx_ptr, parse()->win_ptr);
	mlx_destroy_display(parse()->mlx_ptr);
	free(parse()->mlx_ptr);
	free_parse();
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

/**
 * Paints the ceiling and floor of the window with the specified colors.
 * 
 * @return 1 if the mlx_ptr is not initialized, 0 otherwise.
 */
int	paint_ceiling_floor(void)
{
	t_pix_pos	pos;

	pos.y = -1;
	if (!parse()->mlx_ptr)
		return (1);
	while (++pos.y < W_HEIGHT / 2)
	{
		pos.x = -1;
		while (++pos.x < W_WIDTH)
			mlx_pixel_put(parse()->mlx_ptr, parse()->win_ptr, \
						pos.x, pos.y, parse()->color_c);
	}
	while (pos.y < W_HEIGHT)
	{
		pos.x = -1;
		while (++pos.x < W_WIDTH)
			mlx_pixel_put(parse()->mlx_ptr, parse()->win_ptr, \
						pos.x, pos.y, parse()->color_f);
		++pos.y;
	}
	return (0);
}

/*
 altura (h) do mapa = end - start + 1
 largura (w) do mapa = maior linha do mapa
*/
int	render_cub3d(void)
{
	paint_ceiling_floor();
	render_minimap();
	// get_image();
	// put_image();
	return (0);
}

/**
 * Sets up the hooks for the window.
 * This function assigns the necessary hooks for the window events.
 */
void	get_hooks(void)
{
	mlx_loop_hook(parse()->mlx_ptr, &render_cub3d, parse());
	mlx_hook(parse()->win_ptr, 2, 1L, (void *) moves, parse());
	mlx_hook(parse()->win_ptr, 17, 0L, \
			(int (*)(void))destroy_window, parse());
}

int	build_window(void)
{
	void	*window;

	parse()->mlx_ptr = mlx_init();
	if (!parse()->mlx_ptr)
		return (1);
	window = mlx_new_window(parse()->mlx_ptr, W_WIDTH, W_HEIGHT, "cub3D");
	parse()->win_ptr = window;
	if (!parse()->win_ptr)
	{
		mlx_destroy_display(parse()->mlx_ptr);
		free(parse()->mlx_ptr);
		return (1);
	}
	get_hooks();
	mlx_loop(parse()->mlx_ptr);
	return (0);
}
