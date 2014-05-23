/*
** get_next_line.c for 42sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 20 11:54:44 2014 romaric
** Last update Fri May 23 14:26:03 2014 romaric
*/

#include "my.h"

char		*my_strdup_new(char *src)
{
  char		*dest;

  dest = calloc((strlen(src) + 2) * sizeof(char),
		(strlen(src) + 2) * sizeof(char));
  if (dest == NULL)
      return (NULL);
  my_strcpy(dest, src);
  return (dest);
}

char		*get_next_line(const int fd)
{
  static char   buff[BUFF_SIZE];
  static int    i = 0;
  static int    a = 0;
  t_get		l;

  l.c = 0;
  l.s = calloc(1 * sizeof(char), 1 * sizeof(char));
  if (i == a)
    {
      a = read(fd, buff, BUFF_SIZE);
      i = 0;
    }
  if (a <= 0)
    return (NULL);
  while (buff[i] != '\n')
    {
      if (buff[i] == '\0')
	{
	  i = 0;
	  a = 0;
	  bzero(buff, BUFF_SIZE);
	  return (l.s);
	}
      l.s = my_strdup_new(l.s);
      l.s[l.c] = buff[i];
      i++;
      l.c++;
    }
  i++;
  return (l.s);
}
