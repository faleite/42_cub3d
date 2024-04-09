/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/09 19:39:36 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	isvalid_field(char c)
{
	return (c == '0' || c == '1' || c == 'N' || \
			c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

void	check_field(void)
{
	int	i;
	int	j;
	int	player;

	i = parse()->start_map;
	player = 0;
	while (parse()->scene[i] && i <= parse()->end_map)
	{
		j = -1;
		while (parse()->scene[i][++j])
		{
			if (!isvalid_field(parse()->scene[i][j]))
				err_case("The map contains invalid field `10'\n");
			else if (is_player(parse()->scene[i][j]))
			{
				player++;
				parse()->orientation = parse()->scene[i][j];
				parse()->pos_x = i;
				parse()->pos_y = j;
			}
		}
		i++;
	}
	if (player != 1)
		err_case("Expected one spawning orientation `11'\n");
}

int	start_end_wall(void)
{
	int	i;
	int	j;

	i = parse()->start_map;
	j = -1;
	while (parse()->scene[i][++j])
	{
		if (parse()->scene[i][j] != '1' && parse()->scene[i][j] != ' ')
			err_case("start or end wall is not valid `12'\n");
	}
	i = parse()->end_map;
	j = -1;
	while (parse()->scene[i][++j])
	{
		if (parse()->scene[i][j] != '1' && parse()->scene[i][j] != ' ')
			err_case("start or end wall is not valid `13'\n");
	}
	return (0);
}

int	closed_by_walls(void)
{
	int	i;
	int	j;
	int	len_line;

	i = parse()->start_map;
	while (parse()->scene[i] && i <= parse()->end_map)
	{
		len_line = ft_strlen(parse()->scene[i]) - 1;
		if (parse()->map_width < len_line)
			parse()->map_width = len_line;
		if ((parse()->scene[i][len_line] != '1'))
			err_case("walls not closed properly `23'\n");
		j = -1;
		while (parse()->scene[i][++j])
		{
			if ((parse()->scene[i][j]) == '1')
				break ;
			else if ((parse()->scene[i][j]) != ' ')
				err_case("walls not closed properly `24'\n");
		}
		i++;
	}
	return (0);
}
