/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/18 16:12:16 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	keyboard(int keycode, t_data *data);

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
	mlx_hook(data.win_ptr, 2, 1L, (void *)keyboard, &data);
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
	draw_ceil_floor(&data->img);
	render_minimap(&data->img);
	render_player(&data->img);
	/* After render this function put image to window */
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->img.mlx_img, 0, 0);
	return (0);
}

// void	move_up(t_data *data)
// {
// 	t_pix_pos	map;
// 	t_pix_pos	new_pos;
// 	t_pix_pos	next_step;

// 	printf("Fisrt: y: %d, x: %d\n", plyer()->pos.y, plyer()->pos.x);
// 	new_pos = plyer()->pos;
// 	new_pos.x += cos(plyer()->rotation_angle) * plyer()->move_speed;
// 	new_pos.y += sin(plyer()->rotation_angle) * plyer()->move_speed;
// 	map.x = (new_pos.x / TILE_SIZE);
// 	map.y = (new_pos.y / TILE_SIZE);
// 	next_step.x = (new_pos.x + cos(plyer()->rotation_angle)
// 			* plyer()->move_speed) / TILE_SIZE;
// 	next_step.y = (new_pos.y + sin(plyer()->rotation_angle)
// 			* plyer()->move_speed) / TILE_SIZE;
// 	printf("Second: y: %d, x: %d\n", map.y, map.x);
// 	printf("Third: y: %d, x: %d\n", next_step.y, next_step.x);
// 	// printf("fild: %d\n", (plyer()->map[(int)map.y][(int)map.x]));
// 	if ((plyer()->map[(int)map.y][(int)map.x] != WALL)
// 		&& (plyer()->map[(int)next_step.y][(int)next_step.x] != WALL))
// 	{
// 		plyer()->pos = new_pos;
// 		// parse()->pos_x = new_pos.x;
// 		// parse()->pos_y = new_pos.y;
// 		render_cub3d(data);
// 	}
// }

void	keyboard(int keycode, t_data *data)
{
	// if (field()->moves == 0)
	// 	field()->moves = 1;
	// display();
	if (keycode == ESC)
		destroy_window(data);
	// else if (keycode == K_W || keycode == UP)
	// 	move_up(data);
	// else if (keycode == K_S || keycode == DOWN)
	// 	move_down();
	// else if (keycode == K_D || keycode == RIGHT)
	// 	move_right();
	// else if (keycode == K_A || keycode == LEFT)
	// 	move_left();
}

int	draw_ceil_floor(t_image *img)
{
	t_pix_pos	pos;

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
