/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/27 20:40:05 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_location(void)
{
	int	i;
	int	flag;
	int	last_char;

	i = 0;
	flag = 1;
	while (cub()->scene && cub()->scene[i])
	{
		last_char = ft_strlen(cub()->scene[i]) - 1;
		if ((cub()->scene[i][0] == '1' || cub()->scene[i][0] == ' ') \
			&& cub()->scene[i][last_char] == '1' && flag)
		{
			cub()->start_map = i++;
			flag = 0;
		}
		if ((cub()->scene[i][0] == '1' || cub()->scene[i][0] == ' ') \
			&& cub()->scene[i][last_char] == '1')
		{
			cub()->end_map = i;
			i++;
		}
		else
			i++;
	}
	return (cub()->start_map);
}

static int	clean_comma_utils(char **rgb)
{
	int	i;
	int	len;

	i = 0;
	while (rgb && rgb[i] && i < 2)
	{
		len = ft_strlen(rgb[i]) - 1;
		if (rgb[i][len] == ',')
			rgb[i][len] = '\0';
		i++;
	}
	return (0);
}

int	clean_comma(void)
{
	clean_comma_utils(cub()->rgb_f);
	clean_comma_utils(cub()->rgb_c);
	return (0);
}
