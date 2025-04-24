/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:06:49 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/24 04:06:57 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_and_free(char *old, char *buffer)
{
	int		i;
	int		j;
	char	*new;

	if (!old)
	{
		old = malloc(1);
		if (!old)
			return (NULL);
		old[0] = '\0';
	}
	new = malloc(sizeof(*new) * (ft_strlen(old) + ft_strlen(buffer) + 1));
	if (!new)
		return (free(old), NULL);
	i = -1;
	while (old[++i])
		new[i] = old[i];
	j = -1;
	while (buffer[++j])
		new[i + j] = buffer[j];
	new[i + j] = '\0';
	return (free(old), new);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_newline(char	*buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_read_until_line(char *str, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		num_read;

	while (!ft_newline(str))
	{
		num_read = read(fd, buffer, BUFFER_SIZE);
		if (num_read <= 0)
		{
			if (num_read == 0 && str && *str)
				return (str);
			free(str);
			return (NULL);
		}
		buffer[num_read] = '\0';
		str = ft_strjoin_and_free(str, buffer);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	if (!str || !*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = malloc(sizeof(*line) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_clean_line(char	*str)
{
	int		j;
	int		i;
	char	*clean_line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	i++;
	clean_line = malloc(sizeof(*clean_line) * (ft_strlen(str + i) + 1));
	if (!clean_line)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		clean_line[j++] = str[i++];
	clean_line[j] = '\0';
	return (free(str), clean_line);
}

char	*get_next_line(int fd)
{
	static	char	*str[1024];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (fd >= 0 && fd < 1024 && str[fd])
		{
			free(str[fd]);
			return (NULL);
		}
	}
	str[fd] = ft_read_until_line(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	if (!line)
	{
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = ft_clean_line(str[fd]);
	return (line);
}

#include <unistd.h>
#include <errno.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int	fd;
	int	lines;
	int	i = 0;
	char	*retorno;
//	long	open_max = sysconf(_SC_OPEN_MAX);

//	printf("OPEN_MAX = %ld\n", open_max);

	(void)argc;
	lines = atoi(argv[2]);
	fd = open(argv[1], O_RDONLY);
	while (i++ < lines)
	{
		retorno = get_next_line(fd);
		if (!retorno)
			break;
		printf("%s", retorno);
		free(retorno);
	}
/*	while (1)
	{
		retorno = get_next_line(fd);
		if (!retorno)
			break;
		free(retorno);
	}*/
	close(fd);
	return (0);
}
