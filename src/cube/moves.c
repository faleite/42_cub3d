/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/04 14:37:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

//-------------------------------------------------------- movement updaate.

void ft_player_movement_update(t_cube *cube, int move)
{
    t_plyer *player;
    double new_x;
    double new_y;

    player = cube->p;
    new_x = player->pos.x;
    new_y = player->pos.y;
    if (move == 1)
    {
        new_x += (cos(player->angle) * player->move * player->move_speed);
        new_y += (sin(player->angle) * player->move * player->move_speed);
    }
    else if (move == 2)
    {
        new_x += (cos(player->angle + (M_PI / 2)) * player->move * player->move_speed);
        new_y += (sin(player->angle + (M_PI / 2)) * player->move * player->move_speed);
    }
    // if (hit_wall( new_x, new_y))
    // {
        player->pos.x = new_x;
        player->pos.y = new_y;
    // }
    player->angle += player->rotate * player->rotation_speed;
    ft_angle_normal(&cube->p->angle);
}

void ft_player_movement(t_cube *cube)
{
    if (cube->p->key_bool[K_W] || cube->p->key_bool[K_S]
        || cube->p->key_bool[K_LEFT] || cube->p->key_bool[K_RIGHT])
        ft_player_movement_update(cube, 1);
    if (cube->p->key_bool[K_A] || cube->p->key_bool[K_D])
        ft_player_movement_update(cube, 2);
}