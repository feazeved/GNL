/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 04:01:40 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/25 11:37:22 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			br;
	int			num_read;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ft_initializer(&line, &br, &num_read);
	while (!br)
	{
		if (!buffer[0])
		{
			num_read = read(fd, buffer, BUFFER_SIZE);
			if (num_read == -1)
				return (free(line), NULL);
			if (num_read == 0)
				break ;
			buffer[num_read] = '\0';
		}
		line = ft_str_join_and_free(line, buffer);
		if (!line)
			return (NULL);
		br = ft_clean_buffer(buffer);
	}
	return (line);
}
/*
int	main(void)
{
	int	fd;
	char	*line;

	fd = open("get_next_line.c", O_RDONLY);
	if (fd == -1)
	{
		printf("error\n");
		return (1);
	}
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}*/
