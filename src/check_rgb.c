/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:53:08 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/25 18:48:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	*put_space(char *rgb);
static int	rgb_path(char *str);
static int	handle_comma(char *rgb);

int	check_rgb(char *str)
{
	char	*rgb;

	if (handle_comma(str) != 2)
		err_case("Invalid comma in rgb color element `14'\n");
	rgb = put_space(str);
	rgb_path(rgb);
	return (0);
}

int	check_rgb_number(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb && rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j]))
				err_case("Invalid rgb number `15'\n");
			j++;
		}
		if (!(ft_atoi(rgb[i]) >= 0 && ft_atoi(rgb[i]) <= 255))
			err_case("RGB number outside the range 0 to 255 `16'\n");
		i++;
	}
	return (0);
}

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
		free_arr(elements);
		err_case("Invalid rgb color element number `17'\n");
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
