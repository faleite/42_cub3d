/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/17 18:53:15 by faaraujo         ###   ########.fr       */
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

int	check_first_element(void)
{
	int	i;
	int	elemts;

	i = 0;
	elemts = 0;
	while (cub()->scene && cub()->scene[i] && i < cub()->start_map)
	{
		if (!iselement_wall(cub()->scene[i]) || \
			!iselement_cf(cub()->scene[i]))
			elemts++;
		else if (white_space(cub()->scene[i]))
			err_case("Error\nThe elements are not valid\n");
		i++;
	}
	if (elemts != 6)
		err_case("Error\nThe number of elements is not valid\n");
	i = cub()->end_map;
	while (cub()->scene && cub()->scene[++i])
	{
		if (white_space(cub()->scene[i]))
			err_case("Error\nElements after the map are not allowed\n");
	}
	return (0);
}

/* Utils 
 print_scene(elements, 1);
 printf("NO: %s\n", cub()->path_no);
*/
int	texture_path(char **elements)
{
	int	len;

	len = array_len(elements);
	if (len != 2)
	{
		free_arr(elements);
		err_case("Error\nInvalid texture element number\n");
	}
	else if (!strncmp(elements[0], NO, 3))
		cub()->path_no = ft_strdup(elements[1]);
	else if (!strncmp(elements[0], SO, 3))
		cub()->path_so = ft_strdup(elements[1]);
	else if (!strncmp(elements[0], WE, 3))
		cub()->path_we = ft_strdup(elements[1]);
	else if (!strncmp(elements[0], EA, 3))
		cub()->path_ea = ft_strdup(elements[1]);
	free_arr(elements);
	return (0);
}

/* Utils
 printf("Num elem: %d\n", len);
 printf("Num elem: %s\n", str);
 print_scene(cub()->rgb_f, 1);
*/
int	rgb_path(char *str)
{
	char	**elements;
	int		len;

	elements = ft_split(str, ' ');
	len = array_len(elements);
	if (len == 2)
	{
		if (!strncmp(elements[0], F, 2))
			cub()->rgb_f = ft_split(elements[1], ',');
		else if (!strncmp(elements[0], C, 2))
			cub()->rgb_c = ft_split(elements[1], ',');
	}
	else if (len == 4)
	{
		if (!strncmp(elements[0], F, 2))
			cub()->rgb_f = ft_rgbdup(elements);
		else if (!strncmp(elements[0], C, 2))
			cub()->rgb_c = ft_rgbdup(elements);
	}
	free_arr(elements);
	if (len > 4 || len < 2)
		err_case("Error\nInvalid rgb color element number\n");
	return (0);
}

int	check_wall_texture(void)
{
	char	**elements;
	int		i;

	i = 0;
	while (cub()->scene && cub()->scene[i] && i < cub()->start_map)
	{
		if (!white_space(cub()->scene[i]))
			i++;
		else if (!iselement_wall(cub()->scene[i]))
		{
			elements = ft_split(cub()->scene[i++], ' ');
			texture_path(elements);
		}
		else if (!iselement_cf(cub()->scene[i]))
		{
			rgb_path(cub()->scene[i]);
			i++;
		}
	}
	return (0);
}

int	check_rgb_utils(char **rgb)
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

int	check_rgb(void)
{
	check_rgb_utils(cub()->rgb_f);
	check_rgb_utils(cub()->rgb_c);
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
