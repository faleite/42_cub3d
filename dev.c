/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:59:47 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/23 17:48:10 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* window
 vm: W_W 1350 W_H 680 
*/
#define W_WIDTH 1280
#define W_HEIGHT 750
#define M_SCALE 56

#include <stdio.h>
#include "../mlx_linux/mlx.h"
#include "../mlx_linux/mlx_int.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <math.h>

/* keycode */
#define K_W 119
#define K_A 97
#define K_S 115
#define K_D 100
#define UP 65362
#define DOWN 65364
#define LEFT 65361
#define RIGHT 65363
#define ESC 65307

typedef struct s_vt_d
{
	int		x;
	int		y;
}			t_vt_d;

typedef struct s_ply
{
	float		x; // player position
	float		y; // player position
	float		dx; // DeltaX
	float		dy; // DeltaY
	float		a; // angulo player
}			t_ply;

typedef struct s_cube
{
	int		map[12][12]; // map
	int		x; // unit in each cube 8x8
	int		y; // unit in each cube 8x8
	int		s; // length cube 64 unit
}			t_cube;

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_image;


typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;
}			t_data;

typedef struct s_line
{
	int		height;
	double	x0;
	double	y0;
	double	x1;
	double	y1;
	double	delta_x;
	double	delta_y;
	double	max;
}				t_line;

typedef struct s_ray
{
	int		r;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	rx;
	float	ry;
	float	ra;
	float	xo;
	float	yo;
}				t_ray;

void	line(float p_y, float p_x, t_image *img, int width, int color);

t_ply	*ply(void)
{
	static t_ply	p;

	return (&p);
}

t_cube	*cube(void)
{
	static t_cube	c;

	return (&c);
}

/**
 * * Sets the color of a single pixel on the frame at the specified 
 * position x and y. It directly modifies the frame's memory to change
 * the pixel color.
 *
 * @param img   The image to draw the pixel on.
 * @param x     The x-coordinate of the pixel.
 * @param y     The y-coordinate of the pixel.
 * @param color The color of the pixel.
 */
