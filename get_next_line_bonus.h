/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:43:01 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/25 13:42:00 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char	*ft_read_line(char buffer[OPEN_MAX][BUFFER_SIZE + 1], int fd);
void	ft_free(char *buffer);
void	ft_initializer(char **line, int *br, int *num_read);
char	*get_next_line(int fd);
int		ft_strlen_line(char *str);
int		ft_clean_buffer(char *buffer);
char	*ft_str_join_and_free(char *old, char *buffer);

#endif
