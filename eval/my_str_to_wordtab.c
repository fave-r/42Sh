/*
** my_str_to_wordtab.c for minishell in /home/blackbird/work/minishell/1
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Dec 18 13:38:53 2013 romaric
** Last update Sun May 11 18:05:01 2014 romaric
*/

#include "my.h"

int	countword(char *str, char sep)
{
  int i;
  int word;

  i = 0;
  word = 0;
  while (str[i] != '\0')
    {
      while ((str[i] == sep || str[i] == '\t') && str[i] != '\0')
	i++;
      if (str[i] != sep && str[i] != '\t' && str[i] != '\0')
	word++;
      while (str[i] != sep && str[i] != '\t' && str[i] != '\0')
	i++;
    }
  return (word);
}

char	**my_str_to_wordtab(char *str, char sep)
{
  t_word	w;

  w.i = 0;
  w.nbwords = countword(str, sep);
  w.strpar = xmalloc(sizeof(char*) * (w.nbwords + 1) + my_strlen_n(str) + 1);
  w.ptr = (char*)w.strpar;
  w.ptr += sizeof(char*) * (w.nbwords + 1);
  w.ptr = strdup(str);
  while (*(w.ptr) != '\0')
    {
      while ((*(w.ptr) == sep || *(w.ptr) == '\t') && *(w.ptr) != '\0')
	{
	  *(w.ptr) = '\0';
	  w.ptr += 1;
	}
      if (*(w.ptr) != sep && *(w.ptr) != '\t' && *(w.ptr) != '\0')
	{
	  w.strpar[w.i] = w.ptr;
	  w.i += 1;
	}
      while (*(w.ptr) != sep && *(w.ptr) != '\t' && *(w.ptr) != '\0')
	w.ptr += 1;
    }
  w.strpar[w.i] = 0;
  return (w.strpar);
}
