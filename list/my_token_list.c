/*
** my_token_list.c for my_token_list in /home/alex-odet/work/42Sh/list
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Apr 15 18:14:13 2014 alex-odet
** Last update Wed May 14 15:56:32 2014 
*/

#include "my.h"

t_token		*add_token(t_token *list, char *token)
{
  t_token	*new;
  t_token	*tmp;

  tmp = list;
  new = xmalloc(sizeof(t_token));
  new->token = token;
  new->next = NULL;
  if (list == NULL)
    return (new);
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = new;
  return (list);
}

void    delete_list(t_token **list)
{
  t_token	*tmp;
  t_token	*tmpnxt;

  tmp = *list;
  while (tmp != NULL)
    {
      tmpnxt = tmp->next;
      free(tmp);
      tmp = tmpnxt;
    }
  *list = tmp;
}
