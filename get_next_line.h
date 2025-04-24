/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:07:35 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/24 04:58:38 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*buffer;
	struct s_list	*next;
}	t_list;

t_list	*ft_get_fd(int fd, t_list **head);
void	ft_free_node(t_list **head, int fd);
int		ft_isnewline(char *buffer);
char	*ft_clean(char *buffer);
char	*ft_line(char *buffer);
char	*ft_strjoin_and_free(char *old, char *temp);
char	*get_next_line(int fd);
int		ft_initial_conditions(int fd, t_list **head, t_list **node);
void	ft_strcpycat(char **new, char *temp, char *old);

#endif
