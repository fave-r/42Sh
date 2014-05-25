/*
** delete_varenv.c for npi in /home/lhomme_a/rendu/42Sh
**
** Made by lhomme
** Login   <lhomme_a@epitech.net>
**
** Started on  Sat May 24 17:02:55 2014 lhomme
** Last update Sun May 25 21:27:57 2014 romaric
*/

#include "my.h"

char	*delete_varenv(char *str, char *var)
{
  char	*tmp;
  int	i;
  int	j;

  tmp = strdup(str);
  i = 0;
  j = 0;
  while (str[i] != var[j])
    i++;
  if (str[i])
    {
      tmp[i] = 0;
      while (str[i] && var[j])
	{
	  i++;
	  j++;
	}
    }
  free(str);
  return (tmp);
}
