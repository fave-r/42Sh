/*
** epur_str.c for minishell in /home/blackbird/work/minishell/2
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Thu Mar  6 17:15:43 2014 romaric
** Last update Thu Mar  6 18:15:38 2014 romaric
*/

#include "minishell.h"

char	*epur_str(char *str)
{
  char	*tmp;
  int	i;
  int	k;

  i = 0;
  k = 0;
  tmp = xmalloc(sizeof(*tmp) * (my_strlen(str) + 1));
  while ((str[i] == ' ') || (str[i] == '\t'))
    i++;
  while (str[i] != '\0')
    {
      tmp[k++] = str[i++];
      while ((str[i] == ' ') || (str[i] == '\t'))
	i++;
      if (((str[i - 1] == ' ') || (str[i - 1] == '\t')) && (str[i] != '\0'))
	{
	  tmp[k] = ' ';
	  k++;
	}
    }
  tmp[k] = '\0';
  free(str);
  return (tmp);
}
