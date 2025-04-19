/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:29:45 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/19 02:11:14 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, char *buf)
{
	t_list	*new;
	t_list	*last;

	if (!lst || !buf)
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->buf = buf;
	last = *lst;
	if (!last)
	{
		*lst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

void	ft_lstclear_append(t_list **lst, char *rest, t_list *new_node)
{
	t_list	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		free((*lst)->buf);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
	if (new_node->buf[0])
		*lst = new_node;
	else
	{
		free(rest);
		free(new_node);
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_save_line(t_list **lst)
{
	t_list	*last_node;
	t_list	*new_node;
	char	*rest;
	int	i;
	int	j;

	rest = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_list));
	if (!new_node || !rest)
		return ;
	last_node = ft_lstlast(*lst);
	i = 0;
	j = 0;
	while (last_node->buf[i] && last_node->buf[i] != '\n')
		i++;
	while (last_node->buf[i] && last_node->buf[++i])
		rest[j++] = last_node->buf[i];
	new_node->buf = rest;
	new_node->next = NULL; 
	ft_lstclear_append(lst, rest, new_node);
}

void	ft_populate_list(t_list **lst, int fd)
{
	int	num_read;
	char	*buf;

	while(ft_newline(lst))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		num_read = read(fd, buf, BUFFER_SIZE);
		if (num_read <= 0)
		{
			free(buf);
			return ;
		}
		buf[num_read] = '\0';
		ft_lstadd_back(lst, buf);
	}
}

int	ft_newline(t_list **lst)
{
	int	i;
	t_list	*current;

	current = *lst;
	while (current)
	{
		i = 0;
		while (current->buf[i])
		{
			if (current->buf[i] == '\n')
				return (0);
			i++;
		}
		current = current->next;
	}
	return (1);
}

char	*ft_one_line(t_list *lst)
{
	int	len;
	char	*line;

	if (!lst)
		return (NULL);
	len = ft_lstlen_newline(&lst);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_lstcpy(&lst, &line);
	return (line);
}

void	ft_lstcpy(t_list **lst, char **line)
{
	int	i;
	int	j;
	t_list	*current;

	if (!lst)
		return ;
	j = 0;
	current = *lst;
	while (current)
	{
		i = 0;
		while (current->buf[i])
		{
			if (current->buf[i] == '\n')
			{
				(*line)[j] = '\n';
				(*line)[++j] = '\0';
				return ;
			}
			(*line)[j++] = current->buf[i++];
		}
		current = current->next;
	}
	(*line)[j] = '\0';
}

int	ft_lstlen_newline(t_list **lst)
{
	int	i;
	int	len;
	t_list	*current;

	len = 0;
	current = *lst;
	while (current)
	{
		i = 0;
		while (current->buf[i])
		{
			if (current->buf[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		current = current->next;
	}
	return (len);
}
