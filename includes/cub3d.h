/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/03/12 22:12:04 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* BUFFER SIZE OF SCENE*/
# define BUFFER_CUB 1024

/* images */

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
void	free_map(char **map);

/* checks */
int		check_type(char *str);
int		count_line(char *file);

/* data */
char	**get_scene(char *file);

/* debugs */
void	print_scene(char **file);

#endif /* CUB3D_H */