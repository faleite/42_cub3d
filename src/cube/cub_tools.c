/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:34:03 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/07 18:21:28 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// t_img	*img(void)
// {
// 	static t_img	i;

// 	return (&i);
// }

// void	clear_frame(t_img frame)
// {
// 	char	*pixel;
// 	int		total;
// 	int		i;

// 	pixel = frame.addr;
// 	total = W_WIDTH * W_HEIGHT;
// 	i = 0;
// 	while (i < total)
// 	{
// 		*(int *)pixel = 0;
// 		pixel += 4;
// 		i++;
// 	}
// }

// inline void	img_draw_pixel(t_img img, t_pix_pos p, int color)
// {
// 	*(int *)(img.addr + 4 * (p.x + p.y * W_WIDTH)) = color;
// }

// void	put_img_to_window(t_cub *cub)
// {
// 	mlx_put_image_to_window(data()->mlx_ptr, data()->win_ptr, \
// 							cub->img.mlx_img, 0, 0);
// }

// t_cub	*cub(void)
// {
// 	static t_cub	c;

// 	return (&c);
// }

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