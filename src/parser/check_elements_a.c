/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/06 20:14:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_first_element(void)
{
	int	i;
	int	elemts;

	i = 0;
	elemts = 0;
	while (parse()->scene && parse()->scene[i] && i < parse()->start_map)
	{
		if (!iselement_wall(parse()->scene[i]) || \
			!iselement_cf(parse()->scene[i]))
			elemts++;
		else if (white_space(parse()->scene[i]))
			err_case("The elements are not valid `1'\n");
		i++;
	}
	if (elemts != 6)
		err_case("The number of elements is not valid `2'\n");
	i = parse()->end_map;
	while (parse()->scene && parse()->scene[++i])
	{
		if (white_space(parse()->scene[i]))
			err_case("Elements after the map are not allowed `3'\n");
	}
	return (0);
}

/* Utils 
 print_scene(elements, 1);
 printf("NO: %s\n", parse()->path_no);
*/
int	texture_path(char **elements)
{
	int	len;

	len = array_len(elements);
	if (len != 2)
	{
		free_arr(elements);
		err_case("Invalid texture element number `4'\n");
	}
	else if (!strncmp(elements[0], NO, 3))
		parse()->path_no = ft_strdup(elements[1]);
	else if (!strncmp(elements[0], SO, 3))
		parse()->path_so = ft_strdup(elements[1]);
	else if (!strncmp(elements[0], WE, 3))
		parse()->path_we = ft_strdup(elements[1]);
	else if (!strncmp(elements[0], EA, 3))
		parse()->path_ea = ft_strdup(elements[1]);
	free_arr(elements);
	return (0);
}

int	check_wall_texture(void)
{
	char	**elements;
	int		i;

	i = 0;
	while (parse()->scene && parse()->scene[i] && i < parse()->start_map)
	{
		if (!white_space(parse()->scene[i]))
			i++;
		else if (!iselement_wall(parse()->scene[i]))
		{
			elements = ft_split(parse()->scene[i++], ' ');
			texture_path(elements);
		}
		else if (!iselement_cf(parse()->scene[i]))
			check_rgb(parse()->scene[i++]);
	}
	return (0);
}
