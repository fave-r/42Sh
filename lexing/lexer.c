/*
** main.c for lexer in /home/thibaud/rendu/42sh
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Sat Apr 12 03:06:33 2014 thibaud
** Last update Thu May  8 18:09:05 2014 thibaud
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
  while ((str[i] == '-' || save[1] == save[0] || is_alpha(str[i]))
	 && str[i] != '\0')
    {
      while (str[i] != '\t' && str[i] != ' ' && str[i] != '\0'
	     && str[i] != '|' && str[i] != '&' && str[i] != '>' && str[i] != '<')
	i++;
      save[1] = i;
      while (((str[i] == '\t' || str[i] == ' ') && str[i] != '\0'))
	i++;
    }
  return (i);
}

t_token		*fill_token(char *str)
{
  int		i;
  int		save[2];
  t_token	*list;

  i = 0;
  list = NULL;
  while (str && str[i] != '\0')
    {
      while ((str[i] == '\t' || str[i] == ' ') && str[i] != '\0')
	i++;
      save[0] = i;
      save[1] = save[0];
      if (str[i] == '|' || str[i] == '&' || str[i] == '>'
	  || str[i] == '<' || str[i] == ';')
	{
	  i = get_operator(str, i, save);
	  list = add_token(list, my_strxdup(str + save[0], save[1] - save[0] + 1));
	}
      else if (str[i] != '\0')
	{
	  i = get_other(str, i, save);
      	  list = add_token(list, my_strxdup(str + save[0]
					    , save[1] - save[0] + 1));
	}
    }
  return (list);
}

int		fill_type(t_token *list)
{
  t_token	*cur;

  cur = list;
  if (list)
    {
      while (cur != NULL)
	{
	  if (cur->token[0] == '|' || cur->token[0] == '&' || cur->token[0] == '>'
	      || cur->token[0] == '<' || cur->token[0] == '&')
	    cur->type = 1;
	  else
	    cur->type = 2;
	  cur = cur->next;
	}
    }
  return (0);
}
