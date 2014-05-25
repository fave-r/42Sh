/*
** check_next.c for 42sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 13 20:03:12 2014 romaric
** Last update Tue May 13 20:09:19 2014 romaric
*/

#include "my.h"

char	*my_strcpyfinal(char *dest, char *cmd)
{
  int	i;
  int	x;
  char	*tmp;

  x = 0;
  i = my_strlen_n(dest);
  tmp = xmalloc((my_strlen_n(dest) + my_strlen_n(cmd) + 2) * sizeof(char));
  while (x < (my_strlen_n(dest)))
    {
      tmp[x] = dest[x];
      x++;
    }
  x = 0;
  tmp[i] = '/';
  i++;
  while (cmd[x] != '\0')
    {
      tmp[i] = cmd[x];
      i++;
      x++;
    }
  tmp[i] = '\0';
  return (tmp);
}
