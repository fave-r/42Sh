/*
** char.c for 42sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri Apr 25 17:44:49 2014 romaric
** Last update Thu May  1 16:18:32 2014 romaric
*/

#include "eval.h"

int     my_strlen_n(char *str)
{
  int   x;

  x = 0;
  while (str[x] != '\0' && str[x] != '\n')
    x++;
  return (x);
}

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  dest[my_strlen_n(dest)] = '\0';
  i = 0;
  while (src[i] != '\0' && src[i] != '\n')
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}
