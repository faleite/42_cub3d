/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:06:45 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/23 21:04:20 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

void	init_values(t_data *data)
{
	data->plyr = malloc(sizeof(t_plyr));
	data->cast = malloc(sizeof(t_raycast));
	data->plyr->horizontal = 0;
	data->plyr->vertical = 0;
	data->plyr->move_speed = 3;
	data->plyr->rotation_speed = data->plyr->move_speed * M_PI / 180;
	data->plyr->angle = 90;
	data->plyr->pos.x = map()->ply_start.x * TILE_SIZE + TILE_SIZE / 2;
	data->plyr->pos.y = map()->ply_start.y * TILE_SIZE + TILE_SIZE / 2;
	data->cast->ww_half = W_WIDTH / 2;
	data->cast->bool = 0;
	data->cast->dist = 0;
	data->cast->angle = 3 * (M_PI / 2);
}

void	free_data(t_data *data)
{
	free(data->plyr);
	free(data->cast);
}
