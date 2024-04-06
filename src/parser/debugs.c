/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:27:52 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/06 20:14:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_scene(char **file, int nl)
{
	int	i;

	i = 0;
	while (file && file[i] != NULL)
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

	i = parse()->start_map;
	while (file[i] != NULL && i <= parse()->end_map)
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
	printf("NO: %s\n", parse()->path_no);
	printf("SO: %s\n", parse()->path_so);
	printf("WE: %s\n", parse()->path_we);
	printf("EA: %s\n", parse()->path_ea);
	printf("\n/* RGB COLOR */\n");
	printf("FLOOR:\n");
	print_scene(parse()->rgb_f, 1);
	printf("CEILING:\n");
	print_scene(parse()->rgb_c, 1);
	printf("/* MAP */\n");
	printf("\nSTART MAP: line %d ", parse()->start_map + 1);
	printf("END MAP: line %d\n\n", parse()->end_map + 1);
	print_map(parse()->scene, 1);
}
