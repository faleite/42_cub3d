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

int	hit_wall(float x, float y)
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if ((y_m >= map()->map_height || x_m >= map()->map_width))
		return (0);
	if (map()->map[y_m] && x_m <= (int)strlen(map()->map[y_m]))
		if (map()->map[y_m][x_m] == '1')
			return (0);
	return (1);
}

double	ft_check_distance(t_vt_f p1, t_vector_2d_f p2)
{
	double	dx;
	double	dy;

	dx = (p2.x - p1.x);
	dy = (p2.y - p1.y);
	return (sqrt(dx * dx + dy * dy));
}

int	ft_looking_angle_up(float angle)
{
	ft_angle_normal(&angle);
	if (angle > 0 && angle < M_PI)
		return (1);
	if (angle > M_PI && angle < 2 * M_PI)
		return (2);
	return (0);
}

int	ft_looking_angle_down(float angle)
{
	ft_angle_normal(&angle);
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (1);
	else if (angle > 3 * M_PI / 2 && angle < M_PI)
		return (2);
	return (0);
}

int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}
