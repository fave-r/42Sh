/*
** my_get_line.c for my_get_line in /home/odet/work/42Sh
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Fri May 23 09:58:43 2014 odet
** Last update Fri May 23 11:07:37 2014 odet
*/

#include "my.h"

char		*my_strdup_new(char *src)
{
  char		*dest;

  dest = calloc((my_strlen(src) + 2) * sizeof(char),
		(strlen(src) + 2 * sizeof(char)));
  if (dest == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}

char		*copy_char(char *old, char *new, int *i, int *j)
{
  if (old[*i] == '\0')
    {
      *i = 0;
      new[*j] = 0;
      bzero(old, BUFF_SIZE);
      return (new);
    }
  new = my_strdup_new(new);
  new[*j] = old[*i];
  *i += 1;
  *j += 1;
  return (new);
}

char		*my_get_next_line(const int fd)
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
      l.s = copy_char(buff, l.s, &i, &l.c);
      a = 0;
    }
  i++;
  unset_term();
  return (l.s);
}
