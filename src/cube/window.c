/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:29:40 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/06 11:58:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// #include "../../textures/walls/w3d_n.xpm"
// #include "../../textures/walls/w3d_s.xpm"
// #include "../../textures/walls/w3d_w.xpm"
void	keyboard(int keycode, t_cube *cube);
void	keyboard_release(int key, t_cube *cube);

// void ft_texture_manager(t_cube *cube, t_texture *texture, int num)
// {
// 	if (num == 0)
// 	{
// 		texture->mlx_img =  mlx_xpm_file_to_image(cube->mlx_ptr, parse()->path_no, &cube->texture->width, &cube->texture->height);
// 		if (!texture->mlx_img)
// 			printf("error\n");
// 		texture->addr = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->line_len, &texture->endian);
// 	}
// 	if (num == 1)
// 	{
// 		texture->mlx_img =  mlx_xpm_file_to_image(cube->mlx_ptr, parse()->path_so, &cube->texture->width, &cube->texture->height);
// 		texture->addr = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->line_len, &texture->endian);
// 	}
// 	if (num == 2)
// 	{
// 		texture->mlx_img =  mlx_xpm_file_to_image(cube->mlx_ptr, parse()->path_we, &cube->texture->width, &cube->texture->height);
// 		texture->addr = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->line_len, &texture->endian);
// 	}
// 	if (num == 3)
// 	{
// 		texture->mlx_img =  mlx_xpm_file_to_image(cube->mlx_ptr, parse()->path_ea, &cube->texture->width, &cube->texture->height);
// 		texture->addr = mlx_get_data_addr(texture->mlx_img, &texture->bpp, &texture->line_len, &texture->endian);
// 	}
// }


// int int_textures(t_cube *cube)
// {
// 	int num_text;

// 	num_text = -1;
// 	cube->texture = ft_calloc(4, sizeof(t_texture ));
// 	if (!cube->texture)
// 		return (1);
// 	cube->texture->width = 64;
// 	cube->texture->height = 64;
// 	while (++num_text < 4)
// 	{
// 		ft_texture_manager(cube, &cube->texture[num_text], num_text);
// 	}
// 	// cube->texture[0].addr = mlx_xpm_file_to_image(cube->mlx_ptr, parse()->path_no, &cube->texture->width, &cube->texture->height);
	
// }

int ft_mouse_handlertrack(int x, int y, t_cube *param)
{
    t_vector_2d mouse_pos;

    mouse_pos.x = x - param->p->pos.x;
    mouse_pos.y = y - param->p->pos.y;

    printf("mouse X:%d:\n", x);
    printf("mouse Y:%d:\n", y);

    param->p->angle = atan2(mouse_pos.y, mouse_pos.x);
    ft_angle_normal(&param->p->angle);
	return (0);
}
// Function to load the textures.

void	ft_load_texture(void *mlx, t_texture *texture, char *path)
{
	texture->img.mlx_img = mlx_xpm_file_to_image(mlx, path,
			&texture->width, &texture->height);
	// texture->img.addr = mlx_get_data_addr(texture->img.mlx_img,
	// 		&texture->img.bpp,
	// 		&texture->img.line_len,
	// 		&texture->img.endian);
}

void ft_init_textures(t_cube *cube)
{
	char *path_no;
	char *path_so;
	char *path_we;
	char *path_ea;

	path_no = "../../textures/walls/w3d_e.xpm";
	path_so = "../../textures/walls/w3d_n.xpm";
	path_we = "../../textures/walls/w3d_s.xpm";
	path_ea = "../../textures/walls/w3d_w.xpm";

	ft_load_texture(cube->mlx_ptr, &cube->tex_no, path_no);
	ft_load_texture(cube->mlx_ptr, &cube->tex_so, path_so);
	ft_load_texture(cube->mlx_ptr, &cube->tex_we, path_we);
	ft_load_texture(cube->mlx_ptr, &cube->tex_ea, path_ea);
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
	ft_init_textures(&cube);
	// cube.texture = ft_calloc(4, sizeof(t_texture ));
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

int	render_cub3d(t_cube *cube)
{
	if (!cube->mlx_ptr)
		return (1);
	clear_img(cube->img);

	// (Use Key for activate the minimap)
	draw_ceil_floor(&cube->img);
	render_minimap(cube);
	draw_player(cube, (cube->p->pos.x / TILE_SIZE), (cube->p->pos.y / TILE_SIZE));
	raycasting(cube);
	ft_player_movement(cube);
	// ft_bresenham(&cube->img, )
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
	keycode %= 200;
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
	t_plyer *player;

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
