/*
** word.c for 42sh in /home/leo/rendu/42Sh/auto_completion
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Fri May 23 22:35:49 2014 bourrel
** Last update Fri May 23 22:39:51 2014 bourrel
*/

#include "my.h"

t_arbre		*add_char(char c)
{
  t_arbre	*new;

  if ((new = malloc(sizeof(t_arbre))) == NULL)
    {
      printf("Malloc error\n");
      return (NULL);
    }
  new->c = c;
  new->next = NULL;
  new->deep = NULL;
  return (new);
}

t_arbre		*creat_word(char *str)
{
  t_arbre	*new;
  t_arbre	*cur;
  int		i;

  i = 1;
  new = add_char(str[0]);
  cur = new;
  while (str[i])
    {
      cur->deep = add_char(str[i]);
      cur = cur->deep;
      i++;
    }
  if (i != 0)
    cur->deep = add_char(' ');
  else
    cur->next = add_char(' ');
  return (new);
}

int		add_word(t_arbre *arbre, char *str)
{
  int		i;
  t_arbre	*cur;

  i = 0;
  cur = arbre;
  while (str && i <= my_strlen(str))
    {
      if (cur->c != str[i] && !cur->next)
	{
	  cur->next = creat_word(str + i);
	  return (0);
	}
      else if (cur->c == str[i])
	cur = cur->deep;
      else
	{
	  cur = cur->next;
	  i--;
	}
      i++;
    }
  return (-1);
}
