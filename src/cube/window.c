/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/10 16:55:32 by faaraujo         ###   ########.fr       */
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

int	destroy_image(t_cube *cube)
{
	if (cube->tex_no.img.mlx_img)
		mlx_destroy_image(cube->mlx_ptr, cube->tex_no.img.mlx_img);
	if (cube->tex_so.img.mlx_img)
		mlx_destroy_image(cube->mlx_ptr, cube->tex_so.img.mlx_img);
	if (cube->tex_we.img.mlx_img)
		mlx_destroy_image(cube->mlx_ptr, cube->tex_we.img.mlx_img);
	if (cube->tex_ea.img.mlx_img)
		mlx_destroy_image(cube->mlx_ptr, cube->tex_ea.img.mlx_img);
	return (1);
}

void	image_error(t_cube *cube)
{
	destroy_image(cube);
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	mlx_destroy_display(cube->mlx_ptr);
	free(cube->mlx_ptr);
	free_data(cube);
	err_case("Image doesn't work\n");
}

/* TEXTURE */
void	get_data_texture(t_cube *cube)
{
	cube->tex_no.img.addr = mlx_get_data_addr(cube->tex_no.img.mlx_img, \
						&cube->tex_no.img.bpp, &cube->tex_no.img.line_len, \
						&cube->tex_no.img.endian);
	cube->tex_so.img.addr = mlx_get_data_addr(cube->tex_so.img.mlx_img, \
						&cube->tex_so.img.bpp, &cube->tex_so.img.line_len, \
						&cube->tex_so.img.endian);
	cube->tex_we.img.addr = mlx_get_data_addr(cube->tex_we.img.mlx_img, \
						&cube->tex_we.img.bpp, &cube->tex_we.img.line_len, \
						&cube->tex_we.img.endian);
	cube->tex_ea.img.addr = mlx_get_data_addr(cube->tex_ea.img.mlx_img, \
						&cube->tex_ea.img.bpp, &cube->tex_ea.img.line_len, \
						&cube->tex_ea.img.endian);
}

int	texture_xpm_to_image(t_cube *cube)
{
	cube->tex_no.img.mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
				parse()->path_no, &cube->tex_no.width, &cube->tex_no.height);
	cube->tex_so.img.mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
				parse()->path_so, &cube->tex_so.width, &cube->tex_so.height);
	cube->tex_we.img.mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
				parse()->path_we, &cube->tex_we.width, &cube->tex_we.height);
	cube->tex_ea.img.mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
				parse()->path_ea, &cube->tex_ea.width, &cube->tex_ea.height);
	if (!cube->tex_no.img.mlx_img || !cube->tex_so.img.mlx_img \
		|| !cube->tex_we.img.mlx_img || !cube->tex_ea.img.mlx_img)
		image_error(cube);
	get_data_texture(cube);
	return (0);
}
/* PRINT ONE TEXTURE */
int	draw_one_texture(t_cube *cube, t_texture dir)
{
	t_vt_d	pos;

	pos.y = -1;
	while (++pos.y <= TILE_SIZE )
	{
		pos.x = -1;
		while (++pos.x <= TILE_SIZE)
			img_draw_pixel(&cube->img, pos.x, pos.y, \
			wall_draw_pixel(dir, pos.x, pos.y));
	}
	return (0);
}

/* PRINT ALL TEXTURE */
int	draw_texture(t_cube *cube)
{
    t_vt_d	pos;

    // Desenhar tex_no e tex_so
    pos.y = -1;
    while (++pos.y <= TILE_SIZE)
    {
        pos.x = -1;
        while (++pos.x <= TILE_SIZE)
            img_draw_pixel(&cube->img, pos.x, pos.y, \
            wall_draw_pixel(cube->tex_no, pos.x, pos.y));
    }
    pos.y = -1;
    while (++pos.y <= TILE_SIZE)
	{
        pos.x = TILE_SIZE + 10;
        while (++pos.x <= (TILE_SIZE * 2) + 10)
            img_draw_pixel(&cube->img, pos.x, pos.y, \
            wall_draw_pixel(cube->tex_so, pos.x - TILE_SIZE - 10, pos.y));
    }
    // Desenhar tex_we e tex_ea
    pos.y = TILE_SIZE + 10;
    while (++pos.y <= (TILE_SIZE * 2) + 10)
    {
        pos.x = -1;
        while (++pos.x <= TILE_SIZE)
            img_draw_pixel(&cube->img, pos.x, pos.y, \
            wall_draw_pixel(cube->tex_we, pos.x, pos.y - TILE_SIZE - 10));
    }
    pos.y = TILE_SIZE + 10;
    while (++pos.y <= (TILE_SIZE * 2) + 10)
    {
        pos.x = TILE_SIZE + 10;
        while (++pos.x <= (TILE_SIZE * 2) + 10)
            img_draw_pixel(&cube->img, pos.x, pos.y, \
            wall_draw_pixel(cube->tex_ea, pos.x - TILE_SIZE - 10, pos.y - TILE_SIZE - 10));
    }
    return (0);
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
	texture_xpm_to_image(&cube);
	cube.img.mlx_img = mlx_new_image(cube.mlx_ptr, W_WIDTH, W_HEIGHT);
	cube.img.addr = mlx_get_data_addr(cube.img.mlx_img, &cube.img.bpp, \
					&cube.img.line_len, &cube.img.endian);
	mlx_hook(cube.win_ptr, 2, 1L, (void *)keyboard, &cube);
	mlx_hook(cube.win_ptr, 3, (1L << 1), (void *)keyboard_release, &cube);
	mlx_hook(cube.win_ptr, 17, 0L, (void *)destroy_window, &cube);
	mlx_hook(cube.win_ptr, 6, (1L << 6), ft_mouse_handlertrack, &cube);
	mlx_loop_hook(cube.mlx_ptr, &render_cub3d, &cube);
	mlx_loop(cube.mlx_ptr);
	return (0);
}

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

	draw_ceil_floor(&cube->img);
	raycasting(cube);

	// // (Use Key for activate the minimap)
	render_minimap(cube);
	draw_player(cube, (cube->p->pos.x / TILE_SIZE), \
				(cube->p->pos.y / TILE_SIZE));
	render_rays(cube);

	ft_player_movement(cube);
	drawCircleWithCross(cube);

	// TEXTURES //
	/* PRINT ALL TEXTURE */
	// draw_texture(cube);
	/* PRINT ONE TEXTURE */
	draw_one_texture(cube, cube->tex_we);

	/* After render this function put image to window */
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, \
							cube->img.mlx_img, 0, 0);
	return (0);
}

/**
 * LOOK -> key 'Ctrl' = 107 iqual key 'ESC'
*/
void	keyboard(int keycode, t_cube *cube)
{
	keycode %= 200;
	printf("key press %d\n", keycode);
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
