/*
** dup_fct.c for 42sh in /home/leo/rendu/42Sh/termcap
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Fri May 23 22:51:05 2014 bourrel
** Last update Fri May 23 22:51:20 2014 bourrel
*/

#include "my.h"

char    *my_dupstr(char *src, int len)
{
  char  *new;

  new = xmalloc(sizeof(char) * (len + 1));
  bzero(new, len);
  strcpy(new, src);
  return (new);
}

char    *dup_last_word(char *src)
{
  int   len;
  char  *new;

  if (src == NULL)
    return (NULL);
  len = strlen(src);
  while (len > 0 && src[len] != ' ')
    len--;
  if (src[len] == ' ')
    len++;
  new = strdup(src + len);
  return (new);
}
