/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:59:47 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/12 22:13:04 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validate_map(int argc, char *arg)
{
	if (argc != 2)
		err_case("Error\nUse: ./prog file.cub\n");
	check_type(arg);
	cub()->scene = get_scene(arg);
	print_scene(cub()->scene);
	// check_map();
	// if (playable_map())
	// 	err_case("Error\nThe map is not valid\n");
	free_map(cub()->scene);
	// map()->matrix = copy_map(argv);
}

int	main(int argc, char *argv[])
{
	validate_map(argc, argv[1]);
	// build_window();
	return (0);
}
