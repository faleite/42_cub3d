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

double	ft_get_postion(t_cube *cube, t_texture texture)
{
	double	position;

	if (cube->r->hit == 1)
	{
		position = (int)fmodf((cube->r->hor.x * \
		(texture.width / TILE_SIZE)), texture.width);
	}
	else
	{
		position = (int)fmodf((cube->r->ver.y * \
		(texture.width / TILE_SIZE)), texture.width);
	}
	return (position);
}

t_texture	ft_extract_text_up(t_cube *cube)
{
	float	angle;

	angle = cube->r->angle;
	ft_angle_normal(&angle);
	if (angle < M_PI && angle > 0)
		return (cube->tex_no);
	else
		return (cube->tex_so);
}

t_texture	ft_extract_text_side(t_cube *cube)
{
	float	angle;

	angle = cube->r->angle;
	ft_angle_normal(&angle);
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (cube->tex_we);
	else
		return (cube->tex_ea);
}
