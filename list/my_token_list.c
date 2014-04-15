/*
** my_token_list.c for my_token_list in /home/alex-odet/work/42Sh/list
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Apr 15 18:14:13 2014 alex-odet
** Last update Tue Apr 15 18:18:36 2014 alex-odet
*/

#include "my.h"

t_token		*add_token(t_token *list, char *token)
{
  t_token	*new;
  t_token	*tmp;

  tmp = list;
  new = xmalloc(sizeof(t_token));
  new->token = token;
  new->type = 0;
  new->next = NULL;
  if (list == NULL)
    return (new);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  return (list);
}
