/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:00:53 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/17 16:55:15 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	move_up(t_data *data)
// {
// 	t_pix_pos	new_pos;
// 	t_pix_pos	map;
// 	t_pix_pos	next_step;

// 	new_pos = plyer()->pos;
// 	new_pos.x += cos(plyer()->rotation_angle) * plyer()->move_speed;
// 	new_pos.y += sin(plyer()->rotation_angle) * plyer()->move_speed;
// 	map.x = new_pos.x;
// 	map.y = new_pos.y;
// 	next_step.x = (new_pos.x + cos(plyer()->rotation_angle)
// 			* plyer()->move_speed);
// 	next_step.y = (new_pos.y + sin(plyer()->rotation_angle)
// 			* plyer()->move_speed);
// 	// if ((r.cub_map[(int)map.y][(int)map.x] != WALL)
// 	// 	&& (r.cub_map[(int)next_step.y][(int)next_step.x] != WALL))
// 	if ((parse()->map[(int)map.y][(int)map.x] != WALL) 
// 		&& (parse()->map[(int)next_step.y][(int)next_step.x] != WALL))
// 	{
// 		plyer()->pos = new_pos;
// 		// parse()->pos_x = new_pos.x;
// 		// parse()->pos_y = new_pos.y;
// 		render_cub3d(data);
// 	}
// }
