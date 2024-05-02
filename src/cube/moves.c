/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/02 20:35:32 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_up(t_data *data, int move)
{
	t_vt_f	new;

	data->plyr->move = move;
	new.x = data->plyr->pos.x;
	new.y = data->plyr->pos.y;

	new.x += data->plyr->dir.x * data->plyr->move_speed * data->plyr->move;
	new.y += data->plyr->dir.y * data->plyr->move_speed * data->plyr->move;
	if (hit_wall(new.x, new.y) == 0)
	{
		data->plyr->pos.x = new.x;
		data->plyr->pos.y = new.y;
	}
}

/**
 * printf("NewX: %d, NewY: %d\n", (int)new_pos.x / TILE_SIZE, (int)new_pos.y / TILE_SIZE);
	if (map()->map[(int)new_pos.y / TILE_SIZE][(int)new_pos.x / TILE_SIZE] == '1')
		printf("WALL");
*/
void	move_right(t_data *data, int move)
{
	t_vt_f	new_dir;
	t_vt_f	new_pos;

	data->plyr->move = move;
	new_dir.x = data->plyr->dir.x * cos(M_PI_2) * data->plyr->move -\
				data->plyr->dir.y * sin(M_PI_2) * data->plyr->move;
	new_dir.y = data->plyr->dir.x * sin(M_PI_2) * data->plyr->move +\
				data->plyr->dir.y * cos(M_PI_2) * data->plyr->move;

	new_pos.x = data->plyr->pos.x; 
	new_pos.y = data->plyr->pos.y;

	new_pos.x += new_dir.x * data->plyr->move_speed;
	new_pos.y += new_dir.y * data->plyr->move_speed;
	if (hit_wall(new_pos.x, new_pos.y) == 0)
	{
		data->plyr->pos.x = new_pos.x;
		data->plyr->pos.y = new_pos.y;
	}
}

void	move_rotate(t_data *data, int rotate)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->plyr->dir.x;
	data->plyr->dir.x = data->plyr->dir.x * cos(rotate * data->plyr->rotation_speed
					) - data->plyr->dir.y * sin(rotate * data->plyr->rotation_speed);
	data->plyr->dir.y = old_dir_x * sin(rotate * data->plyr->rotation_speed) +
						data->plyr->dir.y * cos(rotate * data->plyr->rotation_speed);
	old_plane_x = data->plyr->plane.x;
	data->plyr->plane.x = data->plyr->plane.x * 
					cos(rotate * data->plyr->rotation_speed) - data->plyr->plane.y 
					* sin(rotate * data->plyr->rotation_speed);
	data->plyr->plane.y = old_plane_x * sin(rotate * data->plyr->rotation_speed) + 
					data->plyr->plane.y * cos(rotate * data->plyr->rotation_speed);
}
