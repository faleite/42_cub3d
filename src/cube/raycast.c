/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:24:05 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/28 17:59:24 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_player_screen(t_data *data)
{
	t_vt_d	p;

	p.y = 0;
	while (p.y < TILE_SIZE / 2)
	{
		p.x = 0;
		while (p.x < TILE_SIZE / 2)
		{
			img_draw_pixel(&data->img, data->plyr->pos.x + p.x,\
							data->plyr->pos.y + p.y, RED);
			p.x++;
		}
		p.y++;
	}
}

void	draw_line_screen(int p_y, int p_x, t_image *img, double dir)
{
	t_line	line;

	line.x0 = p_x + TILE_SIZE / 4;
	line.y0 = p_y + TILE_SIZE / 4;
	line.x1 = p_x + cos(dir) * 200;
	line.y1 = p_y + sin(dir) * 200;
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

void	hit_wall(t_data *data, double new_x, double new_y)
{
	t_vt_d	p;

	p.x = floor(new_x / TILE_SIZE);
	p.y = floor(new_y / TILE_SIZE);
	p.x = floor(new_x);
	p.y = floor(new_y);
	if (map()->map[p.y][p.x] != '0')
	{
		printf("WALL\n");
		data->cast->flag = 1;
	}
}

void	raycasting(t_data *data, t_image *img)
{
	int		i;
	t_vt_f	ray_dir;
	t_vt_f	side_dist;
	t_vt_f	delta_dist;
	double	perp_walldist; //em que direção pisar na direção x ou y (+1 ou -1)
	t_vt_d	step;
	t_vt_d	pos;
	char	hit; // houve uma batida na parede?
	int		side; //uma parede NS ou EW foi atingida?
	int 	line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	// t_plyr	*ply;

	i = -1;

	// ply = data->plyr;
	while (++i < W_WIDTH)
	{
		// caucula a posicao e a direcao do raio
		data->plyr->camera_x = 2 * i / (double)W_WIDTH - 1; // cordenada x no espaco da camera
		ray_dir.x = data->plyr->dir.x + data->plyr->plane.x * data->plyr->camera_x;
		ray_dir.y = data->plyr->dir.y + data->plyr->plane.y * data->plyr->camera_x;
		pos.x = (int)data->plyr->pos.x;
		pos.y = (int)data->plyr->pos.y;
		if (ray_dir.x == 0)
			delta_dist.x = 1e30;
		else
			delta_dist.x = fabs(2 / ray_dir.x); // 1
		if (ray_dir.y == 0)
			delta_dist.y = 1e30;
		else
			delta_dist.y = fabs(2 / ray_dir.y); // 1
		hit = '0';
		//calcula passo e sideDist inicial
		if (ray_dir.x < 0)
		{
			step.x = -1;
			side_dist.x = (data->plyr->pos.x - pos.x) * delta_dist.x;
		}
		else
		{
			step.x = 1;
			side_dist.x = (pos.x + 1.0 - data->plyr->pos.x) * delta_dist.x;
		}
		if (ray_dir.y < 0)
		{
			step.y = -1;
			side_dist.y = (data->plyr->pos.y - pos.y) * delta_dist.y;
		}
		else
		{
			step.y = 1;
			side_dist.y = (pos.y + 1.0 - data->plyr->pos.y) * delta_dist.y;
		}
		// execucao do DDA
		while (hit == '0')
		{
		//salta para o próximo quadrado do posa, na direção x ou na direção y
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				pos.x += step.x;
				side = 0;
			}
			else
			{
				side_dist.y += delta_dist.y;
				pos.y += step.y;
				side = 1;
			}
			//Verifica se o raio atingiu uma parede
			if (map()->map[pos.x][pos.y] == '1')
				hit = '1';
		}
		//Calcula a distância projetada na direção da câmera
		if (side == 0)
			perp_walldist = (side_dist.x - delta_dist.x);
		else
			perp_walldist = (side_dist.y - delta_dist.y);
		//Calcula a altura da linha a ser desenhada na tela
		line_height = (int)(W_HEIGHT / perp_walldist);
		//calcula o pixel mais baixo e mais alto para preencher a faixa atual
		draw_start = -line_height / 2 + W_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + W_HEIGHT / 2;
		if (draw_end >= W_HEIGHT)
			draw_end = W_HEIGHT - 1;
		color = RED;
		if (side == 1)
			color = RED / 2;
		draw_wall(i, draw_start, draw_end, img, color);
	}
}
