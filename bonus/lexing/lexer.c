/*
** main.c for lexer in /home/thibaud/rendu/42sh
**
** Made by thibaud
** Login   <thibaud@epitech.net>
**
** Started on  Sat Apr 12 03:06:33 2014 thibaud
** Last update Sun May 25 20:27:58 2014 romaric
*/

#include "my.h"

char		*my_strxdup(char *source, int len)
{
  char		*copy;
  int		i;

  i = 0;
  copy = xmalloc(sizeof(char) * len + 1);
  while (i < len - 1)
    {
      copy[i] = source[i];
      i++;
    }
  copy[i] = '\0';
  return (copy);
}

int		get_operator(char *str, int i, int save[2])
{
  if (str[i] == str[i + 1])
    i += 2;
  else
    i++;
  save[1] = i;
  return (i);
}

int		get_other(char *str, int i, int save[2])
{
  int		quote;

  quote = 0;
  while (str[i] && (save[1] == save[0] || !is_spe(str[i])))
    {
      while ((str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != ';'
	     && str[i] != '|' && str[i] != '&' && str[i] != '>' && str[i] != '<')
	     || (str[i] && quote % 2 != 0))
	{
	  if (str[i] == 34 || str[i] == 39)
	    quote++;
	  i++;
	}
      save[1] = i;
      while (str[i] && (str[i] == '\t' || str[i] == ' '))
	i++;
    }
  return (i);
}

t_token		*fill_token(char *str)
{
  int		i;
  int		s[2];
  t_token	*list;

  i = 0;
  list = NULL;
  while (str && str[i] != '\0')
    {
      while ((str[i] == '\t' || str[i] == ' ') && str[i] != '\0')
	i++;
      s[0] = i;
      s[1] = s[0];
      if (str[i] == '|' || str[i] == '&' || str[i] == '>'
	  || str[i] == '<' || str[i] == ';')
	{
	  i = get_operator(str, i, s);
	  list = add_token(list, my_strxdup(str + s[0], s[1] - s[0] + 1));
	}
      else if (str[i] != '\0')
	{
	  i = get_other(str, i, s);
      	  list = add_token(list, my_strxdup(str + s[0], s[1] - s[0] + 1));
	}
    }
  return (list);
}
