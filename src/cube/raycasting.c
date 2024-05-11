/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:24:05 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/03 21:18:06 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		calc_step(float angle, float *inter, \
							float *step, int is_horizon);

void	raycasting(t_cube *cube)
{
	int				num_ray;
	t_vector_2d_f	intersection;
	t_raycast		*ray;

	ray = cube->r;
	ray->angle = cube->p->angle - 0.523599;
	ft_angle_normal((float *)&ray->angle);
	num_ray = -1;
	while (++num_ray < W_WIDTH)
	{
		ft_angle_normal((float *)&ray->angle);
		ray->hit = 0;
		intersection.x = calc_hor_distance(cube, ray->angle);
		intersection.y = calc_vertical_distance(cube, ray->angle);
		if (intersection.y < intersection.x)
			ray->dist = intersection.y;
		else
		{
			ray->dist = intersection.x;
			ray->hit = 1;
		}
		render_wall(cube, num_ray);
		ray->angle += (FOV_RAD / W_WIDTH);
	}
}

static int	calc_step(float angle, float *inter, \
						float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
	return (1);
}

/**
 * vertical intersection.
*/
float	calc_vertical_distance(t_cube *cube, float angl)
{
	t_vector_2d_f	collition;
	t_vector_2d_f	delta;
	int				pixel;

	ft_angle_normal(&angl);
	delta.x = TILE_SIZE;
	delta.y = TILE_SIZE * tan(angl);
	collition.x = floor(cube->p->pos.x / TILE_SIZE) * TILE_SIZE;
	pixel = calc_step(angl, &collition.x, &delta.x, 0);
	collition.y = cube->p->pos.y + (collition.x - cube->p->pos.x) * tan(angl);
	if ((unit_circle(angl, 'x') && delta.y < 0) || \
	(!unit_circle(angl, 'x') && delta.y > 0))
		delta.y *= -1;
	while (hit_wall(collition.x - pixel, collition.y))
	{
		collition.x += delta.x;
		collition.y += delta.y;
	}
	cube->r->ver.x = collition.x;
	cube->r->ver.y = collition.y;
	return (ft_check_distance(cube->p->pos, collition));
}

/**
 * horizontal distance.
*/
float	calc_hor_distance(t_cube *cube, float angl)
{
	t_vector_2d_f	collition;
	t_vector_2d_f	delta;
	int				pixel;

	delta.y = TILE_SIZE;
	ft_angle_normal(&angl);
	delta.x = TILE_SIZE / tan(angl);
	collition.y = floor(cube->p->pos.y / TILE_SIZE) * TILE_SIZE;
	pixel = calc_step(angl, &collition.y, &delta.y, 1);
	collition.x = cube->p->pos.x + (collition.y - cube->p->pos.y) / tan(angl);
	if ((unit_circle(angl, 'y') && delta.x > 0) || \
		(!unit_circle(angl, 'y') && delta.x < 0))
		delta.x *= -1;
	while (hit_wall(collition.x, collition.y - pixel))
	{
		collition.x += delta.x;
		collition.y += delta.y;
	}
	cube->r->hor.x = collition.x;
	cube->r->hor.y = collition.y;
	return (ft_check_distance(cube->p->pos, collition));
}
