/*
** main.c for lexer in /home/thibaud/rendu/42sh
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Sat Apr 12 03:06:33 2014 thibaud
** Last update Tue Apr 15 00:07:55 2014 thibaud
*/

#include "my.h"

void		*my_xdup(void *source, int size)
{
  char		*tmp;
  char		*src;
  int		i;

  i = 0;
  src = source;
  if ((tmp = malloc(sizeof (char) * size)) == NULL)
    exit(0);
  while (i < size)
    {
      tmp[i] = src[i];
      i++;
    }
  tmp = (void *)tmp;
  return (tmp);
}

t_list		*fill_token(char *str)
{
  int		i;
  int		save[2];
  t_list	*list;

  i = 0;
  list = NULL;
  while (str && str[i] != '\0')
    {
      while ((str[i] == '\t' || str[i] == ' ') && str[i] != '\0')
	i++;
      save[0] = i;
      save[1] = save[0];
      if (is_spe(str[i]))
	{
	  i = get_operator(str, i, save);
	  list = add_token(list, my_xdup(str + save[0],
					    save[1] - save[0]));
	}
      else if (str[i] != '\0')
	{
	  i = get_other(str, i, save);
      	  list = add_token(list, my_xdup(str + save[0], save[1] - save[0]));
	}
    }
  return (list);
}

int		fill_type(t_list *list)
{
  t_list	*cur;

  cur = list;
  if (list)
    {
      while (cur != NULL)
	{
	  if (cur->token[0] == '|')
	    cur->type = 0;
	  else if (cur->token[0] == '<' || cur->token[0] == '>')
	    cur->type = 1;
	  else if (is_spe(cur->token[0]))
	    cur->type = 2;
	  else
	    cur->type = 3;
	  cur = cur->next;
	}
    }
  return (0);
}

t_list		*lexer(char *)
{
  t_list	*list;

  list = fill_token(str);
  fill_type(list);
  return (list);
}
