/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:53:08 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/18 21:03:55 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* Utils
 printf("Num elem: %d\n", len);
 printf("Num elem: %s\n", str);
 print_scene(cub()->rgb_f, 1);
*/
static int	rgb_path(char *str)
{
	char	**elements;
	int		len;

	elements = ft_split(str, ' ');
	free(str);
	len = array_len(elements);
	if (len < 5)
	{
		if (!strncmp(elements[0], F, 2))
			cub()->rgb_f = ft_rgbdup(elements);
		else if (!strncmp(elements[0], C, 2))
			cub()->rgb_c = ft_rgbdup(elements);
		free_arr(elements);
	}
	else
	{
		ft_putstr_fd("Error\nInvalid rgb color element number\n", 2);
		free_arr(elements);
		free_cub();
		exit(EXIT_FAILURE);
	}
	return (0);
}

static int	handle_comma(char *rgb)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (rgb && rgb[i])
	{
		if (rgb[i] == ',' && (rgb[i + 1] == '\0' || rgb[i + 1] == ','))
			return (1);
		if (rgb[i] == ',')
			comma++;
		i++;
	}
	return (comma);
}

static char	*put_space(char *rgb)
{
	char	*new_rgb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_rgb = malloc(sizeof(char) * (ft_strlen(rgb) * 2));
	if (!new_rgb)
		return (NULL);
	while (rgb && rgb[i])
	{
		if (rgb[i] == ',')
		{
			new_rgb[j++] = rgb[i++];
			new_rgb[j++] = ' ';
		}
		else
			new_rgb[j++] = rgb[i++];
	}
	new_rgb[j] = '\0';
	return (new_rgb);
}

int	check_rgb(char *str)
{
	char	*rgb;

	if (handle_comma(str) != 2)
		err_case("Error\nInvalid comma in rgb color element\n");
	rgb = put_space(str);
	rgb_path(rgb);
	return (0);
}
