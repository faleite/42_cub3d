/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:42 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/04 21:43:37 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

t_cub	*cub(void)
{
	static t_cub	d;

	return (&d);
}

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
	if (cub()->path_no != NULL)
		free(cub()->path_no);
	if (cub()->path_so != NULL)
		free(cub()->path_so);
	if (cub()->path_we != NULL)
		free(cub()->path_we);
	if (cub()->path_ea != NULL)
		free(cub()->path_ea);
}

void	err_case(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	free_cub();
	exit(EXIT_FAILURE);
}
