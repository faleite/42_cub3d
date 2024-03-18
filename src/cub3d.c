/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:59:47 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/18 21:09:57 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validate_elements(void)
{
	clean_nl();
	if (map_location() < 6)
		err_case("Error\nThe file does not have a valid scene\n");
	check_first_element();
	checking_duplicates();
	check_wall_texture();
	path_exists();
	clean_comma();
}

/* CHECKS
 ELEM:
 - RGB de 0 a 255 
 
 MAP:
 - Linha vazia no meio do mapa
*/
void	validate_map(int argc, char *arg)
{
	if (argc != 2)
		err_case("Error\nUse: ./prog file.cub\n");
	check_type(arg);
	cub()->scene = get_scene(arg);
	validate_elements();
	print_data();
	// print_scene(cub()->scene, 0);
	// check_scene();
	// if (playable_map())
	// 	err_case("Error\nThe map is not valid\n");
	free_cub();
}

int	main(int argc, char *argv[])
{
	validate_map(argc, argv[1]);
	// build_window();
	return (0);
}
