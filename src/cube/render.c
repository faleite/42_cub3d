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

// int get_tex_x(t_cube *cube, t_ray *ray, t_image *tex)
// {
//   // Calculating exact hit position
//   double perp_angle = PI_2 - ray->angle + cube->p->angle;
//   double  hit_length = ray->distance * 0.5f * TILE_SIZE / sin(perp_angle);
//   t_vt_f wall_x = create_vect_f_from_origin(cube->player.pos, ray->angle, hit_length);

//   float cell_pos;
//   // Getting hit position relative to the cell
//   if (ray->side_hit == 1 || ray->side_hit == 3) // Horizontal hit
//     cell_pos = wall_x.y - (int)(wall_x.y / data->cell_size) * data->cell_size;
//   else // Vertical hit
//     cell_pos = wall_x.x - (int)(wall_x.x / data->cell_size) * data->cell_size;

//   if (ray->side_hit == 3 || ray->side_hit == 2) // Converting cell_pos to ratio
//     cell_pos = cell_pos / data->cell_size;
//   else // Flip texture if the side hit is the top or the right side of a cell
//     cell_pos = 1.0f - cell_pos / data->cell_size;

//   int tex_x = cell_pos * texture->width_img; // Mapping ratio to texture dimension

//   return (tex_x);
// }

unsigned int	wall_draw_pixel_1(t_image tex, int x, int y)
{
	return (*(int *)(tex.addr + 4 * (x + y * tex.width)));
}

int ft_get_postion(t_cube *cube)
{
	float position;

	if (cube->r->hit == 1)
	{
		position = fmod(cube->r->hor.x * (cube->tex_ea.width / TILE_SIZE), cube->tex_ea.width);
	}
	else
	{
		position = fmod(cube->r->ver.y * (cube->tex_ea.width / TILE_SIZE), cube->tex_ea.width);
	}
	return (position);
}

void	draw_wall(t_cube *cube, int ray, int t_pix, int b_pix, double wall_height)
{
	t_vector_2d position;
	unsigned int texure;
	double ratio;

	ratio = cube->tex_ea.height / wall_height;
	position.x = ft_get_postion(cube);
	position.y = (t_pix - (W_WIDTH / 2) + (wall_height / 2) * ratio);

	if (position.y < 0)
		position.y = 0;
	while (t_pix < b_pix)
	{
		// img_draw_pixel(&cube->img, ray, t_pix++, \
            wall_draw_pixel(&cube->tex_ea, ray, position.y));
		img_draw_pixel(&cube->img, ray, t_pix++, \
            wall_draw_pixel_1(cube->tex_ea, ray, position.y));
		position.y += ratio;
		// if (cube->r->hit)
		// {
		// 	if (cube->r->angle < M_PI && cube->r->angle > 0)
		// 		img_draw_pixel(&cube->img, ray, t_pix++, ORANGE);
		// 	else
		// 		img_draw_pixel(&cube->img, ray, t_pix++, RED);
		// }
		// else
		// {
		// 	if (cube->r->angle > M_PI / 2 && cube->r->angle < 3 * M_PI / 2)
		// 		img_draw_pixel(&cube->img, ray, t_pix++, GREEN);
		// 	else
		// 		img_draw_pixel(&cube->img, ray, t_pix++, BLACK);
		// }
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
