/*
** my_strchr.c for 42sh in /home/blackbird/work/42Sh/bonus
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 27 13:33:32 2014 romaric
** Last update Tue May 27 13:34:40 2014 romaric
*/

#include "my.h"

int	my_strchr(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == c)
        return (i);
      i++;
    }
  return (-1);
}
