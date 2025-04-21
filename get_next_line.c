/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:06:49 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/21 21:55:16 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean(char *buffer)
{
	char	*clean_line;
	int		i;
	int		j;

	j = 0;
	while (buffer[j] != '\n' && buffer[j])
		j++;
	if (!buffer[j])
		return (free(buffer), NULL);
	j++;
	i = 0;
	while (buffer[j + i])
		i++;
	clean_line = malloc(sizeof(char) * (i + 1));
	if (!clean_line)
		return (free(buffer), NULL);
	i = 0;
	while (buffer[j])
		clean_line[i++] = buffer[j++];
	clean_line[i] = '\0';
	free(buffer);
	return (clean_line);
}

char	*ft_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*ft_strjoin_and_free(char *old, const char *temp)
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
	i = 0;
	while (old[i])
		i++;
	j = 0;
	while (temp[j])
		j++;
	new = malloc(sizeof(char) * (i + j + 1));
	if (!new)
		return (free(old), NULL);
	ft_strcpycat(&new, old, temp);
	return (free(old), new);
}

void	ft_strcpycat(char **new, char *temp, char *old)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (old[i])
	{
		(*new)[i] = old[i];
		i++;
	}
	while (temp[j])
	{
		(*new)[i + j] = temp[j];
		j++;
	}
}

int	ft_initial_conditions(int fd, t_list **head, t_list **node)
{
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	*node = ft_get_fd(fd, &head);
	if (!node)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static t_list	*head = NULL;
	t_list			*node;
	char			temp[BUFFER_SIZE + 1];
	int				num_read;
	char			*line;

	if (!ft_initial_conditions(fd, &head, &node))
		return (NULL);
	while (!ft_isnewline(node->buffer))
	{
		num_read = read(fd, temp, BUFFER_SIZE);
		if (num_read <= 0)
			break ;
		temp[num_read] = '\0';
		node->buffer = ft_strjoin_and_free(node->buffer, temp);
		if (!node->buffer)
			return (ft_free_node(&head, fd), NULL);
	}
	if (!node->buffer || node->buffer[0] == '\0')
		return (ft_free_node(&head, fd), NULL);
	line = ft_line(node->buffer);
	node->buffer = ft_clean(node->buffer);
	if (!node->buffer)
		ft_free_node(&head, fd);
	return (line);
}
/*
#include <stdio.h> 
int main(int argc, char *argv[])
{
	int	fd;
	int	lines;
	int	i = 0;
	char	*retorno;

	lines = atoi(argv[2]);
	fd = open(argv[1], O_RDONLY);
	while (i++ != lines)
	{
		retorno = get_next_line(fd);
		printf("%s", retorno);
		free(retorno);
	}
	close(fd);
	return (0);
}*/
