/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/08 22:32:00 by faaraujo         ###   ########.fr       */
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
# define MINIMAP_SCALE 15

/* elements */
# define F "F"
# define C "C"
# define NO "NO"
# define SO "SO"
# define WE "WE"
# define EA "EA"

/* keycode */
# define W 119
# define A 97
# define S 115
# define D 100
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
	// int		map_width;
}	t_parse;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}			t_data;

#endif /* TYPES_H */