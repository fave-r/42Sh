/*
** char.c for 42sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri Apr 25 17:44:49 2014 romaric
** Last update Wed Apr 30 19:57:37 2014 romaric
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
