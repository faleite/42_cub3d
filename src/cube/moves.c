/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/24 19:59:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_up(t_data *data)
{
	double new_x;
	double new_y;
	
	new_x = data->plyr->pos.x + cos(data->plyr->angle_s) * data->plyr->move_speed * data->plyr->vertical;
	new_y = data->plyr->pos.y + sin(data->plyr->angle_s) * data->plyr->move_speed * data->plyr->vertical;
	
	data->plyr->pos.x = new_x;
	data->plyr->pos.y = new_y;
	
	data->plyr->angle_s += (data->plyr->horizontal) * data->plyr->rotation_speed;
	hit_wall(data, data->plyr->pos.x, data->plyr->pos.y);
}
