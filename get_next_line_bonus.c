/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:41:58 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/30 23:40:54 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(char *buffer, int fd)
{
	int		br;
	int		num_read;
	char	*line;

	br = 0;
	num_read = 1;
	line = NULL;
	while (!br)
	{
		if (!buffer[0])
		{
			num_read = read(fd, buffer, BUFFER_SIZE);
			if (num_read == -1)
				return (free(line), NULL);
			if (num_read == 0)
				break ;
		}
		line = ft_str_join_and_free(line, buffer);
		if (!line)
			return (NULL);
		br = ft_clean_buffer(buffer);
	}
	return (line);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*ptr;
	size_t			bytes;

	bytes = nmemb * size;
	if (size && ((bytes / size) != nmemb))
		return (NULL);
	ptr = malloc(bytes);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < bytes)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer[fd])
			return (NULL);
	}
	line = ft_read_line(buffer[fd], fd);
	if (!line || !line[0])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
