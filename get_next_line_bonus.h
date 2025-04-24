/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:07:35 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/24 03:16:27 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char    *ft_strjoin_and_free(char *old, char *buffer);
int ft_strlen(char *str);
int ft_newline(char *buffer);
char    *ft_read_until_line(char *str, int fd);
char    *ft_get_line(char *str);
char    *ft_clean_line(char *str);
char    *get_next_line(int fd);

#endif
