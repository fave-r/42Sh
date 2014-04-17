/*
** my_auto_complete.c for my_auto_complete in /home/odet_a/work/42Sh
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Thu Apr 17 02:37:57 2014 
** Last update Thu Apr 17 03:35:48 2014 
*/

#include "my.h"

char		*my_auto_complete(char *path)
{
  printf("path = %s\n", path);
  char		*new;
  glob_t	globbuf;
  int		x;

  if (path[0] != '\n')
    {
      new = strcat(path, "*");
      x = glob(new, GLOB_DOOFFS | GLOB_NOMATCH, NULL, &globbuf);
      printf("Path find = %s\n", globbuf.gl_pathv[0]);
      free(new);
      if (x == 0)
	return (globbuf.gl_pathv[0]);
      else
	return (path);
    }
  return (NULL);
}
