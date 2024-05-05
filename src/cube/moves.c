/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/05 16:10:15 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//-------------------------------------------------------- movement updaate.
// printf("NewX: %d, NewY: %d\n", (int)(new.x) / (int)TILE_SIZE, (int)(new.y) / (int)TILE_SIZE);
void	ft_player_movement_update(t_cube *cube, int move)
{
	t_plyer	*player;
	t_vt_f	new;

	player = cube->p;
	new = player->pos;
	if (move == 1)
	{
		new.x += (cos(player->angle) * player->move * player->move_speed);
		new.y += (sin(player->angle) * player->move * player->move_speed);
	}
	else if (move == 2)
	{
		new.x += (cos(player->angle + (M_PI / 2)) * player->move *\
						player->move_speed);
		new.y += (sin(player->angle + (M_PI / 2)) * player->move *\
						player->move_speed);
	}
	if (map()->map[(int)new.y / (int)TILE_SIZE][(int)cube->p->pos.x /\
		(int)TILE_SIZE] != '1')
		cube->p->pos.y = new.y;
	if (map()->map[(int)cube->p->pos.y / (int)TILE_SIZE][(int)new.x /\
		(int)TILE_SIZE] != '1')
		cube->p->pos.x = new.x;
	player->angle += player->rotate * player->rotation_speed;
	ft_angle_normal(&cube->p->angle);
}

void	ft_player_movement(t_cube *cube)
{
	if (cube->p->key_bool[K_W] || cube->p->key_bool[K_S]
		|| cube->p->key_bool[K_LEFT] || cube->p->key_bool[K_RIGHT])
		ft_player_movement_update(cube, 1);
	if (cube->p->key_bool[K_A] || cube->p->key_bool[K_D])
		ft_player_movement_update(cube, 2);
}
