/*
** my_epur_str.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Mon Feb 10 17:00:57 2014 lhomme
** Last update Sat May 24 13:56:46 2014 bourrel
*/

#include "my.h"

char	*my_epur_str(char *str)
{
  t_get		epur;

  epur.c = 0;
  epur.l = 0;
  if (!str || str[0] == 0)
    return (NULL);
  epur.s = xmalloc(sizeof(char) * strlen(str) + 1);
  while (str[epur.c] != '\0' && str[epur.c] != '\n')
    {
      if (str[epur.c] != ' ' && str[epur.c] != '\t')
	{
	  epur.s[epur.l] = str[epur.c];
	  epur.l++;
	  if (str[epur.c + 1] == ' ' || str[epur.c + 1] == '\t')
	    {
	      epur.s[epur.l] = ' ';
	      epur.l++;
	    }
	}
      epur.c++;
    }
  epur.s[epur.l] = '\0';
  free(str);
  return (epur.s);
}
