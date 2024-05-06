/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/06 17:22:21 by faaraujo         ###   ########.fr       */
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
int		render_cub3d(t_cube *cube);
int		build_window(t_cube cube);
int		destroy_window(t_cube *cube);
double	player_direction(void);

/* rendering */
void	img_draw_pixel(t_image *img, int x, int y, int color);
void	clear_img(t_image img);
void	brasenham(t_line line, t_image *img, int color);
void	draw_line(float p_y, float p_x, t_image *img, double dir);
void	draw_circle(t_vt_d center, int color, int radius, t_image *img);

/* mini map */
int		draw_ceil_floor(t_image *img);
int		render_minimap(t_cube *cube);
void	draw_player(t_cube *cube, float x, float y);

/* math */
float	ft_max(float a, float b);
float	ft_mod(float a);

/* screen */

/* moves */
void	ft_angle_normal(float *angle);
void	ft_player_movement(t_cube *cube);
void	ft_angle_normal(float *angle);

/* Raycast */
int		hit_wall_m(float new_x, float new_y);
void	raycasting(t_cube *cube);
void	render_rays(t_cube *cube);

// Study
void	ft_bresenham(t_image *img, t_vt_d p1, t_vt_d p2, int color);

/* tools */
void	init_values(t_cube *cube);
void	free_data(t_cube *cube);

/* debugs */
void	print_struct_map(void);

#endif /* CUB3D_H */