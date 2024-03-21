/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/21 20:29:23 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	clean_comma_utils(char **rgb)
{
	int	i;
	int	len;

	i = 0;
	while (rgb && rgb[i] && i < 2)
	{
		len = ft_strlen(rgb[i]) - 1;
		if (rgb[i][len] == ',')
			rgb[i][len] = '\0';
		i++;
	}
	return (0);
}

int	clean_comma(void)
{
	clean_comma_utils(cub()->rgb_f);
	clean_comma_utils(cub()->rgb_c);
	return (0);
}
