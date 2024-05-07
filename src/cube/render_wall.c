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
void	draw_wall(t_cube *cube, int ray, int t_pix, int b_pix)
{
	while (t_pix < b_pix)
	{
		if (cube->r->hit)
		{
			if (cube->r->angle < M_PI && cube->r->angle > 0)
				img_draw_pixel(&cube->img, ray, t_pix++, ORANGE);
			else
				img_draw_pixel(&cube->img, ray, t_pix++, RED);
		}
		else
		{
			if (cube->r->angle > M_PI / 2 && cube->r->angle < 3 * M_PI / 2)
				img_draw_pixel(&cube->img, ray, t_pix++, GREEN);
			else
				img_draw_pixel(&cube->img, ray, t_pix++, BLACK);
		}
	}
}

void	render_wall(t_cube *cube, int ray)
{
	t_vector_2d_f	intersection;
	t_vector_2d_f	pixels;
	double			wall_height;
	float			angle;

	angle = cube->r->angle - cube->p->angle;
	ft_angle_normal(&angle);
	cube->r->dist *= cos(angle);
	wall_height = (TILE_SIZE / cube->r->dist) * \
				((W_WIDTH / 2) / tan(FOV_RAD / 2));
	pixels.x = (W_HEIGHT / 2) + (wall_height / 2);
	pixels.y = (W_HEIGHT / 2) - (wall_height / 2);
	if (pixels.x > W_HEIGHT)
		pixels.x = W_HEIGHT;
	if (pixels.y < 0)
		pixels.y = 0;
	draw_wall(cube, ray, pixels.y, pixels.x);
}

static void	draw_rays(t_image *img, t_vt_f p, t_vt_d r)
{
	t_vt_d	player;
	t_vt_d	ray;
	int		scale;

	scale = MAP_SCALE;
	if (parse()->map_height > 20 || parse()->map_width > 40)
		scale /= 2;
	player.x = p.x / (TILE_SIZE / scale);
	player.y = p.y / (TILE_SIZE / scale);
	ray.x = r.x / (TILE_SIZE / scale);
	ray.y = r.y / (TILE_SIZE / scale);
	ft_bresenham(img, player, ray, YELLOW);
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
