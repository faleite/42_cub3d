/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:59:47 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/17 21:11:03 by faaraujo         ###   ########.fr       */
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

static int	put_field(char field)
{
	if (field == '1')
		return (WALL);
	else if (field == '0')
		return (FLOOR);
	else if (field == ' ')
		return (SPACES);
	else if (field == 'N')
		return (N);
	else if (field == 'S')
		return (S);
	else if (field == 'W')
		return (W);
	else if (field == 'E')
		return (E);
	return (-1);
}

int	**get_int_map(void)
{
	int	i;
	int	j;
	int	**map;

	i = 0;
	map = ft_calloc(parse()->map_height + 1, sizeof(int *));
	while (i <= parse()->map_height)
	{
		j = 0;
		map[i] = ft_calloc(parse()->map_width + 1, sizeof(int *));
		while (j < (int)ft_strlen(parse()->map[i]))
		{
			map[i][j] = put_field(parse()->map[i][j]);
			j++;
		}
		j = parse()->map_width;
		while (map[i][j] == 0)
			map[i][j--] = SPACES;
		i++;
	}
	return (map);
}

void	init_player(void)
{
	plyer()->map = get_int_map();
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
	print_int_map(plyer()->map);
	build_window();
	// free_map(plyer()->map);
	// free_arr(parse()->map);
	return (0);
}
