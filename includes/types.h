/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/11 15:09:39 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "cub3d.h"

/* BUFFER SIZE OF SCENE*/
# define BUFFER_CUB 1024

/* images */

/* window
 vm: W_W 1350 W_H 680
*/
# define W_WIDTH 1280
# define W_HEIGHT 750
# define MAP_SCALE 12.0
# define FOV 60
# define FOV_RAD 1.0472
# define FOV_HALF 30
# define RAY_VIEW 25
# define TILE_SIZE 64.0

/* elements */
# define F "F"
# define C "C"
# define NO "NO"
# define SO "SO"
# define WE "WE"
# define EA "EA"

/* Colors */
# define BLACK 1515552
# define GRAY 8421504
# define RED 16519760
# define WHITE 16777215
# define GREEN 2263842
# define PINK 16738740
# define YELLOW 15647028
# define WOOD 7166474
# define BROWN 3218945
# define ORANGE 16744448
# define SPACE 32
/* fields */
# define WALL '1'
# define FLOOR '0'

/* keycode */
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define UP 65362
# define DOWN 65364
# define LEFT 161
# define RIGHT 163
# define ESC 107
# define K_UP 162
# define K_DOWN 164
# define K_LEFT 161
# define K_RIGHT 163

/* Mouse buttons */
# define MOUSE_LEFT_BUTTON 1
# define MOUSE_RIGHT_BUTTON 3
# define MOUSE_THIRD_BUTTON 2
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5
# define MOUSE_SCROLL_LEFT 6
# define MOUSE_SCROLL_RIGHT 7

/**
 * Represents a 2D pixel position.
 *
 * @param x coordinate of the pixel.
 * @param y coordinate of the pixel.
 */
typedef struct s_vector_2int
{
	int	x;
	int	y;
}		t_vector_2int;

typedef struct s_wall
{
	double	bottom;
	double	top;
}			t_wall;

typedef struct s_vector_2d
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	double	angle;
}			t_vector_2d;

typedef struct s_vector_2dob
{
	double	x;
	double	y;
}			t_vector_2dob;

typedef struct s_vector_2d_f
{
	float	x;
	float	y;
}			t_vector_2d_f;

typedef struct s_parse
{
	char	**scene;
	char	**map;
	char	**rgb_c;
	char	**rgb_f;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	orientation;
	int		pos_x;
	int		pos_y;
	int		start_map;
	int		end_map;
	int		color_c;
	int		color_f;
	int		map_height;
	int		map_width;
}			t_parse;

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}			t_image;

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
}			t_line;

typedef struct s_bres
{
	int		dx;
	int		dy;
	int		xi;
	int		yi;
	int		x;
	int		y;
	int		d;
	int		cst1;
	int		cst2;
}			t_bres;

typedef struct s_map
{
	int				map_width;
	int				map_height;
	char			**map;
	double			orientation;
	t_vector_2int	ply_start;
}					t_map;

typedef struct s_plyer
{
	int				move;
	int				rotate;
	int				key_bool[200];
	int				prev_key_bool[200];
	float			angle;
	double			move_speed;
	double			rotation_speed;
	t_vector_2dob	pos;
}					t_plyer;

typedef struct s_ray
{
	double	angle;
	double	distance;
	int		hit_wall;
	t_line	position;
}			t_ray;

typedef struct s_raycast
{
	int				hit;
	double			dist;
	double			angle;
	t_vector_2int	step;
	t_vector_2int	pos;
	t_vector_2int	hor;
	t_vector_2int	ver;
}					t_raycast;

typedef struct s_texture
{
	t_image	img;
	int		width;
	int		height;
}			t_texture;

typedef struct s_cube
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;
	t_plyer		*p;
	t_raycast	*r;
	t_texture	tex_no;
	t_texture	tex_so;
	t_texture	tex_we;
	t_texture	tex_ea;
	int			flag_map;
}				t_cube;

#endif /* TYPES_H */