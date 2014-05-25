/*
** my_get_line.c for my_get_line in /home/odet/work/42Sh
**
** Made by odet
** Login   <odet@epitech.net>
**
** Started on  Fri May 23 09:58:43 2014 odet
** Last update Sun May 25 06:56:02 2014 romaric
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

char		*copy_char(char *old, int *i, t_get *ptr, int *a)
{
  if (old[*i] == '\0')
    {
      *a = 0;
      ptr->s[ptr->c] = 0;
      bzero(old, BUFF_SIZE);
      return (ptr->s);
    }
  ptr->s = my_strdup_new(ptr->s);
  ptr->s[ptr->c] = old[*i];
  *i += 1;
  ptr->c += 1;
  return (ptr->s);
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
    l.s = copy_char(buff, &i, &l, &a);
  i++;
  return (l.s);
}
