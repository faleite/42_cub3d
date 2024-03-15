/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 19:27:52 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/15 19:33:09 by faaraujo         ###   ########.fr       */
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
