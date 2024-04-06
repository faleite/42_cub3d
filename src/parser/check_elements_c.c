/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/06 20:14:34 by faaraujo         ###   ########.fr       */
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
	while (parse()->scene && parse()->scene[i])
	{
		last_char = ft_strlen(parse()->scene[i]) - 1;
		if ((parse()->scene[i][0] == '1' || parse()->scene[i][0] == ' ') \
			&& parse()->scene[i][last_char] == '1' && flag)
		{
			parse()->start_map = i++;
			flag = 0;
		}
		if ((parse()->scene[i][0] == '1' || parse()->scene[i][0] == ' ') \
			&& parse()->scene[i][last_char] == '1')
		{
			parse()->end_map = i;
			i++;
		}
		else
			i++;
	}
	return (parse()->start_map);
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
	clean_comma_utils(parse()->rgb_f);
	clean_comma_utils(parse()->rgb_c);
	return (0);
}
