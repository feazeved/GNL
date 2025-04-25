/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:02:04 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/25 12:09:27 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

void	ft_initializer(char **line, int *br, int *num_read);
char	*get_next_line(int fd);
int		ft_strlen_line(char *str);
int		ft_clean_buffer(char *buffer);
char	*ft_str_join_and_free(char *old, char *buffer);

#endif
