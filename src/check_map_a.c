/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/22 21:18:13 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

static int	isvalid_field(char c)
{
	return (c == '0' || c == '1' || c == 'N' || \
			c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

static int	is_player(char c)
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
				err_case("The map contains invalid field\n");
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
		err_case("Expected one spawning orientation\n");
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
			err_case("start or end wall is not valid\n");
	}
	i = cub()->end_map;
	j = -1;
	while (cub()->scene[i][++j])
	{
		if (cub()->scene[i][j] != '1' && cub()->scene[i][j] != ' ')
			err_case("start or end wall is not valid\n");
	}
	return (0);
}
