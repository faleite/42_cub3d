/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:34:09 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/12 21:09:58 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_type(char *str)
{
	int		len;
	char	*type;

	len = ft_strlen(str);
	if (len <= 4)
		err_case("Error\nThe argument must be a valid format: file.cub 1\n");
	type = ft_strchr(str, '.');
	if (!type)
		err_case("Error\nThe argument must be a valid format: file.cub 2\n");
	if (ft_strncmp(type, ".cub", 5))
		err_case("Error\nThe argument must be a valid format: file.cub 3\n");
	return (0);
}

// int	check_side_wall(char *line)
// {
// 	int	len;

// 	len = ft_strlen(line);
// 	len -= (line[len - 1] == '\n');
// 	if (len >= 60)
// 		err_case("Error\nThe map is not the ideal size for the screen\n");
// 	if (map()->size_x == 0)
// 		map()->size_x = len;
// 	if (line[0] == '1' && line[len - 1] == '1')
// 		return (0);
// 	return (1);
// }

// int	check_wall(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (i < map()->size_x)
// 	{
// 		if (line[i] == '1')
// 			i++;
// 		else
// 			return (1);
// 	}
// 	return (0);
// }

// void	heigth_map(void)
// {
// 	int	i;

// 	i = 0;
// 	while (map()->matrix && map()->matrix[i])
// 		i++;
// 	if (i > 32)
// 		err_case("Error\nThe map is not the ideal size for the screen\n");
// 	if (map()->size_y == 0)
// 		map()->size_y = i;
// }

// int	check_len(char *line)
// {
// 	int	len;

// 	len = ft_strlen(line);
// 	len -= (line[len - 1] == '\n');
// 	if (len != map()->size_x)
// 		return (1);
// 	return (0);
// }
