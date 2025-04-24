/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 21:22:37 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/24 05:51:51 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_isnewline(char *buffer)
{
	int	i;

	i = 0;
	if (buffer == NULL)
		return (0);
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

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

t_list	*ft_get_fd(int fd, t_list **head)
{
	t_list	*node;

	node = *head;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->buffer = NULL;
	node->next = *head;
	*head = node;
	return (node);
}

void	ft_free_node(t_list **head, int fd)
{
	t_list	*current;
	t_list	*previous;

	previous = NULL;
	current = *head;
	while (current)
	{
		if (current->fd == fd)
		{
			if (previous)
				previous->next = current->next;
			else
				*head = current->next;
			free(current->buffer);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}
