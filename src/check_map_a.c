/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/25 22:09:01 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

	i = cub()->start_map;
	player = 0;
	while (cub()->scene[i] && i <= cub()->end_map)
	{
		j = -1;
		while (cub()->scene[i][++j])
		{
			if (!isvalid_field(cub()->scene[i][j]))
				err_case("The map contains invalid field `10'\n");
			else if (is_player(cub()->scene[i][j]))
			{
				player++;
				cub()->orientation = cub()->scene[i][j];
				cub()->pos_x = i;
				cub()->pos_y = j;
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

	i = cub()->start_map;
	j = -1;
	while (cub()->scene[i][++j])
	{
		if (cub()->scene[i][j] != '1' && cub()->scene[i][j] != ' ')
			err_case("start or end wall is not valid `12'\n");
	}
	i = cub()->end_map;
	j = -1;
	while (cub()->scene[i][++j])
	{
		if (cub()->scene[i][j] != '1' && cub()->scene[i][j] != ' ')
			err_case("start or end wall is not valid `13'\n");
	}
	return (0);
}

int	closed_by_walls(void)
{
	int	i;
	int	j;
	int	last_char;

	i = cub()->start_map;
	while (cub()->scene[i] && i <= cub()->end_map)
	{
		last_char = ft_strlen(cub()->scene[i]) - 1;
		if ((cub()->scene[i][last_char] != '1'))
			err_case("walls not closed properly `23'\n");
		j = -1;
		while (cub()->scene[i][++j])
		{
			if ((cub()->scene[i][j]) == '1')
				break ;
			else if ((cub()->scene[i][j]) != ' ')
				err_case("walls not closed properly `24'\n");
		}
		i++;
	}
	return (0);
}
