/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:00:08 by faaraujo          #+#    #+#             */
/*   Updated: 2023/08/25 22:00:36 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief A function that takes one line of the text stored on buffer.
 * @param fd A file descriptor that opens and reads the text.
 * @return The first or next line of the text stored on buffer.
 */
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = strjoin_line(line, buffer);
		if (clean_line(buffer) == 1)
			break ;
		if (read(fd, buffer, BUFFER_SIZE) < 0)
		{
			free (line);
			return (NULL);
		}
	}
	return (line);
}
