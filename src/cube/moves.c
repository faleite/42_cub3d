/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/25 12:33:45 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	move_up(t_data *data)
// {
// 	double	new_x;
// 	double	new_y;

// 	new_x = data->plyr->pos.x + cos(data->plyr->angle_s) * data->plyr->move_speed * data->plyr->vertical;
// 	new_y = data->plyr->pos.y + sin(data->plyr->angle_s) * data->plyr->move_speed * data->plyr->vertical;

// 	data->plyr->pos.x = new_x;
// 	data->plyr->pos.y = new_y;

// 	data->plyr->angle_s += data->plyr->horizontal * data->plyr->rotation_speed;
// 	hit_wall(data, data->plyr->pos.x, data->plyr->pos.y);
// }

void	move_up(t_data *data)
{
	t_vt_f	new;

	new.x = data->plyr->dir.x * data->plyr->move_speed;
	new.y = data->plyr->dir.y * data->plyr->move_speed;

	data->plyr->pos.x += new.x;
	data->plyr->pos.y += new.y;
	// hit_wall(data, data->plyr->pos.x, data->plyr->pos.y);
}

void	move_down(t_data *data)
{
	t_vt_f	new;

	new.x = data->plyr->dir.x * data->plyr->move_speed;
	new.y = data->plyr->dir.y * data->plyr->move_speed;

	data->plyr->pos.x -= new.x;
	data->plyr->pos.y -= new.y;
	// hit_wall(data, data->plyr->pos.x, data->plyr->pos.y);
}

void	move_left(t_data *data)
{
	t_vt_f	new_dir;
	t_vt_f	new_pos;

	new_dir.x = data->plyr->dir.x * cos(-M_PI_2) -\
				data->plyr->dir.y * sin(-M_PI_2);
	new_dir.y = data->plyr->dir.x * sin(-M_PI_2) +\
				data->plyr->dir.y * cos(-M_PI_2);

	new_pos.x = new_dir.x * data->plyr->move_speed;
	new_pos.y = new_dir.y * data->plyr->move_speed;

	data->plyr->pos.x += new_pos.x;
	data->plyr->pos.y += new_pos.y;
	// hit_wall(data, data->plyr->pos.x, data->plyr->pos.y);
}

void	move_right(t_data *data)
{
	t_vt_f	new_dir;
	t_vt_f	new_pos;

	new_dir.x = data->plyr->dir.x * cos(M_PI_2) -\
				data->plyr->dir.y * sin(M_PI_2);
	new_dir.y = data->plyr->dir.x * sin(M_PI_2) +\
				data->plyr->dir.y * cos(M_PI_2);

	new_pos.x = new_dir.x * data->plyr->move_speed;
	new_pos.y = new_dir.y * data->plyr->move_speed;

	data->plyr->pos.x += new_pos.x;
	data->plyr->pos.y += new_pos.y;
	// hit_wall(data, data->plyr->pos.x, data->plyr->pos.y);
}

void	rotate_right(t_data *data)
{
	float	old_dir_x;

	old_dir_x = data->plyr->dir.x;
	data->plyr->dir.x = data->plyr->dir.x * cos(data->plyr->rotation_speed) - data->plyr->dir.y * sin(data->plyr->rotation_speed);
	data->plyr->dir.y = old_dir_x * sin(data->plyr->rotation_speed) + data->plyr->dir.y * cos(data->plyr->rotation_speed);
	// hit_wall(data, data->plyr->pos.x, data->plyr->pos.y);
}