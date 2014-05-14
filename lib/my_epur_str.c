/*
** my_epur_str.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Mon Feb 10 17:00:57 2014 lhomme
** Last update Wed May 14 17:38:47 2014 
*/

#include "my.h"

char	*my_epur_str(char *str)
{
  int           i;
  int           j;

  i = 0;
  j = 0;
  if (str[0] == 0)
    return (0);
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  str[j] = str[i];
	  j++;
	  if (str[i + 1] == ' ' || str[i + 1] == '\t')
	    {
	      str[j] = ' ';
	      j++;
	    }
	}
      i++;
    }
  str[j] = '\0';
  if (j > 0 && str[j - 1] == ' ')
    str[j - 1] = '\0';
  return (str);
}
