/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:43:01 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/27 03:51:54 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_read_line(char *buffer, int fd);
char	*get_next_line(int fd);
int		ft_strlen_line(char *str);
int		ft_clean_buffer(char *buffer);
char	*ft_str_join_and_free(char *old, char *buffer);

#endif
