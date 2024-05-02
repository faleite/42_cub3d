/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/02 20:27:21 by faaraujo         ###   ########.fr       */
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
# define W_WIDTH  1280
# define W_HEIGHT 750
# define SIZE 64
# define MAP_SCALE 40
# define FOV 60
# define FOV_HALF 30
# define RAY_VIEW 25
# define TILE_SIZE 40 // 32 // 64

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
# define LEFT 65361
# define RIGHT 65363
# define ESC 65307

# define MOUSE_LEFT_BUTTON	1
# define MOUSE_RIGHT_BUTTON	3
# define MOUSE_THIRD_BUTTON	2
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define MOUSE_SCROLL_LEFT	6
# define MOUSE_SCROLL_RIGHT	7

/**
 * Represents a 2D pixel position.
 *
 * @param x coordinate of the pixel.
 * @param y coordinate of the pixel.
 */
typedef struct s_vt_d
{
	int		x;
	int		y;
}			t_vt_d;

typedef struct s_vt_f
{
	double		x;
	double		y;
}			t_vt_f;

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
}	t_parse;

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		mouse_button;
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
}				t_line;

typedef struct s_map
{
	char	**map;
	t_vt_d	ply_start;
	int		map_height;
	int		map_width;
}			t_map;

typedef struct s_plyr
{
	int			horizontal; // 0
	int			vertical; // 0
	double		angle_s;

	double		move_speed; // 3 
	double		rotation_speed; // move_sp * (PI / 180)
	double		angle; // 90
	t_vt_f		pos; // //posição inicial xey
	t_vt_f		dir; // //vetor de direção inicial
	t_vt_f		plane; // //a versão 2d raycaster do plano da câmera
	double		camera_x;

	t_vt_d		player_map;

	int			move;
}				t_plyr;

typedef struct s_raycast
{
	int			ww_half; // W_W / 2
	int			flag; // 0
	double		dist; // 0
	double		angle; // 3 * PI / 2
}				t_raycast;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img;
	t_plyr		*plyr;
	t_raycast	*cast;
}			t_data;

#endif /* TYPES_H */