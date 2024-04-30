/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/29 21:14:18 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	keyboard(int keycode, t_data *data);

int	build_window(t_data data)
{
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
	mlx_hook(data.win_ptr, 2, 1L, (void *)keyboard, &data);
	mlx_hook(data.win_ptr, 17, 0L, (void *)destroy_window, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

/* TAREFA */
// plane	dir		plane


// 		   plyer

/*
 altura (h) do mapa = end - start + 1
 largura (w) do mapa = maior linha do mapa
*/
int	render_cub3d(t_data *data)
{
	if (!data->mlx_ptr)
		return (1);
	clear_img(data->img);
	draw_ceil_floor(&data->img);

	// (Use Key for activate the minimap)
	render_minimap(&data->img);
	// render_player(data);
	raycasting(data, &data->img);

	// draw_line_screen(data->plyr->pos.y, data->plyr->pos.x,
	//  				&data->img, data->plyr->angle);
	// draw_player_screen(&data->img, data->plyr->pos.x, data->plyr->pos.y);

	/* After render this function put image to window */
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->img.mlx_img, 0, 0);
	return (0);
}

void	keyboard(int keycode, t_data *data)
{
	if (keycode == ESC)
		destroy_window(data);
	else if (keycode == K_W || keycode == UP)
		move_up(data);
	else if (keycode == K_S || keycode == DOWN)
		move_down(data);
	else if (keycode == K_D)
		move_right(data);
	else if (keycode == K_A)
		move_left(data);
	else if (keycode == RIGHT)
		move_rotate(data, -1);
	else if (keycode == LEFT)
		move_rotate(data, 1);
}

int	draw_ceil_floor(t_image *img)
{
	t_vt_d	pos;

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
