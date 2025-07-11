/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:14:22 by faaraujo          #+#    #+#             */
/*   Updated: 2024/05/06 19:54:15 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/* structs init */
t_parse	*parse(void);

/* parser */
int		validate_scene(int argc, char *arg);

/* tools */
void	err_case(char *msg);
void	free_arr(char **arr);
void	free_parse(void);
int		array_len(char **arr);

/* check elements */
char	**ft_rgbdup(char **src);
int		check_type(char *str);
int		check_first_element(void);
int		iselement_wall(char *str);
int		iselement_cf(char *str);
int		white_space(char *str);
int		check_wall_texture(void);
int		checking_duplicates(void);
int		path_exists(void);
int		clean_comma(void);
int		check_rgb(char *rgb);
int		check_rgb_number(char **rgb);

/* check map */
void	check_field(void);
int		map_location(void);
int		start_end_wall(void);
int		closed_by_walls(void);
int		closed_by_validfield(char **map);
int		is_player(char c);

/* data */
char	**get_scene(char *file);
char	**get_map(void);
void	get_player(void);
int		count_line(char *file);
int		clean_nl(void);

/* debugs */
void	print_scene(char **file, int nl);
void	print_map(char **file, int nl);
void	print_data(void);

#endif /* PARSER_H */