void	img_draw_pixel(t_image *img, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x <= W_WIDTH && y >= 0 && y <= W_HEIGHT)
	{
		pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

void	draw_rays3d(t_image *img)
{
	t_ray	r;
	float	a_tan;

	r.ra = ply()->a;
	r.r = -1;
	while (++r.r < 1)
	{
		// Check HOrizontal Lines
		r.dof = 0;
		a_tan = -1 / tan(r.ra);
		if (r.ra > M_PI)
		{
			r.ry = (((int)ply()->y >> 6) << 6) - 0.0001;
			r.rx = (ply()->y - r.ry) * a_tan + ply()->x;
			r.yo = -64;
			r.xo = -r.yo * a_tan;
		}
		if (r.ra < M_PI)
		{
			r.ry = (((int)ply()->y >> 6) << 6) + 64;
			r.rx = (ply()->y - r.ry) * a_tan + ply()->x;
			r.yo = 64;
			r.xo = -r.yo * a_tan;
		}
		if (r.ra == 0 || r.ra == M_PI) // looking straight left or right
		{
			r.rx = ply()->x;
			r.ry = ply()->y;
			r.dof = 8;
		}
		while (r.dof < 8)
		{
			r.mx = (int)(r.rx) >> 6;
			r.my = (int)(r.ry) >> 6;
			r.mp = r.my * cube()->x + r.mx;
			// hit wall
			if ((r.mx > 0 && r.my > 0) && (r.mx < cube()->x && r.my < cube()->y) && cube()->map[r.mx][r.my] == 1)
				r.dof = 8;
			else // next line
			{
				r.rx += r.xo;
				r.ry += r.yo;
				r.dof += 1;
			}
		}
		line(ply()->x, ply()->y, img, 1, 65280);
		line(r.rx, r.ry, img, 1, 65280);
	}
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_mod(float a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}

/*
	Brasenham's algorithme draws lines between two points
*/
void	brasenham(t_line line, t_image *img, int color)
{
	t_line	*tmp;

	tmp = &line;
	tmp->delta_x = (tmp->x1 - tmp->x0);
	tmp->delta_y = (tmp->y1 - tmp->y0);
	tmp->max = ft_max(ft_mod(tmp->delta_x), ft_mod(tmp->delta_y));
	tmp->delta_x /= tmp->max;
	tmp->delta_y /= tmp->max;
	while ((int)(tmp->x0 - tmp->x1) || (int)(tmp->y0 - tmp->y1))
	{
		img_draw_pixel(img, tmp->x0, tmp->y0, color);
		tmp->x0 += tmp->delta_x;
		tmp->y0 += tmp->delta_y;
	}
}

void	line(float p_y, float p_x, t_image *img, int width, int color)
{
	t_line		line;

	line.x0 = p_x * M_SCALE / 5;
	line.y0 = p_y * M_SCALE / 5;
	line.x1 = p_x + cos(ply()->a) * width;
	line.x1 *= M_SCALE / 5;
	line.y1 = p_y + sin(ply()->a) * width;
	line.y1 *= M_SCALE / 5;
	brasenham(line, img, color);
}

void	init_cube()
{
	int	x;
	int	y;
	int temp_map[12][12] =
	{
		{1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,1,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1},
	};

	cube()->x = 12;
	cube()->y = 12;
	cube()->s = 64;

	x = -1;
	while (++x < cube()->x)
	{
		y = -1;
		while (++y < cube()->y)
			cube()->map[x][y] = temp_map[x][y];
	}
}

void	draw_player(t_image *img, float x, float y, int color)
{
	t_vt_d p1;
	t_vt_d p2;

	p2.x = (x * M_SCALE + M_SCALE) / 5;
	p2.y = (y * M_SCALE + M_SCALE) / 5;
	p1.y = (y * M_SCALE) / 5;
	while (p1.y < p2.y)
	{
		p1.x = (x * M_SCALE) / 5;
		while (p1.x < p2.x)
		{
			img_draw_pixel(img, p1.x, p1.y, color);
			line(y + 0.5, x + 0.5, img, 3, 16519760);
			p1.x++;
		}
		p1.y++;
	}
}

void	draw_line(t_image *img, float x, float y, int color)
{
	t_vt_d p1;
	t_vt_d p2;

	p2.x =( x * M_SCALE + M_SCALE);
	p2.y = (y * M_SCALE + M_SCALE);
	p1.y = (y * M_SCALE);
	while (p1.y < p2.y)
	{
		p1.x = (x * M_SCALE);
		while (p1.x < p2.x)
		{
			img_draw_pixel(img, p1.x, p1.y, color);
			p1.x++;
		}
		p1.y++;
	}
}

void	draw_map2d(t_image *img)
{
	t_vt_d	p;

	p.y = 0;
	while (p.y < cube()->y)
	{
		p.x = 0;
		while (p.x < cube()->x)
		{
			if (cube()->map[p.y][p.x] == 1)
				draw_line(img, (float)p.x, (float)p.y, 1515552);
			else
				draw_line(img, (float)p.x, (float)p.y, 8421504);
			p.x++;
		}
		p.y++;
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
			img_draw_pixel(img, pos.x, pos.y, 4145023);
	}
	while (pos.y < W_HEIGHT)
	{
		pos.x = -1;
		while (++pos.x < W_WIDTH)
			img_draw_pixel(img, pos.x, pos.y, 4144959);
		++pos.y;
	}
	return (0);
}

int	destroy_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int	display(t_data *data)
{
	if (!data->mlx_ptr)
		return (1);
	draw_ceil_floor(&data->img);
	draw_map2d(&data->img);
	draw_player(&data->img, ply()->x, ply()->y, 16519760);
	draw_rays3d(&data->img);

	/* After render this function put image to window */
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
							data->img.mlx_img, 0, 0);
	return (0);
}

void	keyboard(int keycode, t_data *data)
{
	// if (field()->moves == 0)
	// 	field()->moves = 1;
	// display();
	if (keycode == ESC)
		destroy_window(data);
	else if (keycode == K_W || keycode == UP)
	{
		// ply()->y -= 1;
		ply()->x += ply()->dx;
		ply()->y += ply()->dy;
	}
	else if (keycode == K_S || keycode == DOWN)
	{
		// ply()->y += 1;
		ply()->x -= ply()->dx;
		ply()->y -= ply()->dy;
	}
	else if (keycode == K_D || keycode == RIGHT)
	{
		// ply()->x += 1;
		ply()->a += 0.1;
		if (ply()->a > 2 * M_PI)
			ply()->a -= 2 * M_PI;
		ply()->dx = cos(ply()->a) * 0.5;
		ply()->dy = sin(ply()->a) * 0.5;
	}
	else if (keycode == K_A || keycode == LEFT)
	{
		// ply()->x -= 1;
		ply()->a -= 0.1;
		if (ply()->a < 0)
			ply()->a += 2 * M_PI;
		ply()->dx = cos(ply()->a) * 0.5;
		ply()->dy = sin(ply()->a) * 0.5;
	}
}

int	init(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	init_cube();
	ply()->x = 5;
	ply()->y = 5;
	// ply()->orientation = 'N';
	ply()->dx = cos(ply()->a) * 0.5;
	ply()->dy = sin(ply()->a) * 0.5;
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, W_WIDTH, W_HEIGHT, "3DSage");
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (1);
	}
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, W_WIDTH, W_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, \
					&data.img.line_len, &data.img.endian);
	mlx_loop_hook(data.mlx_ptr, &display, &data);
	mlx_hook(data.win_ptr, 2, 1L, (void *)keyboard, &data);
	mlx_hook(data.win_ptr, 17, 0L, (void *)destroy_window, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	init();
	return (0);
}
