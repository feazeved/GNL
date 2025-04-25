/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:41:58 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/25 13:41:05 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
		buffer[i++] = 0;
}

char	*ft_read_line(char buffer[OPEN_MAX][BUFFER_SIZE + 1], int fd)
{
	int		br;
	int		num_read;
	char	*line;

	br = 0;
	num_read = 1;
	line = NULL;
	while (!br)
	{
		if (!buffer[fd][0])
		{
			num_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (num_read == -1)
				return (free(line), NULL);
			if (num_read == 0)
				break ;
			buffer[fd][num_read] = '\0';
		}
		line = ft_str_join_and_free(line, buffer[fd]);
		if (!line)
			return (NULL);
		br = ft_clean_buffer(buffer[fd]);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;

	if (BUFFER_SIZE <= 0 || OPEN_MAX <= fd)
	{
		if (fd > 0 && OPEN_MAX > fd)
			ft_free(buffer[fd]);
		return (NULL);
	}
	line = ft_read_line(buffer, fd);
	if (!line)
		return (NULL);
	return (line);
}
