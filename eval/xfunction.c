/*
** xfunction.c for minishell in /home/blackbird/work/minishell/1
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Dec 18 14:03:00 2013 romaric
** Last update Sun Dec 29 15:44:04 2013 romaric
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "minishell.h"

int	xopen(const char *pathname, int flags)
{
  int	len;

  len = open(pathname, flags);
  if (len == -1)
    {
      my_putstr("open fail.\n", 2);
      exit(EXIT_FAILURE);
    }
  return (len);
}

ssize_t	xread(int fd, void *buf, size_t count)
{
  ssize_t	len;

  len = read(fd, buf, count);
  if (len == -1)
    {
      my_putstr("read fail.\n", 2);
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
      free(mal);
      my_putstr("malloc fail.\n", 2);
      return (NULL);
    }
  return (mal);
}
