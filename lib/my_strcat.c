/*
** my_strcat.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell1
**
** Made by lhomme
** Login   <lhomme_a@epitech.net>
**
** Started on  Mon Dec  9 11:54:04 2013 lhomme
** Last update Sun May 25 21:50:30 2014 romaric
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;
  char	*tmp;

  i = 0;
  j = 0;
  if (dest != NULL)
    tmp = xmalloc(sizeof(*tmp) * (strlen(dest) + strlen(src) + 1));
  else if (dest == NULL)
    return (src);
  else if (src == NULL)
    return (dest);
  while (dest[i] != 0)
    {
      tmp[i] = dest[i];
      i = i + 1;
    }
  while (src[j] != 0)
    {
      tmp[i] = src[j];
      j = j + 1;
      i = i + 1;
    }
    tmp[i] = 0;
  return (tmp);
}
