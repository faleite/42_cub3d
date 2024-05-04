/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/04 18:09:28 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	keyboard(int keycode, t_cube *cube);
void	keyboard_release(int key, t_cube *cube);

// void	ft_angle_normal(double *angle)
// {
// 	double mod_angle = 2 * M_PI;

// 	*angle = fmod(*angle, mod_angle);
// 	if (*angle < 0)
// 	*angle += mod_angle;
// }
// int	mouse_click_motion(int x, int y, t_cube *cube)
// {
// 	printf("mouse X:%d:\n", x);
// 	printf("mouse Y:%d:\n", y);

// 	t_vt_d mouse_pos;

// 	mouse_pos.x = x - cube->p->pos.x;
// 	mouse_pos.y = y - cube->p->pos.y;

// 	printf("mouse X:%d:\n", x);
// 	printf("mouse Y:%d:\n", y);

// 	cube->p->dir.y = atan2(mouse_pos.y, mouse_pos.x);
// 	ft_angle_normal(&cube->p->dir.y);
// 	return (0);
// }

int	mouse_click(int button, int x, int y, t_image *img)
{
    img->mouse_button = button;
    set_grid_cell(img, x, y);
	return (1);
}

int	build_window(t_cube cube)
{
	cube.mlx_ptr = mlx_init();
	if (!cube.mlx_ptr)
		return (1);
	cube.win_ptr = mlx_new_window(cube.mlx_ptr, W_WIDTH, W_HEIGHT, "cub3D");
	if (!cube.win_ptr)
	{
		free(cube.win_ptr);
		return (1);
	}
	cube.img.mlx_img = mlx_new_image(cube.mlx_ptr, W_WIDTH, W_HEIGHT);
	cube.img.addr = mlx_get_data_addr(cube.img.mlx_img, &cube.img.bpp, \
					&cube.img.line_len, &cube.img.endian);
	mlx_loop_hook(cube.mlx_ptr, &render_cub3d, &cube);
	mlx_hook(cube.win_ptr, 2, 1L, (void *)keyboard, &cube);
	mlx_hook(cube.win_ptr, 3, (1L << 1), (void *)keyboard_release, &cube);
	mlx_hook(cube.win_ptr, 17, 0L, (void *)destroy_window, &cube);
	mlx_hook(cube.win_ptr, 4, (1L << 2), (void *)mouse_click, &cube.img);
	// mlx_hook(cube.win_ptr, 6, (1L << 6), (void *)mouse_click_motion, &cube.img);
	mlx_loop(cube.mlx_ptr);
	return (0);
}

/* TAREFA */
// plane	dir		plane


// 		   plyer

/*
 altura (h) do mapa = end - start + 1
 largura (w) do mapa = maior linha do mapa
*/
int	render_cub3d(t_cube *cube)
{
	if (!cube->mlx_ptr)
		return (1);
	clear_img(cube->img);
	draw_ceil_floor(&cube->img);

	// (Use Key for activate the minimap)
	render_minimap(&cube->img);
	draw_player(cube, cube->p->pos.x / TILE_SIZE, cube->p->pos.y / TILE_SIZE);
	raycasting(cube, &cube->img);
	// render_player(cube);

	// print_grid(&cube->img);
	// print_ray(cube, &cube->img);
	// print_player_m(cube, &cube->img);
	// print_player(cube, &cube->img);



	// draw_line_screen(cube->p->pos.y, cube->p->pos.x,
	//  				&cube->img, cube->p->angle);
	// draw_player_screen(&cube->img, cube->p->pos.x, cube->p->pos.y);

	/* After render this function put image to window */
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, \
							cube->img.mlx_img, 0, 0);
	return (0);
}

void	keyboard(int keycode, t_cube *cube)
{
	if (keycode == ESC)
		destroy_window(cube);
	else if (keycode == K_W || keycode == UP)
		move_up(cube, 1);
	else if (keycode == K_S || keycode == DOWN)
		move_up(cube, -1);
	else if (keycode == K_D)
		move_right(cube, 1);
	else if (keycode == K_A)
		move_right(cube, -1);
	else if (keycode == RIGHT)
		move_rotate(cube, 1);
	else if (keycode == LEFT)
		move_rotate(cube, -1);
}

void	keyboard_release(int key, t_cube *cube)
{
	if (key)
		cube->p->move = 0;
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
