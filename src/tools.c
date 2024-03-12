/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:42 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/12 22:12:27 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cub	*cub(void)
{
	static t_cub	d;

	return (&d);
}

// t_field	*field(void)
// {
// 	static t_field	f;

// 	return (&f);
// }

// t_img	*img(void)
// {
// 	static t_img	i;

// 	return (&i);
// }

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i++]);
	}
	free(map);
}

void	print_scene(char **file)
{
	int	i;

	i = 0;
	while (file[i] != NULL)
	{
		printf("%s", file[i++]);
	}
	printf("\n");
}

void	err_case(char *msg)
{
	ft_putstr_fd(msg, 2);
	// if (map()->matrix)
	// 	free_map(map()->matrix);
	exit(EXIT_FAILURE);
}
