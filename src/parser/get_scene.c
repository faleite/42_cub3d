/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:24:35 by faaraujo          #+#    #+#             */
/*   Updated: 2024/04/05 20:55:40 by faaraujo         ###   ########.fr       */
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
	while (cub()->scene && cub()->scene[i])
	{
		len = ft_strlen(cub()->scene[i]) - 1;
		if (cub()->scene[i][len] == '\n')
			cub()->scene[i][len] = '\0';
		i++;
	}
	return (0);
}
/* Ainda nao usando */
int	get_map_dimension(void)
{
	int	y;
	int	len;

	y = cub()->start_map;
	while (cub()->scene[y] && y <= cub()->end_map)
	{
		len = ft_strlen(cub()->scene[y]);
		if (len > cub()->map_width)
			cub()->map_width = len;
		cub()->map_height++;
		y++;
	}
	return (0);
}
