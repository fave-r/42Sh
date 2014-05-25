/*
** history.c for history in /home/lhomme_a/rendu/42Sh
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Apr 30 18:33:32 2014 lhomme
** Last update Sun May 25 14:48:11 2014 lhomme
*/

#include "my.h"

t_env	*my_history(t_env *history, char *str)
{
  int		fd;
  static int	line = 1;

  history = my_add_env(history, str);
  if (line == 1)
    fd = open(".history", O_WRONLY | O_CREAT | O_TRUNC, 0666);
  else
    fd = open(".history", O_WRONLY | O_APPEND, 0666);
  if (fd == -1)
    return (history);
  my_put_nbr(line, fd);
  write(fd, "\t", 1);
  write(fd, str, strlen(str));
  write(fd, "\n", 1);
  close(fd);
  line++;
  return (history);
}
