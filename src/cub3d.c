/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:59:47 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/18 12:32:59 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	init_player(void)
{
	plyer()->map = parse()->map;
	plyer()->pos.x = parse()->pos_x;
	plyer()->pos.y = parse()->pos_y;
	plyer()->rotation_angle = player_direction();
	plyer()->radius = 2;
	plyer()->move_speed = 2.0;
	plyer()->rotation_speed = 2 * (M_PI / 180);
}

/*
 DEBUG:
 print_data();
*/
int	main(int argc, char *argv[])
{
	validate_scene(argc, argv[1]);
	init_player();
	build_window();
	return (0);
}
