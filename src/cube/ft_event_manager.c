/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <juan-pma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 08:59:50 by juan-pma          #+#    #+#             */
/*   Updated: 2024/05/11 08:59:50 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_mouse_handlertrack(int x, int y, t_cube *param)
{
	t_vector_2d	mouse_pos;

	mouse_pos.x = x - param->p->pos.x;
	mouse_pos.y = y - param->p->pos.y;
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

void	keyboard(int keycode, t_cube *cube)
{
	keycode %= 200;
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