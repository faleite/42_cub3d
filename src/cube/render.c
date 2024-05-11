/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:24:05 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/03 21:18:06 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * draw the wall
*/

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
		return (cube->tex_so);
	else
		return (cube->tex_no);
}


t_texture	ft_extract_text_side(t_cube *cube)
{
	float	angle;

	angle = cube->r->angle;
	ft_angle_normal(&angle);
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (cube->tex_ea);
	else
		return (cube->tex_we);
}

void	draw_wall(t_cube *cube, int ray, int t_pix,\
		int b_pix, double wall_height)
{
	t_vector_2dob	position_o;
	t_texture		texture_painter;
	int				*text_adrr;
	double			ratio;

	if (cube->r->hit)
		texture_painter = ft_extract_text_up(cube);
	else
		texture_painter = ft_extract_text_side(cube);
	ratio = (double)texture_painter.height / wall_height ;
	position_o.x = ft_get_postion(cube, texture_painter);
	text_adrr = (int *)texture_painter.img.addr;
	position_o.y = (t_pix - (W_WIDTH / 2) + (wall_height / 2)) * ratio;
	if (position_o.y < 0)
		position_o.y = 0;
	while (t_pix < b_pix)
	{
		img_draw_pixel(&cube->img, ray, t_pix, \
           (text_adrr[(int)position_o.y * texture_painter.width + (int)position_o.x]));
		position_o.y += ratio;
		t_pix++;
	}
}

void	render_wall(t_cube *cube, int ray)
{
	double			wall_height;
	double			bottom;
	double			top;
	float			angle;

	angle = cube->r->angle - cube->p->angle;
	ft_angle_normal(&angle);
	cube->r->dist *= cos(angle);
	wall_height = (TILE_SIZE / cube->r->dist) * \
				((W_WIDTH / 2) / tan(FOV_RAD / 2));
	bottom = (W_HEIGHT / 2) + (wall_height / 2);
	top = (W_HEIGHT / 2) - (wall_height / 2);
	if (bottom > W_HEIGHT)
		bottom = W_HEIGHT;
	if (top < 0)
		top = 0;
	draw_wall(cube, ray, top, bottom, wall_height);
}

void	render_rays(t_cube *cube)
{
	int				nry;
	t_raycast		*ray;
	t_vector_2d_f	intersection;

	ray = cube->r;
	ray->angle = cube->p->angle - 0.523599;
	nry = -1;
	while (++nry <  (W_WIDTH * 2) || ray->angle <= (cube->p->angle + 0.523599))
	{
		ray->hit = 0;
		intersection.x = calc_hor_distance(cube, ray->angle);
		intersection.y = calc_vertical_distance(cube, ray->angle);
		if (intersection.y < intersection.x)
		{
			ray->dist = intersection.y;
			draw_rays(&cube->img, cube->p->pos, ray->ver);
		}
		else
		{
			ray->dist = intersection.x;
			ray->hit = 1;
			draw_rays(&cube->img, cube->p->pos, ray->hor);
		}
		ray->angle += 0.0002757;
	}
}
