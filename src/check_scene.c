/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/14 21:57:27 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* CHECKS
 ELEM:
 - Elementos repetidos
 - Numero de argumentos de cada elemento
 - path
 - RGB de 0 a 255 
 
 MAP:
 - Linha vazia no meio do mapa
*/

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

int	first_element(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3) || \
		!ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3) || \
		!ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
		return (0);
	return (1);
}

int	white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_first_element(void)
{
	int	i;
	int	elemts;

	i = 0;
	elemts = 0;
	while (cub()->scene && cub()->scene[i] && i < cub()->start_map)
	{
		if (!first_element(cub()->scene[i]))
			elemts++;
		else if (white_space(cub()->scene[i]))
			err_case("Error\nOne of the elements is not valid\n");
		i++;
	}
	if (elemts != 6)
		err_case("Error\nThe number of elements is invalid\n");
	i = cub()->end_map;
	while (cub()->scene && cub()->scene[++i])
	{
		if (white_space(cub()->scene[i]))
			err_case("Error\nElements after the map are not allowed\n");
	}
	return (0);
}

// int	check_scene(void)
// {
// 	int	i;

	// heigth_map();
	// i = 0;
	// while (cub()->scene && cub()->scene[i])
	// {
	// 	if (check_side_wall(cub()->scene[i]))
	// 		err_case("Error\nThe cub should have a wall around it\n");
	// 	if (check_wall(cub()->scene[0])
	// 		|| check_wall(cub()->scene[cub()->size_y - 1]))
	// 		err_case("Error\nThe cub should have a valid wall around it\n");
	// 	if ((i > 0 && i < cub()->size_y - 1) && !check_wall(cub()->scene[i]))
	// 		err_case("Error\nInside the cub should not have a wall closed\n");
	// 	if (cub()->size_y < 3)
	// 		err_case("Error\nThe cub is not a valid cub\n");
	// 	if (check_len(cub()->scene[i]))
	// 		err_case("Error\nThe cub is not a type of rectangle\n");
	// 	i++;
	// }
	// if (check_field())
	// 	err_case("Error\nThe map contains one or more invalid fields\n");
// 	return (0);
// }
