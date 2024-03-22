/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/22 21:18:35 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			err_case("walls not closed properly `1'\n");
		j = -1;
		while (cub()->scene[i][++j])
		{
			if ((cub()->scene[i][j]) == '1')
				break ;
			else if ((cub()->scene[i][j]) != ' ')
				err_case("walls not closed properly `2'\n");
		}
		i++;
	}
	return (0);
}

// int	invalid_field(void)
// {
// 	int	i;
// 	int	j;
// 	int	other;

// 	i = 0;
// 	other = 0;
// 	while (map()->matrix && map()->matrix[i])
// 	{
// 		j = 0;
// 		while (map()->matrix[i][j])
// 		{
// 			if (map()->matrix[i][j] != 'E' && map()->matrix[i][j] != 'P'
// 				&& map()->matrix[i][j] != 'C' && map()->matrix[i][j] != '1'
// 				&& map()->matrix[i][j] != '0' && map()->matrix[i][j] != '\n')
// 				other++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (other);
// }

// int	count_field(void)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	if (invalid_field())
// 		return (1);
// 	while (map()->matrix && map()->matrix[i])
// 	{
// 		j = 0;
// 		while (map()->matrix[i][j])
// 		{
// 			if (map()->matrix[i][j] == 'E')
// 				field()->out++;
// 			if (map()->matrix[i][j] == 'P')
// 				field()->player++;
// 			if (map()->matrix[i][j] == 'C')
// 				field()->collect++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// int	check_field(void)
// {
// 	if (count_field())
// 		return (1);
// 	if (field()->out != 1)
// 		err_case("Error\nThere must be a way out of this game\n");
// 	if (field()->player != 1)
// 		err_case("Error\nThere must be a player in this game\n");
// 	if (field()->collect < 1)
// 		err_case("Error\nThere must be at least one collectible in this game\n");
// 	return (0);
// }

// int	check_scene(void)
// {
// 	int	i;

// 	heigth_map();
// 	i = 0;
// 	while (cub()->scene && cub()->scene[i])
// 	{
// 		if (check_side_wall(cub()->scene[i]))
// 			err_case("Error\nThe cub should have a wall around it\n");
// 		if (check_wall(cub()->scene[0])
// 			|| check_wall(cub()->scene[cub()->size_y - 1]))
// 			err_case("Error\nThe cub should have a valid wall around it\n");
// 		if ((i > 0 && i < cub()->size_y - 1) && !check_wall(cub()->scene[i]))
// 			err_case("Error\nInside the cub should not have a wall closed\n");
// 		if (cub()->size_y < 3)
// 			err_case("Error\nThe cub is not a valid cub\n");
// 		if (check_len(cub()->scene[i]))
// 			err_case("Error\nThe cub is not a type of rectangle\n");
// 		i++;
// 	}
// 	if (check_field())
// 		err_case("Error\nThe map contains one or more invalid fields\n");
// 	return (0);
// }
