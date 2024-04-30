/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/29 18:07:51 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_up(t_data *data)
{
	t_vt_f	new;

	new.x = data->plyr->dir.x * data->plyr->move_speed;
	new.y = data->plyr->dir.y * data->plyr->move_speed;

	if (map()->map[(int)(data->plyr->pos.x + new.x)]\
					[(int)data->plyr->pos.y] != '1')
		data->plyr->pos.x += new.x;
	if (map()->map[(int)data->plyr->pos.x]\
				[(int)(data->plyr->pos.y + new.y)] != '1')
		data->plyr->pos.y += new.y;
	// hit_wall(data, data->plyr->pos.x, data->plyr->pos.y);
}

void	move_down(t_data *data)
{
	t_vt_f	new;

	new.x = data->plyr->dir.x * data->plyr->move_speed;
	new.y = data->plyr->dir.y * data->plyr->move_speed;

	if (map()->map[(int)(data->plyr->pos.x - new.x)]\
				[(int)data->plyr->pos.y] != '1')
		data->plyr->pos.x -= new.x;
	if (map()->map[(int)data->plyr->pos.x]\
				[(int)(data->plyr->pos.y - new.y)] != '1')
		data->plyr->pos.y -= new.y;
}

void	move_right(t_data *data)
{
	t_vt_f	new_dir;
	t_vt_f	new_pos;

	new_dir.x = data->plyr->dir.x * cos(-M_PI_2) -\
				data->plyr->dir.y * sin(-M_PI_2);
	new_dir.y = data->plyr->dir.x * sin(-M_PI_2) +\
				data->plyr->dir.y * cos(-M_PI_2);

	new_pos.x = new_dir.x * data->plyr->move_speed;
	new_pos.y = new_dir.y * data->plyr->move_speed;
	if (map()->map[(int)(data->plyr->pos.x + new_pos.x)] \
				[(int)(data->plyr->pos.y + new_pos.y)] != '1')
	{
		data->plyr->pos.x += new_pos.x;
		data->plyr->pos.y += new_pos.y;
	}
	// if (map()->map[(int)data->plyr->pos.x]
				// [(int)(data->plyr->pos.y + new_pos.y)] != '1')
}

void	move_left(t_data *data)
{
	t_vt_f	new_dir;
	t_vt_f	new_pos;

	new_dir.x = data->plyr->dir.x * cos(M_PI_2) -\
				data->plyr->dir.y * sin(M_PI_2);
	new_dir.y = data->plyr->dir.x * sin(M_PI_2) +\
				data->plyr->dir.y * cos(M_PI_2);

	new_pos.x = new_dir.x * data->plyr->move_speed;
	new_pos.y = new_dir.y * data->plyr->move_speed;
	printf("NPos: x %f,y %f", new_pos.x, new_pos.y);
	// int mapx;
	// int mapy;

	// mapx = floor(new_pos.x);
	// mapy = floor(new_pos.y);
	// if (map()->map[mapy] 
	// 			[mapx] != '1')
	if (map()->map[(int)(data->plyr->pos.x + new_pos.x)] \
				[(int)(data->plyr->pos.y + new_pos.y)] != '1')
	{
		data->plyr->pos.x += new_pos.x;
		data->plyr->pos.y += new_pos.y;
	}
	// if (map()->map[(int)data->plyr->pos.x]
				// [(int)(data->plyr->pos.y + new_pos.y)] != '1')
		// data->plyr->pos.y += new_pos.y;
}


void	move_rotate(t_data *data, int d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->plyr->dir.x;
	data->plyr->dir.x = data->plyr->dir.x * cos(d * data->plyr->rotation_speed \
					) - data->plyr->dir.y * sin(d * data->plyr->rotation_speed);
	data->plyr->dir.y = old_dir_x * sin(d * data->plyr->rotation_speed) + \
						data->plyr->dir.y * cos(d * data->plyr->rotation_speed);
	old_plane_x = data->plyr->plane.x;
	data->plyr->plane.x = data->plyr->plane.x * \
					cos(d * data->plyr->rotation_speed) - data->plyr->plane.y \
					* sin(d * data->plyr->rotation_speed);
	data->plyr->plane.y = old_plane_x * sin(d * data->plyr->rotation_speed) + \
					data->plyr->plane.y * cos(d * data->plyr->rotation_speed);
}
