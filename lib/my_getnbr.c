/*
** my_getnbr.c for my_getnbr in /home/lhomme_a/rendu/minishell2
**
** Made by lhomme
** Login   <lhomme_a@epitech.net>
**
** Started on  Thu Mar  6 22:11:23 2014 lhomme
** Last update Sun May 25 21:50:12 2014 romaric
*/

#include "my.h"

int		is_neg(char *str)
{
  int		i;
  int		counter;

  i = 0;
  counter = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
        counter++;
      i++;
    }
  if (counter % 2 != 0)
    return (1);
  else
    return (0);
}

int		is_num(char l)
{
  if (l >= '0' && l <= '9')
    return (1);
  else
    return (0);
}

int		my_getnbr(char *str)
{
  int		i;
  int		nbr;

  nbr = 0;
  i = 0;
  while (is_num(str[i]) == 0)
    i++;
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] - 48));
      i++;
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}
