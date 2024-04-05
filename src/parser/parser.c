/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:59:47 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/05 20:24:54 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	set_color_ceil_floor(char **rgb)
{
	return (ft_atoi(rgb[0]) << 16 | \
			ft_atoi(rgb[1]) << 8 | ft_atoi(rgb[2]));
}

static void	validate_elements(void)
{
	clean_nl();
	if (map_location() < 6)
		err_case("The file does not have a valid scene `18'\n");
	check_first_element();
	checking_duplicates();
	check_wall_texture();
	path_exists();
	clean_comma();
	check_rgb_number(cub()->rgb_f);
	check_rgb_number(cub()->rgb_c);
	cub()->color_f = set_color_ceil_floor(cub()->rgb_f);
	cub()->color_c = set_color_ceil_floor(cub()->rgb_c);
}

static void	validate_map(void)
{
	check_field();
	start_end_wall();
	closed_by_walls();
	closed_by_validfield(cub()->scene);
	get_map_dimension();
}

int	validate_scene(int argc, char *arg)
{
	if (argc != 2)
		err_case("Use: ./prog file.cub `19'\n");
	check_type(arg);
	cub()->scene = get_scene(arg);
	validate_elements();
	validate_map();
	return (0);
}
