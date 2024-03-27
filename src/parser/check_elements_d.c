/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:09 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/27 21:11:53 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_type(char *str)
{
	int		len;
	char	*type;

	len = ft_strlen(str);
	if (len <= 4)
		err_case("The argument must be a valid format: file.cub `7'\n");
	if (str[0] == '.')
		str += 1;
	type = ft_strchr(str, '.');
	if (!type)
		err_case("The argument must be a valid format: file.cub `8'\n");
	if (ft_strncmp(type, ".cub", 5))
		err_case("The argument must be a valid format: file.cub `9'\n");
	return (0);
}

int	iselement_wall(char *str)
{
	if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3) || \
		!ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3))
		return (0);
	return (1);
}

int	iselement_cf(char *str)
{
	if (!ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
		return (0);
	return (1);
}

int	white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (1);
	}
	return (0);
}

char	**ft_rgbdup(char **src)
{
	char	**dst;
	int		i;
	int		j;

	i = 1;
	j = 0;
	dst = ft_calloc(5, sizeof(char *));
	while (src && src[i])
	{
		dst[j] = ft_strdup(src[i]);
		j++;
		i++;
	}
	return (dst);
}
