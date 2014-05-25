/*
** basic.c for basic in /home/alex-odet/work/42Sh/lib
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Thu Apr  3 14:06:29 2014 alex-odet
** Last update Sun May 25 21:02:37 2014 romaric
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putchar(char c, int fd)
{
  write(fd, &c, 1);
}

int	my_putstr(char *str, int fd)
{
  return (write(fd, str, my_strlen(str)));
}

void	my_put_nbr(int nb, int fd)
{
  int	neg;

  neg = 0;
  if (nb < 0)
    {
      my_putchar('-', fd);
      if (nb == -2147483648)
        {
          neg = 1;
          nb++;
        }
      nb = nb * -1;
    }
  if (nb >= 10)
    my_put_nbr(nb / 10, fd);
  if (neg == 1)
    {
      neg = 0;
      my_putchar(nb % 10 + '1', fd);
    }
  else
    my_putchar(nb % 10 + '0', fd);
}
