/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 21:32:29 by faaraujo          #+#    #+#             */
/*   Updated: 2023/08/25 21:54:21 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/**
 * @brief Computes the length of the string s excluding the terminating null
 * byte ('\0'), and including line break byte ('\n').
 * @param s Pointer of string.
 * @return Returns the number of bytes in the string pointed to by s.
*/
size_t	gnl_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	if (s[len] == '\n')
		return (len + 1);
	return (len);
}

/**
 * @brief The similar 'strjoin': Allocates (with malloc(3)) and returns
 * a new string with only one line which is the result of the concatenation
 * of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
*/
char	*strjoin_line(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	s3 = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + gnl_strlen(s2) + 1));
	if (!(s3))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		s3[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	s3[j] = '\0';
	free(s1);
	return (s3);
}

/**
 * @brief A function that takes text from buffer, and delete the first line
 * this text.
 * @param buffer The stored text'
 * @return The text without the first line.
 */
size_t	clean_line(char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	j = 0;
	result = 0;
	while (buffer[i])
	{
		if (result)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			result = 1;
		buffer[i] = 0;
		i++;
	}
	return (result);
}
