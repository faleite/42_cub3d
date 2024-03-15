/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/15 21:05:29 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* BUFFER SIZE OF SCENE*/
# define BUFFER_CUB 1024

/* images */

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

/* includes */
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h> /**/
# include <string.h> /**/
# include <errno.h> /**/
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

typedef struct s_cub
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**scene;
	char	**rgb_c;
	char	**rgb_f;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		start_map;
	int		end_map;		
	int		x;
	int		y;
	int		size_x;
	int		size_y;
}	t_cub;

/* structs init */
t_cub	*cub(void);
// t_img	*img(void);
// t_field	*field(void);

/* tools */
void	err_case(char *msg);
void	free_arr(char **arr);
int		array_len(char **arr);


/* checks */
int		check_type(char *str);
int		check_scene(void);
int		map_location(void);
int		check_first_element(void);
int		iselement_wall(char *str);
int		iselement_cf(char *str);
int		white_space(char *str);
int		check_wall_texture(void);

/* data */
char	**get_scene(char *file);
int		count_line(char *file);
int		clean_nl(void);

/* debugs */
void	print_scene(char **file, int nl);

#endif /* CUB3D_H */