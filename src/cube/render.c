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

static void	draw_wall(t_cube *cube, int ray, t_wall pix, double wall_height);

void	render_wall(t_cube *cube, int ray)
{
	double	wall_height;
	t_wall	pix;
	float	angle;

	angle = cube->r->angle - cube->p->angle;
	ft_angle_normal(&angle);
	cube->r->dist *= cos(angle);
	wall_height = (TILE_SIZE / cube->r->dist) * \
				((W_WIDTH / 2) / tan(FOV_RAD / 2));
	pix.bottom = (W_HEIGHT / 2) + (wall_height / 2);
	pix.top = (W_HEIGHT / 2) - (wall_height / 2);
	if (pix.bottom > W_HEIGHT)
		pix.bottom = W_HEIGHT;
	if (pix.top < 0)
		pix.top = 0;
	draw_wall(cube, ray, pix, wall_height);
}

void	render_rays(t_cube *cube)
{
	int				nry;
	t_raycast		*ray;
	t_vector_2d_f	intersection;

	ray = cube->r;
	ray->angle = cube->p->angle - 0.523599;
	nry = -1;
	while (++nry < (W_WIDTH * 2) || ray->angle <= (cube->p->angle + 0.523599))
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

static void	draw_wall(t_cube *cube, int ray, t_wall pix, double wall_height)
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
	position_o.y = (pix.top - (W_WIDTH / 2) + (wall_height / 2)) * ratio;
	if (position_o.y < 0)
		position_o.y = 0;
	while (pix.top < pix.bottom)
	{
		img_draw_pixel(&cube->img, ray, pix.top, (text_adrr[(int)position_o.y * \
						texture_painter.width + (int)position_o.x]));
		position_o.y += ratio;
		pix.top++;
	}
}
