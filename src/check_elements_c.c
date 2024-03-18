/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/18 19:01:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
