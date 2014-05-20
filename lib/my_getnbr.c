/*
** my_getnbr.c for getnbr in /home/brahic_a/rendu/fdf
** 
** Made by brahic
** Login   <brahic_a@epitech.net>
** 
** Started on  Wed Dec  4 09:27:15 2013 brahic
** Last update Thu May 15 16:28:41 2014 bourrel
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	nb;
  int	i;

  nb = 0;
  i = 1;
  while (str[0] && str[0] >= '0' && str[0] <= '9')
    {
      nb = (str[0] - 48) + (nb * i );
      i = 10;
      str++;
    }
  return (nb);
}
