/*
** xfunction.c for minishell in /home/blackbird/work/minishell/1
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Dec 18 14:03:00 2013 romaric
** Last update Sun May 11 14:54:19 2014 romaric
*/

#include "eval.h"

int	xopen(const char *pathname, int flags, mode_t mode)
{
  int	len;

  len = open(pathname, flags, mode);
  if (len == -1)
    fprintf(stderr, "open fail.\n");
  return (len);
}

ssize_t	xread(int fd, void *buf, size_t count)
{
  ssize_t	len;

  len = read(fd, buf, count);
  if (len == -1)
    {
      fprintf(stderr, "read fail.\n");
      exit(EXIT_FAILURE);
    }
  return (len);
}

void	*xmalloc(size_t n)
{
  void	*mal;

  mal = malloc(n);
  if (mal == NULL)
    {
      fprintf(stderr, "malloc fail.\n");
      exit(EXIT_FAILURE);
    }
  return (mal);
}
