#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
  int fd;
  char  *buffer;
  struct s_list *next; 
} t_list;

t_list *ft_get_fd(int fd, t_list **head)
{
  t_list *node;

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

void ft_free_node(t_list **head, int fd)
{
  t_list *current;
  t_list *previous;

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

int ft_isnewline(char *buffer)
{
  int i;

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

char *ft_clean(char *buffer)
{
  char *clean_line;
  int i;
  int j;

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

char *ft_line(char *buffer)
{
  int i;
  int j;
  char *line;

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

char *ft_strjoin_and_free(char *old, const char *temp)
{
  int i;
  int j;
  char *new;

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
  i = -1;
  while (old[++i])
    new[i] = old[i];
  j = -1;
  while (temp[++j])
    new[i + j] = temp[j];
  new[i + j] = '\0';
  free(old);
  return (new);
}

char  *get_next_line(int fd)
{
  static t_list *head = NULL;
  t_list *node;
  char temp[BUFFER_SIZE + 1];
  int num_read;
  char *line;

  if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    return (NULL);
  node = ft_get_fd(fd, &head);
  if (!node)
    return (NULL);
  while (!ft_isnewline(node->buffer))
  {
    num_read = read(fd, temp, BUFFER_SIZE);
    if (num_read <= 0)
      break;
    temp[num_read] = '\0';
    node->buffer = ft_strjoin_and_free(node->buffer, temp);
    if (!node->buffer)
      return (NULL);
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
int main(int argc, char *argv[])
{
  int fd;
  int lines;
  int i = 0;

  lines = atoi(argv[2]);
  fd = open(argv[1], O_RDONLY);
  while (i++ != lines)
    printf("%s", get_next_line(fd));
  close(fd);
  return (0);
} */