/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <juan-pma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 08:55:56 by juan-pma          #+#    #+#             */
/*   Updated: 2024/05/11 08:55:56 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	image_error(t_cube *cube)
{
	destroy_image(cube);
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	mlx_destroy_display(cube->mlx_ptr);
	free(cube->mlx_ptr);
	free_data(cube);
	err_case("Image doesn't work\n");
}

/* TEXTURE */
void	get_data_texture(t_cube *cube)
{
	cube->tex_no.img.addr = mlx_get_data_addr(cube->tex_no.img.mlx_img, \
						&cube->tex_no.img.bpp, &cube->tex_no.img.line_len, \
						&cube->tex_no.img.endian);
	cube->tex_so.img.addr = mlx_get_data_addr(cube->tex_so.img.mlx_img, \
						&cube->tex_so.img.bpp, &cube->tex_so.img.line_len, \
						&cube->tex_so.img.endian);
	cube->tex_we.img.addr = mlx_get_data_addr(cube->tex_we.img.mlx_img, \
						&cube->tex_we.img.bpp, &cube->tex_we.img.line_len, \
						&cube->tex_we.img.endian);
	cube->tex_ea.img.addr = mlx_get_data_addr(cube->tex_ea.img.mlx_img, \
						&cube->tex_ea.img.bpp, &cube->tex_ea.img.line_len, \
						&cube->tex_ea.img.endian);
}

int	texture_xpm_to_image(t_cube *cube)
{
	cube->tex_no.img.mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
				parse()->path_no, &cube->tex_no.width, &cube->tex_no.height);
	cube->tex_so.img.mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
				parse()->path_so, &cube->tex_so.width, &cube->tex_so.height);
	cube->tex_we.img.mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
				parse()->path_we, &cube->tex_we.width, &cube->tex_we.height);
	cube->tex_ea.img.mlx_img = mlx_xpm_file_to_image(cube->mlx_ptr, \
				parse()->path_ea, &cube->tex_ea.width, &cube->tex_ea.height);
	if (!cube->tex_no.img.mlx_img || !cube->tex_so.img.mlx_img \
		|| !cube->tex_we.img.mlx_img || !cube->tex_ea.img.mlx_img)
		image_error(cube);
	get_data_texture(cube);
	return (0);
}