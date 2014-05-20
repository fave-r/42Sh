/*
** my_strcat.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell1
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Mon Dec  9 11:54:04 2013 lhomme
** Last update Mon May 19 18:42:20 2014 bourrel
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
    tmp = malloc(sizeof(*tmp) * (strlen(dest) + strlen(src) + 1));
  else
    tmp = malloc(sizeof(*tmp) * (strlen(src) + 1));
  if (tmp == NULL)
    return (NULL);
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
