/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/09 20:15:37 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	moves(int keycode, t_data *data);
int		render_cub3d(t_data *data);

int	build_window(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, W_WIDTH, W_HEIGHT, "cub3D");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, W_WIDTH, W_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
					&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &render_cub3d, &data);
	mlx_hook(data.win_ptr, 2, 1L, (void *)moves, &data);
	mlx_hook(data.win_ptr, 17, 0L, (void *)destroy_window, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

/*
 altura (h) do mapa = end - start + 1
 largura (w) do mapa = maior linha do mapa
*/
int	render_cub3d(t_data *data)
{
	if (!data->mlx_ptr)
		return (1);
	paint_ceiling_floor(&data->img);
	render_minimap(&data->img);

	/* After render this function put image to window */
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->img.mlx_img, 0, 0);
	return (0);
}

void	moves(int keycode, t_data *data)
{
	// if (field()->moves == 0)
	// 	field()->moves = 1;
	// display();
	if (keycode == ESC)
		destroy_window(data);
	// else if (keycode == W || keycode == UP)
	// 	move_up();
	// else if (keycode == S || keycode == DOWN)
	// 	move_down();
	// else if (keycode == D || keycode == RIGHT)
	// 	move_right();
	// else if (keycode == A || keycode == LEFT)
	// 	move_left();
}
