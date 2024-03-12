/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:50:32 by faaraujo          #+#    #+#             */
/*   Updated: 2023/08/25 21:55:17 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h> /* for function read() */
# include <fcntl.h> /* for function open() */
# include <stdio.h> /* for standard input/output */
# include <stdlib.h> /* for funtions malloc() and free() */
# include <string.h> /* for functions about string manipulation */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9999
# endif /* BUFFER_SIZE */

/**
 * @brief A function that takes one line of the text stored on buffer.
 * @param fd A file descriptor that opens and reads the text.
 * @return The first or next line of the text stored on buffer.
 */
char	*get_next_line(int fd);

/**
 * @brief The similar 'strjoin': Allocates (with malloc(3)) and returns
 * a new string with only one line which is the result of the concatenation
 * of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
*/
char	*strjoin_line(char *s1, char *s2);

/**
 * @brief A function that takes text from buffer, and delete the first line
 * this text.
 * @param buffer The stored text'
 * @return The text without the first line.
 */
size_t	clean_line(char *buffer);

/**
 * @brief Computes the length of the string s excluding the terminating null
 * byte ('\0'), and including line break byte ('\n').
 * @param s Pointer of string.
 * @return Returns the number of bytes in the string pointed to by s.
*/
size_t	gnl_strlen(char *s);

#endif /* GET_NEXT_LINE_H */
