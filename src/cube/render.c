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

double ft_get_postion(t_cube *cube, t_texture texture)
{
	double position;
	double cell;

	if (cube->r->hit == 1)
	{
		cell = floor(cube->r->hor.x / TILE_SIZE);
		position = cube->r->hor.x - (cell * TILE_SIZE);
		// position = (int)fmodf((cube->r->hor.x * \
		// (texture.width / TILE_SIZE)), texture.width);
	}
	else
	{
		cell = floor(cube->r->ver.y / TILE_SIZE);
		position = cube->r->hor.x - (cell * TILE_SIZE);
		// position = (int)fmodf((cube->r->ver.y * \
		// (texture.width / TILE_SIZE)), texture.width);
	}
	return (position);
}

t_texture ft_extract_text_up(t_cube *cube)
{
	if (cube->r->angle < M_PI && cube->r->angle > 0)
		return(cube->tex_so);
	else
		return(cube->tex_no);
}


t_texture ft_extract_text_side(t_cube *cube)
{
	if (cube->r->angle > M_PI / 2 && cube->r->angle < 3 * M_PI / 2)
		return(cube->tex_ea);
	else
		return(cube->tex_we);
}

void	draw_wall(t_cube *cube, int ray, int t_pix, int b_pix, double wall_height)
{
	t_vector_2d position;
	unsigned int texure;
	t_texture texture_painter;
	double ratio;
	
	if (cube->r->hit)
		texture_painter = ft_extract_text_up(cube);
	else
		texture_painter = ft_extract_text_side(cube);
	// ratio = (double)texture_painter.height / wall_height;
	ratio = (double)texture_painter.height / wall_height ;
	position.x = ft_get_postion(cube, texture_painter);
	// position.y = (t_pix - b_pix) * ratio;
	position.y = (t_pix - (W_HEIGHT / 2) + (wall_height / 2) * ratio);
	if (position.y < 0)
		position.y = 0;
	int posy = position.y;
	while (t_pix < b_pix)
	{
		img_draw_pixel(&cube->img, ray, t_pix, \
            wall_draw_pixel(texture_painter, ray, position.y));
		position.y+= ratio;
		if(position.y > b_pix)
			break;
		t_pix++;
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
	pixels.x = floor(W_HEIGHT / 2) + floor(wall_height / 2);
	pixels.y = floor(W_HEIGHT / 2) - floor(wall_height / 2);
	if (pixels.x > W_HEIGHT)
		pixels.x = W_HEIGHT;
	if (pixels.y < 0)
		pixels.y = 0;
	draw_wall(cube, ray, pixels.y, pixels.x, wall_height);
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

int	draw_ceil_floor(t_image *img)
{
	t_vt_d	pos;

	pos.y = -1;
	while (++pos.y < W_HEIGHT / 2)
	{
		pos.x = -1;
		while (++pos.x < W_WIDTH)
			img_draw_pixel(img, pos.x, pos.y, parse()->color_c);
	}
	while (pos.y < W_HEIGHT)
	{
		pos.x = -1;
		while (++pos.x < W_WIDTH)
			img_draw_pixel(img, pos.x, pos.y, parse()->color_f);
		++pos.y;
	}
	return (0);
}
