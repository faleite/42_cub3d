/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/11 09:15:07 by marvin           ###   ########.fr       */
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
t_map			*map(void);

/* cube */
int				render_cub3d(t_cube *cube);
int				build_window(t_cube cube);
int				destroy_window(t_cube *cube);
int				destroy_image(t_cube *cube);

/* rendering */
void			img_draw_pixel(t_image *img, int x, int y, int color);
void			ft_bresenham(t_image *img, t_vt_d p1, t_vt_d p2, int color);
void			clear_img(t_image img);
void			render_wall(t_cube *cube, int ray);
unsigned int	wall_draw_pixel(t_texture texture, int x, int y);
int             texture_xpm_to_image(t_cube *cube);

/* mini map */
int				draw_ceil_floor(t_image *img);
int				render_minimap(t_cube *cube);
void			draw_player(t_cube *cube, float x, float y);
void			render_rays(t_cube *cube);

/* math */
float			ft_max(float a, float b);
float			ft_mod(float a);
void			ft_angle_normal(float *angle);

/* moves */
void			ft_player_movement(t_cube *cube);
int             ft_mouse_handlertrack(int x, int y, t_cube *param);

/* Raycast */
int				hit_wall(float x, float y);
double				ft_check_distance(t_vt_f p1, t_vector_2d_f p2);
int				ft_looking_angle_up(float angle);
int				ft_looking_angle_down(float angle);
int				unit_circle(float angle, char c);
float			calc_vertical_distance(t_cube *cube, float angl);
float			calc_hor_distance(t_cube *cube, float angl);
void			raycasting(t_cube *cube);

/* tools */
void			init_values(t_cube *cube);
void			free_data(t_cube *cube);
void			print_struct_map(void);

/* Draw */
void drawCircleWithCross(t_cube *cube);
void	draw_rays(t_image *img, t_vt_f p, t_vt_d r);

#endif /* CUB3D_H */