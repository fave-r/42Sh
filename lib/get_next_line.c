/*
** get_next_line.c for corewar in /home/blackbird/work/Corewar/asm/Get_Next_Line
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon Mar 24 11:49:17 2014 romaric
** Last update Thu Apr 17 03:05:35 2014 
*/

#include "my.h"

char		*my_get_strdup(char *src)
{
  char		*dest;

  dest = xmalloc((my_strlen(src) + 2) * sizeof(char));
  if (dest == NULL)
    exit (EXIT_FAILURE);
  strcpy(dest, src);
  return (dest);
}

char		*get_next_line(const int fd)
{
  static char   buff[BUFF_SIZE];
  static int    i = 0;
  static int    a = 0;
  t_get	l;

  l.c = 0;
  l.s = xmalloc(1 * sizeof(char));
  if (i == a)
    {
      a = read(fd, buff, BUFF_SIZE);
      i = 0;
    }
  if (a <= 0)
    return (0);
  while (buff[i] != '\n')
    {
      if (buff[i] == '\0')
	return (l.s);
      if (buff[i] == '\t')
	{
	  l.s[l.c] = 0;
	  printf("OK\n");
	  return (my_auto_complete(l.s));
	}
      l.s = my_get_strdup(l.s);
      l.s[l.c] = buff[i];
      i++;
      l.c++;
    }
  i++;
  return (l.s);
}