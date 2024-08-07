/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:59:47 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/12 15:44:03 by faaraujo         ###   ########.fr       */
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
	parse()->map_height = parse()->end_map - parse()->start_map;
	check_first_element();
	checking_duplicates();
	check_wall_texture();
	path_exists();
	clean_comma();
	check_rgb_number(parse()->rgb_f);
	check_rgb_number(parse()->rgb_c);
	if (parse()->rgb_f[0][0] == '\0' || parse()->rgb_c[0][0] == '\0')
		err_case("Invalid rgb `99'\n");
	else
	{
		parse()->color_f = set_color_ceil_floor(parse()->rgb_f);
		parse()->color_c = set_color_ceil_floor(parse()->rgb_c);
	}
}

static void	validate_map(void)
{
	check_field();
	start_end_wall();
	closed_by_walls();
	closed_by_validfield(parse()->scene);
	parse()->map = get_map();
	map()->map = parse()->map;
	map()->map_height = parse()->end_map - parse()->start_map;
	map()->map_width = parse()->map_width;
	get_player();
}

int	validate_scene(int argc, char *arg)
{
	if (argc != 2)
		err_case("Use: ./cub3D file.cub `19'\n");
	check_type(arg);
	parse()->scene = get_scene(arg);
	validate_elements();
	validate_map();
	return (0);
}
