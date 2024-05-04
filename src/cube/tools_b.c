/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:06:45 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/04 16:07:45 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_map	*map(void)
{
	static t_map	m;

	return (&m);
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
double	player_direction(void)
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

void	set_vector_f(t_vt_f *p, float x, float y)
{
	p->x = x;
	p->y = y;
}

t_vt_f	set_dir(void)
{
	t_vt_f	dir;

	if (parse()->orientation == 'N')
		set_vector_f(&dir, 0, 1);
	else if (parse()->orientation == 'S')
		set_vector_f(&dir, 0, -1);
	else if (parse()->orientation == 'W')
		set_vector_f(&dir, 1, 0);
	else
		set_vector_f(&dir, -1, 0);
	// set positions player to 0;
	// map()->map[map()->ply_start.x][map()->ply_start.y] = '0';
	return (dir);
}

void	init_values(t_cube *cube)
{
	cube->p = ft_calloc(1, sizeof(t_plyer));
	if (!cube->p)
		exit(1);
	cube->r = ft_calloc(1, sizeof(t_raycast));
	if (!cube->r)
		exit(1);

	cube->p->move_speed = 1.5;
	cube->p->rotation_speed = cube->p->move_speed * (M_PI / 180) * 8;
	cube->p->angle = player_direction();
	// cube->p->dir = set_dir(); // raio vetor inicial de direcao
	cube->p->dir.x = -1; // set_dir(); // raio vetor inicial de direcao
	// cube->p->dir.y = -1; // set_dir(); // raio vetor inicial de direcao
	cube->p->pos.x = map()->ply_start.x * TILE_SIZE + TILE_SIZE / 2;
	cube->p->pos.y = map()->ply_start.y * TILE_SIZE + TILE_SIZE / 2;
	cube->p->plane.y = 0.66; // versão 2d raster do plano da câmera
}

void	free_data(t_cube *cube)
{
	free(cube->p);
	free(cube->r);
}
