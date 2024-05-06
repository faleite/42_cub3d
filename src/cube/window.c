/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/06 18:22:35 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	keyboard(int keycode, t_cube *cube);
void	keyboard_release(int key, t_cube *cube);

int	ft_mouse_handlertrack(int x, int y, t_cube *param)
{
	t_vector_2d	mouse_pos;

	mouse_pos.x = x - param->p->pos.x;
	mouse_pos.y = y - param->p->pos.y;

	// printf("mouse X:%d:\n", x);
	// printf("mouse Y:%d:\n", y);

	param->p->angle = atan2(mouse_pos.y, mouse_pos.x);
	ft_angle_normal(&param->p->angle);
	return (0);
}

void	ft_load_texture(void *mlx, t_texture *texture)
{
	texture->img.addr = mlx_get_data_addr(texture->img.mlx_img,
			&texture->img.bpp,
			&texture->img.line_len,
			&texture->img.endian);
}

t_tex	*tex(void)
{
	static t_tex	t;

	return (&t);
}

void	*file_to_image(t_cube *cube, char *path)
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(cube->mlx_ptr, path, &width, &height);
	if (!img)
		printf("NOT TAKE THE IMAGE\n");
		// image_error();
	else
		printf("IMAGE: %p\n", img);
	return (img);
}

void	get_image(t_cube *cube)
{
	tex()->path_no = file_to_image(cube, parse()->path_no);
	cube->tex_no.img.mlx_img = tex()->path_no;
	tex()->path_so = file_to_image(cube, parse()->path_so);
	tex()->path_we = file_to_image(cube, parse()->path_we);
	tex()->path_ea = file_to_image(cube, parse()->path_ea);
}

void	image_to_window(t_cube *cube, void *img, int x, int y)
{
	mlx_put_image_to_window
	(
		cube->mlx_ptr,
		cube->win_ptr,
		img,
		x * TILE_SIZE,
		y * TILE_SIZE
	);
}

// void ft_init_textures(t_cube *cube)
// {
// 	char *path_no;
// 	char *path_so;
// 	char *path_we;
// 	char *path_ea;

// 	path_no = "../../textures/walls/w3d_e.xpm";
// 	path_so = "../../textures/walls/w3d_n.xpm";
// 	path_we = "../../textures/walls/w3d_s.xpm";
// 	path_ea = "../../textures/walls/w3d_w.xpm";

// 	ft_load_texture(cube->mlx_ptr, &cube->tex_no, path_no);
// 	ft_load_texture(cube->mlx_ptr, &cube->tex_so, path_so);
// 	ft_load_texture(cube->mlx_ptr, &cube->tex_we, path_we);
// 	ft_load_texture(cube->mlx_ptr, &cube->tex_ea, path_ea);
// }

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
	get_image(&cube);
	cube.img.mlx_img = mlx_new_image(cube.mlx_ptr, W_WIDTH, W_HEIGHT);
	cube.img.addr = mlx_get_data_addr(cube.img.mlx_img, &cube.img.bpp, \
					&cube.img.line_len, &cube.img.endian);
	ft_load_texture(cube.mlx_ptr, &cube.tex_no); //
	mlx_hook(cube.win_ptr, 2, 1L, (void *)keyboard, &cube);
	mlx_hook(cube.win_ptr, 3, (1L << 1), (void *)keyboard_release, &cube);
	mlx_hook(cube.win_ptr, 17, 0L, (void *)destroy_window, &cube);
	mlx_hook(cube.win_ptr, 6, (1L << 6), ft_mouse_handlertrack, &cube);
	mlx_loop_hook(cube.mlx_ptr, &render_cub3d, &cube);
	mlx_loop(cube.mlx_ptr);
	return (0);
}

/*
 altura (h) do mapa = end - start + 1
 largura (w) do mapa = maior linha do mapa
*/

void drawCircleWithCross(t_cube *cube) {

    int centerx;
    int centery;
    int radious;

    centerx = W_WIDTH / 2;
    centery = W_HEIGHT / 2;
    radious = 50;
    int x, y, dx, dy;

    // Draw the circle
    for (double angle = 0; angle < 360; angle += 0.1) {
        x = centerx + (int)(radious * cos(angle * M_PI / 180));
        y = centery + (int)(radious * sin(angle * M_PI / 180));
        img_draw_pixel(&cube->img, x, y, RED);
    }

    // Draw the vertical line of the cross
    for (y = centery - radious; y <= centery + radious; y++) {
        img_draw_pixel(&cube->img, centerx, y, WHITE);
    }

    // Draw the horizontal line of the cross
    for (x = centerx - radious; x <= centerx + radious; x++) {
        img_draw_pixel(&cube->img, x, centery, WHITE);
    }
}

int	render_cub3d(t_cube *cube)
{
	if (!cube->mlx_ptr)
		return (1);
	clear_img(cube->img);

	// draw_ceil_floor(&cube->img);
	// raycasting(cube);

	// (Use Key for activate the minimap)
	// render_minimap(cube);
	// draw_player(cube, (cube->p->pos.x / TILE_SIZE), \
	// 			(cube->p->pos.y / TILE_SIZE));
	// render_rays(cube);

	// ft_player_movement(cube);
	// drawCircleWithCross(cube);

	// TEXTURES //
	// mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, \
							tex()->path_no, 0, 0);

	/* After render this function put image to window */
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, \
							cube->img.mlx_img, 0, 0);
	return (0);
}

void	keyboard(int keycode, t_cube *cube)
{
	keycode %= 200;
	// printf("key press %d\n", keycode);
	if (keycode < 200)
	{
		cube->p->prev_key_bool[keycode] = cube->p->key_bool[keycode];
		cube->p->key_bool[keycode] = 1;
	}
    if (keycode < 200)
    {
        cube->p->prev_key_bool[keycode] = cube->p->key_bool[keycode] ;
        cube->p->key_bool[keycode] = 1;
    }
	if (keycode == ESC)
		destroy_window(cube);
	else if (keycode == K_W || keycode == K_D)
		cube->p->move = 1;
	else if (keycode == K_S || keycode == K_A)
		cube->p->move = -1;
	else if (keycode == RIGHT)
		cube->p->rotate = 1;
	else if (keycode == LEFT)
		cube->p->rotate = -1;
}

void	keyboard_release(int key, t_cube *cube)
{
	t_plyer	*player;

	player = cube->p;
	key %= 200;

	if (key < 200)
	{
		player->prev_key_bool[key] = player->key_bool[key];
		player->key_bool[key] = 0;
		player->move = 0;
		player->rotate = 0;
	}
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
