/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/04 18:34:20 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	one_space(char c)
{
	return (c == '1' || c == ' ' || c == '\0');
}

static int	one_zero(char c)
{
	return (c == '1' || c == '0');
}

static int	check_fence(char *s2, int j, int flag, char c)
{
	int	len;

	len = ft_strlen(s2);
	if (c == 32 && j < len)
	{
		if (!flag && (!one_space(s2[j - 1]) || !one_space(s2[j + 1])))
			err_case("Invalid map (bad field around ' ') `25'\n");
		else if (flag && (!one_space(s2[j - 1]) || !one_space(s2[j + 1]) \
				|| !one_space(s2[j])))
			err_case("Invalid map (bad field around ' ') `26'\n");
	}
	else if (c == 48 && j < len)
	{
		if (!flag && ((!one_zero(s2[j - 1]) && !is_player(s2[j - 1])) || \
			(!one_zero(s2[j + 1]) && !is_player(s2[j + 1]))))
			err_case("Invalid map (bad field around '0') `27'\n");
		else if (flag && ((!one_zero(s2[j - 1]) && !is_player(s2[j - 1])) || \
				(!one_zero(s2[j + 1]) && !is_player(s2[j + 1])) || \
				(!one_zero(s2[j]) && !is_player(s2[j]))))
			err_case("Invalid map (bad field around '0') `28'\n");
	}
	return (0);
}

static void	space_zero(char **map, int i, int j, char c)
{
	if (c == 32)
	{
		check_fence(map[i - 1], j, 1, c);
		check_fence(map[i], j, 0, c);
		check_fence(map[i + 1], j, 1, c);
	}
	else if (c == 48)
	{
		check_fence(map[i - 1], j, 1, c);
		check_fence(map[i], j, 0, c);
		check_fence(map[i + 1], j, 1, c);
	}
}

/*
DEBUG (after line 78):
printf("line: %d, field: %d\n", i, j);
*/
int	closed_by_validfield(char **map)
{
	int	i;
	int	j;

	i = cub()->start_map;
	while (++i < cub()->end_map)
	{
		j = 0;
		while (map[i][++j])
		{
			space_zero(map, i, j, map[i][j]);
			if (is_player(map[i][j]))
			{
				if (!one_zero(map[i][j - 1]) || !one_zero(map[i][j + 1]))
					err_case("Invalid map (bad field around 'P') `29'\n");
				if (!one_zero(map[i - 1][j - 1]) || \
					!one_zero(map[i - 1][j + 1]) || !one_zero(map[i - 1][j]))
					err_case("Invalid map (bad field around 'P') `30'\n");
				if (!one_zero(map[i + 1][j - 1]) || \
					!one_zero(map[i + 1][j + 1]) || !one_zero(map[i + 1][j]))
					err_case("Invalid map (bad field around 'P') `31'\n");
			}
		}
	}
	return (0);
}
