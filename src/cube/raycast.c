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

int	unit_circle(float angle, char c);
int	calc_step(float angle, float *inter, float *step, int is_horizon);
int	hit_wall_m(float x, float y);
int ft_check_distance(t_vt_f p1, t_vector_2d_f p2);

void	draw_player_screen(t_image *img, int x, int y)
{
	t_vt_d	p;

	p.y = 0;
	while (p.y < TILE_SIZE / 2)
	{
		p.x = 0;
		while (p.x < TILE_SIZE / 2)
		{
			img_draw_pixel(img, x + p.x, y + p.y, RED);
			p.x++;
		}
		p.y++;
	}
}

void	draw_line_screen(int x, int p_y, int p_x, t_image *img, double dir, double perp)
{
	t_line	line;

	line.x0 = x;
	line.y0 = p_y;
	line.x1 = p_x + cos(dir) * perp;
	line.y1 = p_y + sin(dir) * perp;
	brasenham(line, img, WHITE);
}

void	draw_wall(int i, int start, int end, t_image *img, int color)
{
	t_line	line;

	line.x0 = i;
	line.y0 = start;
	line.x1 = i;
	line.y1 = end;
	brasenham(line, img, color);
}

int	hit_wall_m(float x, float y)
{
	int		x_m;
	int		y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / TILE_SIZE);
	y_m = floor (y / TILE_SIZE);
	if ((y_m >= map()->map_height || x_m >= map()->map_width))
		return (0);
	if (map()->map[y_m] && x_m <= (int)strlen(map()->map[y_m]))
		if (map()->map[y_m][x_m] == '1')
			return (0);
	return (1);
}

/**
 * calculate the distance between
 * two points.
 */


float	calc_vertical_distance(t_cube *cube, float angl) // vertical intersection.
{
    t_vector_2d_f collition;
    t_vector_2d_f delta;
	float	y_step;
	int		pixel;

	ft_angle_normal(&angl);
	delta.x = TILE_SIZE;
	delta.y = TILE_SIZE * tan(angl);
	collition.x = floor(cube->p->pos.x / TILE_SIZE) * TILE_SIZE;
	pixel = calc_step(angl, &collition.x, &delta.x, 0);
	collition.y = cube->p->pos.y + (collition.x - cube->p->pos.x) * tan(angl);
	if ((unit_circle(angl, 'x') && delta.y < 0) || \
	(!unit_circle(angl, 'x') && delta.y > 0))
		delta.y *= -1;
	while (hit_wall_m(collition.x - pixel, collition.y))
	{
		collition.x += delta.x;
		collition.y += delta.y;
	}
	cube->r->ver.x = collition.x;
	cube->r->ver.y = collition.y;
    return (ft_check_distance(cube->p->pos, collition));
}

void	render_wall(t_cube *cube, t_image *img, int color, int index)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	perp_walldist;

	// Calcula a distância projetada na direção da câmera
	if (cube->r->side == 0)
		perp_walldist = (cube->r->side_dist.x - cube->r->delta_dist.x);
	else
		perp_walldist = (cube->r->side_dist.y - cube->r->delta_dist.y);
	//Calcula a altura da linha a ser desenhada na tela
	line_height = (int)(W_HEIGHT / perp_walldist);
	line_height *= 2;
	//calcula o pixel mais baixo e mais alto para preencher a faixa atual
	draw_start = -line_height / 2 + W_HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + W_HEIGHT / 2;
	if (draw_end >= W_HEIGHT)
		draw_end = W_HEIGHT - 1;
	if (cube->r->side == 1)
		color = RED / 2;
	draw_wall(index, draw_start, draw_end, img, color);
}

int ft_check_distance(t_vt_f p1, t_vector_2d_f p2)
{
    double dx;
    double dy;

    dx = (p2.x - p1.x);
    dy = (p2.y - p1.y);
    return sqrt(dx * dx + dy * dy);
}

int	calc_step(float angle, float *inter, float *step, int is_horizon)
{
	if (is_horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
    else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*step *= -1;
	}
    return (1);
}

int ft_looking_angle_up(float angle)
{
	ft_angle_normal(&angle);
	if (angle > 0 && angle < M_PI)
		return (1);
	if (angle > M_PI && angle < 2 * M_PI)
		return (2);
}

int ft_looking_angle_down(float angle)
{
	ft_angle_normal(&angle);
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
		return (1);
	else if (angle > 3 * M_PI / 2 && angle < M_PI)
		return (2);
}
int	unit_circle(float angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}

