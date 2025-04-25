/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:49:32 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/25 13:36:58 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int	ft_clean_buffer(char *buffer)
{
	int	br;
	int	i;
	int	j;

	i = 0;
	j = 0;
	br = 0;
	while (buffer[i])
	{
		if (br == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			br = 1;
		buffer[i++] = '\0';
	}
	while (j < i)
		buffer[j++] = '\0';
	return (br);
}

char	*ft_str_join_and_free(char *old, char *buffer)
{
	char	*new;
	int		i;
	int		j;

	new = malloc((ft_strlen_line(old) + ft_strlen_line(buffer) + 1));
	if (!new)
		return (free(old), NULL);
	i = 0;
	while (old && old[i])
	{
		new[i] = old[i];
		i++;
	}
	j = 0;
	while (buffer && buffer[j])
	{
		new[i++] = buffer[j];
		if (buffer[j] == '\n')
			break ;
		j++;
	}
	new[i] = '\0';
	return (free(old), new);
}
