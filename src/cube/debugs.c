/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debugs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:45:55 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/17 20:27:30 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_int_map(int **map)
{
	int	i;
	int	j;

	i = 0;
	while (i <= parse()->map_height)
	{
		j = -1;
		while (++j <= parse()->map_width)
		{
			printf("%d ", map[i][j]);
		}
		printf("\n");
		i++;
	}
}
