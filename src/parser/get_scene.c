/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:24:35 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/18 15:01:54 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**get_scene(char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**scene;

	scene = malloc(sizeof(char *) * (count_line(file) + 1));
	if (!scene)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_case("File Descriptor (File not exist) `20'\n");
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		scene[i] = line;
		if (!line)
			break ;
		i++;
	}
	close(fd);
	return (scene);
}

int	count_line(char *file)
{
	int		line_count;
	int		read_file;
	int		fd;
	int		i;
	char	buffer[BUFFER_CUB];

	line_count = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_case("File Descriptor (File not exist) `21'\n");
	read_file = read(fd, buffer, BUFFER_CUB);
	while (read_file > 0)
	{
		i = 0;
		while (i < read_file)
		{
			if (buffer[i++] == '\n')
				line_count++;
		}
		read_file = read(fd, buffer, BUFFER_CUB);
		if (read_file < 0)
			err_case("Not read (Empty file) `22'\n");
	}
	close(fd);
	return (line_count);
}

int	clean_nl(void)
{
	int	i;
	int	len;

	i = 0;
	while (parse()->scene && parse()->scene[i])
	{
		len = ft_strlen(parse()->scene[i]) - 1;
		if (parse()->scene[i][len] == '\n')
			parse()->scene[i][len] = '\0';
		i++;
	}
	return (0);
}

char	**get_map(void)
{
	int		i;
	int		j;
	int		len;
	char	**map;

	i = parse()->start_map - 1;
	j = 0;
	len = parse()->map_height + 1;
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	while (++i <= parse()->end_map)
		map[j++] = parse()->scene[i];
	map[j] = NULL;
	return (map);
}

void	get_player(void)
{
	int	x;
	int	y;

	x = -1;
	while (parse()->map[++x])
	{
		y = -1;
		while (parse()->map[x][++y])
		{
			if (is_player(parse()->map[x][y]))
			{
				parse()->orientation = parse()->map[x][y];
				parse()->pos_x = x;
				parse()->pos_y = y;
			}
		}
	}
}

/* Ainda nao usando */
// int	get_map_dimension(void)
// {
// 	int	y;
// 	int	len;

// 	y = parse()->start_map;
// 	while (parse()->scene[y] && y <= parse()->end_map)
// 	{
// 		len = ft_strlen(parse()->scene[y]);
// 		if (len > parse()->map_width)
// 			parse()->map_width = len;
// 		parse()->map_height++;
// 		y++;
// 	}
// 	return (0);
// }
