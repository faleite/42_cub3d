/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/17 20:47:35 by faaraujo         ###   ########.fr       */
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
# define MM_SCALE 12

/* elements */
# define F "F"
# define C "C"
# define NO "NO"
# define SO "SO"
# define WE "WE"
# define EA "EA"

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

/**
 * Represents a 2D pixel position.
 *
 * @param x coordinate of the pixel.
 * @param y coordinate of the pixel.
 */
typedef struct s_pix_pos
{
	int		x;
	int		y;
}			t_pix_pos;

typedef enum e_side
{
	HORIZONTAL = 1,
	VERTICAL
}				t_side;

typedef enum e_map
{
	FLOOR,
	WALL,
	N,
	S,
	W,
	E,
	SPACES,
}				t_map;

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

typedef struct s_plyr
{
	int			**map;
	int			move_speed;
	double		radius;
	double		rotation_angle;
	double		rotation_speed;
	t_pix_pos	pos;
}				t_plyr;

typedef struct s_raycast
{
	// char or int			**cub_map;
	t_plyr		player;
	t_pix_pos	wall_hit;
	t_pix_pos	step;
	t_pix_pos	intercept;
	t_pix_pos	next_touch;
	t_side		hit_side;
	double		distance;
	double		ray_angle;
}				t_raycast;

#endif /* TYPES_H */