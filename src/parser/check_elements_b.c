/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:56:48 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/06 20:14:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_duplicates(char *str, int len)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (parse()->scene && parse()->scene[i] && i < parse()->start_map)
	{
		if (!ft_strncmp(parse()->scene[i], str, len))
		{
			flag++;
			if (flag > 1)
				err_case("Duplicate element `5'\n");
		}
		i++;
	}
	return (0);
}

int	checking_duplicates(void)
{
	is_duplicates("NO ", 3);
	is_duplicates("SO ", 3);
	is_duplicates("WE ", 3);
	is_duplicates("EA ", 3);
	is_duplicates("F ", 2);
	is_duplicates("C ", 2);
	return (0);
}

static int	open_path(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	else
		close(fd);
	return (1);
}

static void	err_path(char *filename)
{
	ft_putstr_fd("Error\nThe file ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(" does not exist `6'\n", 2);
	free_parse();
	exit(EXIT_FAILURE);
}

int	path_exists(void)
{
	if (!open_path(parse()->path_no))
		err_path(parse()->path_no);
	else if (!open_path(parse()->path_so))
		err_path(parse()->path_so);
	else if (!open_path(parse()->path_we))
		err_path(parse()->path_we);
	else if (!open_path(parse()->path_ea))
		err_path(parse()->path_ea);
	return (0);
}
