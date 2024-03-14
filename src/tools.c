/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:42 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/14 21:46:05 by faaraujo         ###   ########.fr       */
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

void	free_scene(char **scene)
{
	int	i;

	i = 0;
	while (scene[i] != NULL)
	{
		free(scene[i++]);
	}
	free(scene);
}

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

void	err_case(char *msg)
{
	ft_putstr_fd(msg, 2);
	if (cub()->scene)
		free_scene(cub()->scene);
	exit(EXIT_FAILURE);
}
