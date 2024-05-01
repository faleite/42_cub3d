/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/01 20:29:34 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* includes */
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> /* open */
# include <string.h>
# include <errno.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

/* CUB3D */
# include "types.h"
# include "parser.h"

/* struct */
t_map	*map(void);

/* cube */
int		render_cub3d(t_data *data);
int		build_window(t_data data);
int		destroy_window(t_data *data);
double	player_direction(void);

/* rendering */
void	img_draw_pixel(t_image *img, int x, int y, int color);
void	clear_img(t_image img);
void	brasenham(t_line line, t_image *img, int color);
void	draw_line(float p_y, float p_x, t_image *img, double dir);
void	draw_circle(t_vt_d center, int color, int radius, t_image *img);

/* mini map */
int		draw_ceil_floor(t_image *img);
// int		render_minimap(t_data *data, t_image *img);
int		render_minimap(t_image *img);
int		render_player(t_data *data);
void  print_player_m(t_data *data, t_image *img);
// void	init_player(void);

/* math */
float	ft_max(float a, float b);
float	ft_mod(float a);

/* screen */
void	draw_player_screen(t_image *img, int x, int y);
// void	draw_line_screen(int p_y, int p_x, t_image *img, double dir);

/* moves */
void	move_up(t_data *data, int move);
void	move_right(t_data *data, int move);
void	move_rotate(t_data *data, int rotate);

/* Raycast */
int		hit_wall(double new_x, double new_y);
void	raycasting(t_data *data, t_image *img);
// Study
void	print_grid(t_image *img);
void	set_grid_cell(t_image *img, int x, int y);
void	print_player(t_data *data, t_image *img);
void	ft_bresenham(t_image *img, t_vt_d p1, t_vt_d p2, int color);
void	print_ray(t_data *data, t_image *img);

/* tools */
void	init_values(t_data *data);
void	free_data(t_data *data);

/* debugs */
void	print_struct_map(void);

#endif /* CUB3D_H */