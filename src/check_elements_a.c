/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/19 18:48:57 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
			check_rgb(cub()->scene[i++]);
	}
	return (0);
}
