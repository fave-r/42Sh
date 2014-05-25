/*
** xfunction.c for minishell in /home/blackbird/work/minishell/1
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Dec 18 14:03:00 2013 romaric
** Last update Sun May 25 20:08:09 2014 lhomme
*/

#include "my.h"

int	xopen(const char *pathname, int flags, mode_t mode)
{
  int	len;

  len = open(pathname, flags, mode);
  if (len == -1)
    fprintf(stderr, "Error: %s: no such file or directory\n", pathname);
  return (len);
}

ssize_t	xread(int fd, void *buf, size_t count)
{
  ssize_t	len;

  len = read(fd, buf, count);
  if (len == -1)
    fprintf(stderr, "read failed.\n");
  return (len);
}
