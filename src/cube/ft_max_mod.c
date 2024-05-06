/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:23:42 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/06 19:47:24 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_mod(float a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}

void	ft_angle_normal(float *angle)
{
	float	mod_angle;

	mod_angle = 2 * M_PI;
	*angle = fmod(*angle, mod_angle);
	if (*angle < 0)
		*angle += mod_angle;
}
