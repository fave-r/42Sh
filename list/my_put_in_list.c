/*
** my_put_in_list.c for my_put_in_list in /home/alex-odet/work/42Sh/List
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr  3 13:39:42 2014 alex-odet
** Last update Thu Apr  3 13:59:03 2014 alex-odet
*/

#include "my.h"

t_token		*new_node(char *token, int type)
{
  t_token	*new;

  new = xmalloc(sizeof(t_token));
  new->buff = token;
  new->type = type;
  new->next = NULL;
  return (new);
}

t_token		*my_put_in_list(t_token *list, char *token, int type)
{
  t_token	*tmp;

  if (list == NULL)
    return (new_node(token, type));
  tmp = list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new_node(token, type);
  return(list);
}
