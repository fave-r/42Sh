/*
** istty.c for istty in /home/odet/work/42Sh
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Fri May 23 10:07:30 2014 odet
** Last update Fri May 23 21:42:07 2014 bourrel
*/

#include "my.h"

char	*my_istty(const int fd, t_env_var env)
{
  char	*tmp;

  tmp = NULL;
  if (isatty(0))
    tmp = get_next_line_icanon(0, env);
  else
    {
      tmp = my_get_next_line(fd);
      unset_term();
    }
  return (tmp);
}
