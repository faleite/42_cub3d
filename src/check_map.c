/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/21 21:52:18 by faaraujo         ###   ########.fr       */
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
