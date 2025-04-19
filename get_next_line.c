/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:21:00 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/19 02:50:30 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*line;
	static t_list	*new_list;

	if ((read(fd, &line, 0) < 0) || 0 > fd || BUFFER_SIZE <= 0)
		return (NULL);
	ft_populate_list(&new_list, fd);
	if (!new_list)
		return (NULL);
	line = ft_one_line(new_list);
	ft_save_line(&new_list);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	fd;
	int	lines;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	lines = atoi(argv[2]);
	while (get_next_line(fd))
	{
		printf("%s", get_next_line(fd));
		lines--;
	}
	close(fd);
	return (0);
}
