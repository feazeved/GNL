/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 19:20:46 by feazeved          #+#    #+#             */
/*   Updated: 2025/04/19 02:09:47 by feazeved         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct	s_list
{
	char		*buf;
	struct s_list	*next;
}			t_list;

int	ft_lstlen_newline(t_list **lst);
void	ft_lstcpy(t_list **lst, char **line);
char	*ft_one_line(t_list *list);
int	ft_newline(t_list **list);
void	ft_populate_list(t_list **list, int fd);
void	ft_lstadd_back(t_list **lst, char *buf);
void	ft_lstclear_append(t_list **lst, char *rest, t_list *new_node);
t_list	*ft_lstlast(t_list *lst);
void	ft_save_line(t_list **lst);

#endif
