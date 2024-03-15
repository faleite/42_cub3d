/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:59:47 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/15 21:33:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validate_elements(void)
{
	clean_nl();
	if (map_location() < 6)
		err_case("Error\nThe file does not have a valid scene\n");
	check_first_element();
	check_wall_texture();
}

void	validate_map(int argc, char *arg)
{
	if (argc != 2)
		err_case("Error\nUse: ./prog file.cub\n");
	check_type(arg);
	cub()->scene = get_scene(arg);
	validate_elements();
	// printf("Start MAP: %d\n", cub()->start_map);
	// printf("End MAP: %d\n", cub()->end_map);
	// print_scene(cub()->scene, 0);
	// check_scene();
	// if (playable_map())
	// 	err_case("Error\nThe map is not valid\n");
	free_arr(cub()->scene);
	// map()->matrix = copy_map(argv);
}

int	main(int argc, char *argv[])
{
	validate_map(argc, argv[1]);
	// build_window();
	return (0);
}
