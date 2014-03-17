/*
** get_char.c for get_char in /home/blackbird/work
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri Mar 14 14:30:48 2014 romaric
** Last update Mon Mar 17 10:31:56 2014 alex-odet
*/

#include "struct.h"

char    get_char(int fd)
{
  static char	buff[BUFF_SIZE];
  static int i;
  static int s;
  char  c;

  i = 0;
  s = 0;
  if (i == s)
    {
      s = read(fd, buff, BUFF_SIZE);
      i = 0;
    }
  if (s <= 0)
    return (-1);
  c = buff[i];
  i = i + 1;
  return (c);
}
