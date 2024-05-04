/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:59:47 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/04 14:29:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
 DEBUG:
 print_data();
 print_struct_map();
*/
int	main(int argc, char *argv[])
{
	t_cube	cube;

	validate_scene(argc, argv[1]);
	init_values(&cube);
 	// print_struct_map();
	build_window(cube);
	return (0);
}
