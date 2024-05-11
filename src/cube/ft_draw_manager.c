/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-pma <juan-pma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 09:13:46 by juan-pma          #+#    #+#             */
/*   Updated: 2024/05/11 09:13:46 by juan-pma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

void	draw_rays(t_image *img, t_vt_f p, t_vt_d r)
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

void drawCircleWithCross(t_cube *cube)
{

    t_vector_2d center;
	t_vector_2d coord;
    int radious;
	double angle;

    center.x = W_WIDTH / 2;
    center.y = W_HEIGHT / 2;
    radious = 50;
	angle = 0;
    while (angle < 360)
	{
        coord.x = center.x + (int)(radious * cos(angle * M_PI / 180));
        coord.y = center.y + (int)(radious * sin(angle * M_PI / 180));
        img_draw_pixel(&cube->img, coord.x, coord.y, RED);
		angle+= 0.1;
	}
	coord.y = center.y - radious;
    while ( coord.y++ <= center.y + radious)
        img_draw_pixel(&cube->img, center.x, coord.y, WHITE);
	coord.x = center.x - radious;
    while ( coord.x++ <= center.x + radious)
        img_draw_pixel(&cube->img, coord.x, center.y, WHITE);
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