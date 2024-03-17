/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:42 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/17 16:15:30 by faaraujo         ###   ########.fr       */
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

int	array_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i] != NULL)
	{
		free(arr[i++]);
	}
	free(arr);
}

void	free_cub(void)
{
	free_arr(cub()->scene);
	free_arr(cub()->rgb_c);
	free_arr(cub()->rgb_f);
	free(cub()->path_no);
	free(cub()->path_so);
	free(cub()->path_we);
	free(cub()->path_ea);
}

void	err_case(char *msg)
{
	ft_putstr_fd(msg, 2);
	if (cub()->scene)
		free_arr(cub()->scene);
	exit(EXIT_FAILURE);
}
