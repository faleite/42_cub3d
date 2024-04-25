/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:06:45 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/25 12:22:05 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


// t_plyr	*plyer(void)
// {
// 	static t_plyr	p;

// 	return (&p);
// }

t_map	*map(void)
{
	static t_map	m;

	return (&m);
}

/*
Defines direction in function of unitary vectors
			N 3pi / 2
            |
 pi EA______|_____WE 0
		    |
		    |
	    	S pi/2
*/
double	player_direction(void)
{
	if (parse()->orientation == 'N')
		return ((3 * M_PI) / 2);
	if (parse()->orientation == 'S')
		return (M_PI / 2);
	if (parse()->orientation == 'W')
		return (0);
	if (parse()->orientation == 'E')
		return (M_PI);
	return (0);
}

void	set_vector_f(t_vt_f *p, float x, float y)
{
	p->x = x;
	p->y = y;
}

t_vt_f	set_dir(void)
{
	t_vt_f	dir;

	if (parse()->orientation == 'N')
		set_vector_f(&dir, 0, -1);
	else if (parse()->orientation == 'S')
		set_vector_f(&dir, 0, 1);
	else if (parse()->orientation == 'W')
		set_vector_f(&dir, -1, 0);
	else
		set_vector_f(&dir, 1, 0);
	// set positions player to 0;
	// map()->map[map()->ply_start.x][map()->ply_start.y] = '0';
	return (dir);
}

void	init_values(t_data *data)
{
	data->plyr = ft_calloc(1, sizeof(t_plyr));
	if (!data->plyr)
		exit(1);
	data->cast = ft_calloc(1, sizeof(t_raycast));
	if (!data->cast)
		exit(1);
	// data->plyr->horizontal = 0;
	// data->plyr->vertical = 0;
	data->plyr->move_speed = 8;
	data->plyr->rotation_speed = 0.08; // (FOV * M_PI) / 180; // data->plyr->move_speed * M_PI / 180
	data->plyr->angle = player_direction();
	data->plyr->dir = set_dir();
	data->plyr->angle_s = M_PI; // 90
	data->plyr->pos.x = map()->ply_start.x * TILE_SIZE + TILE_SIZE / 2;
	data->plyr->pos.y = map()->ply_start.y * TILE_SIZE + TILE_SIZE / 2;
	data->cast->ww_half = W_WIDTH / 2;
	// data->cast->bool = 0;
	// data->cast->dist = 0;
	data->cast->angle = 3 * (M_PI / 2);
}

void	free_data(t_data *data)
{
	free(data->plyr);
	free(data->cast);
}
