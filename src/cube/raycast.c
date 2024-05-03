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

int	hit_wall(double new_x, double new_y)
{
	t_vt_d	p;

	p.x = (int)(new_x) / TILE_SIZE;
	p.y = (int)(new_y) / TILE_SIZE;
	if (map()->map[p.y][p.x] == '1')
		return (1);
	return (0);
}

/**
 * calculate the distance between
 * two points.
 */
void	calc_delta_distance(t_cube *cube)
{
	if (cube->r->ray_dir.x == 0)
		cube->r->delta_dist.x = 1e30;
	else
		cube->r->delta_dist.x = fabs(1 / (cube->r->ray_dir.x));
	if (cube->r->ray_dir.y == 0)
		cube->r->delta_dist.y = 1e30;
	else
		cube->r->delta_dist.y = fabs(1 / (cube->r->ray_dir.y));
}

void	calc_side_distance(t_cube *cube)
{
	if (cube->r->ray_dir.x < 0)
		cube->r->side_dist.x = (cube->p->pos.x - cube->r->pos.x) * cube->r->delta_dist.x;
	else
		cube->r->side_dist.x = (cube->r->pos.x + 1.0 - cube->p->pos.x) * cube->r->delta_dist.x;
	if (cube->r->ray_dir.y < 0)
		cube->r->side_dist.y = (cube->p->pos.y - cube->r->pos.y) * cube->r->delta_dist.y;
	else
		cube->r->side_dist.y = (cube->r->pos.y + 1.0 - cube->p->pos.y) * cube->r->delta_dist.y;
}

void	calc_step(t_cube *cube)
{
	if (cube->r->ray_dir.x < 0)
		cube->r->step.x = -1;
	else
		cube->r->step.x = 1;
	if (cube->r->ray_dir.y < 0)
		cube->r->step.y = -1;
	else
		cube->r->step.y = 1;
}

void	dda_exc(t_cube *cube)
{
	cube->r->hit = hit_wall(cube->r->pos.x, cube->r->pos.y);
	while (cube->r->hit == 0)
	{
		if (cube->r->side_dist.x < cube->r->side_dist.y)
		{
			cube->r->side_dist.x += cube->r->delta_dist.x;
			cube->r->pos.x += cube->r->step.x;
			cube->r->side = 0;
		}
		else
		{
			cube->r->side_dist.y += cube->r->delta_dist.y;
			cube->r->pos.y += cube->r->step.y;
			cube->r->side = 1;
		}
		cube->r->hit = hit_wall(cube->r->pos.x, cube->r->pos.y);
	}
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

void	raycasting(t_cube *cube, t_image *img)
{
	int		index;
	double	camera_x;

	index = -1;
	while (++index < W_WIDTH)
	{
		// caucula a posicao e a direcao do raio
		camera_x = 2 * index / (double)W_WIDTH - 1; // cordenada x no espaco da camera
		cube->r->ray_dir.x = cube->p->dir.x + cube->p->plane.x * camera_x;
		cube->r->ray_dir.y = cube->p->dir.y + cube->p->plane.y * camera_x;

		cube->r->pos.x = (int)cube->p->pos.x;
		cube->r->pos.y = (int)cube->p->pos.y;
		calc_delta_distance(cube);
		calc_step(cube);
		calc_side_distance(cube);
		dda_exc(cube);
		t_vt_d	player;
        player.x = cube->p->pos.x / (TILE_SIZE / MAP_SCALE);
        player.y = cube->p->pos.y / (TILE_SIZE / MAP_SCALE);
        t_vt_d	ray_end;
        ray_end.x = cube->r->pos.x / (TILE_SIZE / MAP_SCALE);
        ray_end.y = cube->r->pos.y / (TILE_SIZE / MAP_SCALE);
		ft_bresenham(img, player, ray_end, WHITE);
		render_wall(cube, img, RED, index);
	}
}
