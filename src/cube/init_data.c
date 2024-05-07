/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:06:45 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/07 20:30:12 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	player_direction(void);

void	init_values(t_cube *cube)
{
	int	i;

	cube->p = ft_calloc(1, sizeof(t_plyer));
	if (!cube->p)
		exit(1);
	cube->r = ft_calloc(1, sizeof(t_raycast));
	if (!cube->r)
		exit(1);
	cube->p->move_speed = 4;
	cube->p->rotation_speed = 0.045;
	cube->p->angle = player_direction();
	cube->p->pos.x = map()->ply_start.x * TILE_SIZE + TILE_SIZE / 2;
	cube->p->pos.y = map()->ply_start.y * TILE_SIZE + TILE_SIZE / 2;
	i = -1;
	while (++i < 200)
	{
		cube->p->prev_key_bool[i] = 0;
		cube->p->key_bool[i] = 0;
	}
}

/**
 * Defines direction in function of unitary vectors
			N 3pi / 2
            |
 pi EA______|_____WE 0
		    |
		    |
	    	S pi/2
 * Norte ('N'): 3π/2 radianos, ou 270 graus.
 * Sul ('S'): π/2 radianos, ou 90 graus.
 * Leste ('E'): π radianos, ou 180 graus.
 * Oeste ('W'): 0 radianos, ou 0 graus.
*/
static double	player_direction(void)
{
	if (parse()->orientation == 'N')
		return ((3.0 * M_PI) / 2.0);
	if (parse()->orientation == 'S')
		return (M_PI / 2.0);
	if (parse()->orientation == 'E')
		return (M_PI);
	if (parse()->orientation == 'W')
		return (0.0);
	return (-1.0);
}

void	free_data(t_cube *cube)
{
	free(cube->p);
	free(cube->r);
}

t_map	*map(void)
{
	static t_map	m;

	return (&m);
}
