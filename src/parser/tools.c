/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:11:42 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/06 21:15:40 by faaraujo         ###   ########.fr       */
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

t_parse	*parse(void)
{
	static t_parse	d;

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

void	free_parse(void)
{
	free_arr(parse()->scene);
	free(parse()->map);
	free_arr(parse()->rgb_c);
	free_arr(parse()->rgb_f);
	if (parse()->path_no != NULL)
		free(parse()->path_no);
	if (parse()->path_so != NULL)
		free(parse()->path_so);
	if (parse()->path_we != NULL)
		free(parse()->path_we);
	if (parse()->path_ea != NULL)
		free(parse()->path_ea);
}

void	err_case(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	free_parse();
	exit(EXIT_FAILURE);
}