float	calc_hor_distance(t_cube *cube, float angl) // horizontal distance.
{
   t_vector_2d_f collition;
   t_vector_2d_f delta;
	int		pixel;

	delta.y = TILE_SIZE;
	ft_angle_normal(&angl);
	delta.x = TILE_SIZE / tan(angl);
	collition.y = floor(cube->p->pos.y / TILE_SIZE) * TILE_SIZE;
	pixel = calc_step(angl, &collition.y, &delta.y, 1);
	collition.x = cube->p->pos.x + (collition.y - cube->p->pos.y) / tan(angl);
	if ((unit_circle(angl, 'y') && delta.x > 0) || \
		(!unit_circle(angl, 'y') && delta.x < 0))
		delta.x *= -1;
	while (hit_wall_m(collition.x, collition.y - pixel))
	{
		collition.x += delta.x;
		collition.y += delta.y;
	}
	cube->r->hor.x = collition.x;
	cube->r->hor.y = collition.y;
    return (ft_check_distance(cube->p->pos, collition));
}

void	draw_wall_m(t_cube *cube, int ray, int t_pix, int b_pix)	// draw the wall
{

	while (t_pix < b_pix)
	{
		if (cube->r->hit)
		{
			if (cube->r->angle < M_PI && cube->r->angle > 0 )
				img_draw_pixel(&cube->img, ray, t_pix++, ORANGE);
			else
				img_draw_pixel(&cube->img, ray, t_pix++, BLACK / 2);
		}
		else
		{
			if (cube->r->angle > M_PI / 2 && cube->r->angle < 3 * M_PI / 2 )
				img_draw_pixel(&cube->img, ray, t_pix++, GREEN);
			else
				img_draw_pixel(&cube->img, ray, t_pix++, BLACK);
		}
	}
}

void ft_draw_wall(t_cube *cube, int ray)
{
    t_vector_2d_f intersection;
	t_vector_2d_f pixels;

	double wall_height;
	float angle;

	angle = cube->r->angle - cube->p->angle;
	ft_angle_normal(&angle);
	cube->r->dist *= cos(angle);
	wall_height = (TILE_SIZE / cube->r->dist) * ( (W_WIDTH / 2) / tan(FOV_RAD / 2));
	pixels.x = (W_HEIGHT / 2) + (wall_height / 2);
	pixels.y = (W_HEIGHT / 2) - (wall_height / 2);
	if (pixels.x > W_HEIGHT)
		pixels.x = W_HEIGHT;
	if (pixels.y < 0)
		pixels.y = 0;
	draw_wall_m(cube, ray, pixels.y, pixels.x);
}

void	draw_rays(t_cube *cube, t_image *img)
{
	t_vt_d	player;
	t_vt_d	ray_end;

	player.x = cube->p->pos.x / (TILE_SIZE / MAP_SCALE);
	player.y = cube->p->pos.y / (TILE_SIZE / MAP_SCALE);
	ray_end.x = cube->r->pos.x / (TILE_SIZE / MAP_SCALE);
	ray_end.y = cube->r->pos.y / (TILE_SIZE / MAP_SCALE);
	ft_bresenham(img, player, ray_end, WHITE);
}

void raycasting(t_cube *cube)
{
    t_vector_2d_f intersection;
    t_raycast *ray;
    int num_ray;

    ray = cube->r;
    ray->angle = cube->p->angle - 0.523599;
	ft_angle_normal((float *)&ray->angle);
    num_ray = -1;
    while (++num_ray < (W_WIDTH * 2) || ray->angle <= (cube->p->angle + 0.523599))
    {
		ft_angle_normal((float *)&ray->angle);
        ray->hit = 0;
        intersection.x = calc_hor_distance(cube, ray->angle);
        intersection.y = calc_vertical_distance(cube, ray->angle);
        if (intersection.y < intersection.x)
        {
            ray->dist = intersection.y;
			t_vt_d colide;
			colide.x = ray->ver.x / (TILE_SIZE / MAP_SCALE);
			colide.y = ray->ver.y / (TILE_SIZE / MAP_SCALE);
			t_vt_d pos;
			pos.x = cube->p->pos.x / (TILE_SIZE / MAP_SCALE);
			pos.y = cube->p->pos.y / (TILE_SIZE / MAP_SCALE);
			ft_bresenham(&cube->img, pos, colide, YELLOW);
        }
        else
        {
            ray->dist = intersection.x;
            ray->hit = 1;
						t_vt_d colide;
			colide.x = ray->hor.x / (TILE_SIZE / MAP_SCALE);
			colide.y = ray->hor.y / (TILE_SIZE / MAP_SCALE);
			t_vt_d pos;
			pos.x = cube->p->pos.x / (TILE_SIZE / MAP_SCALE);
			pos.y = cube->p->pos.y / (TILE_SIZE / MAP_SCALE);
			ft_bresenham(&cube->img, pos, colide, YELLOW);
        }
        ft_draw_wall(cube, num_ray);
        ray->angle += 0.0002757;
    }
}
