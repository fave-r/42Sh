/*
** basic.c for basic in /home/alex-odet/work/42Sh/lib
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr  3 14:06:29 2014 alex-odet
** Last update Thu Apr  3 14:07:37 2014 alex-odet
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_putstr(char *str, int fd)
{
  return (write(fd, str, my_strlen(str)));
}
