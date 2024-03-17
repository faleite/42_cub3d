/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:27:52 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/17 16:14:29 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_scene(char **file, int nl)
{
	int	i;

	i = 0;
	while (file[i] != NULL)
	{
		if (nl)
			printf("%s\n", file[i++]);
		else if (!nl)
			printf("%s", file[i++]);
	}
	printf("\n");
}

void	print_map(char **file, int nl)
{
	int	i;

	i = cub()->start_map;
	while (file[i] != NULL && i <= cub()->end_map)
	{
		if (nl)
			printf("%s\n", file[i++]);
		else if (!nl)
			printf("%s", file[i++]);
	}
	printf("\n");
}

void	print_data(void)
{
	printf("/* TEXTURE PATH */\n");
	printf("NO: %s\n", cub()->path_no);
	printf("SO: %s\n", cub()->path_so);
	printf("WE: %s\n", cub()->path_we);
	printf("EA: %s\n", cub()->path_ea);
	printf("\n/* RGB COLOR */\n");
	printf("FLOOR:\n");
	print_scene(cub()->rgb_f, 1);
	printf("CEILING:\n");
	print_scene(cub()->rgb_c, 1);
	printf("/* MAP */\n");
	printf("START MAP: line %d ", cub()->start_map + 1);
	printf("END MAP: line %d\n", cub()->end_map + 1);
	print_map(cub()->scene, 1);
}
