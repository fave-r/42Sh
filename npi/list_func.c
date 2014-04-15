/*
** list_func.c for npi in /home/lhomme_a/rendu/42Sh/NPI
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Thu Mar 27 14:15:33 2014 lhomme
** Last update Tue Apr 15 18:26:19 2014 romaric
*/

#include "npi.h"

t_list		*add_end(void *list, void *data)
{
  t_list       *new_elem;
  t_list       *tmp;

  new_elem = malloc(sizeof(t_list));
  new_elem->data = data;
  new_elem->next = NULL;
  if (list == NULL)
    return (new_elem);
  else
    {
      tmp = list;
      while (tmp->next != NULL)
        tmp = tmp->next;
      tmp->next = new_elem;
      return (list);
    }
}

t_list		*add_top(void *list, void *data)
{
  t_list	*new;

  new = malloc(sizeof(t_list));
  new->data = data;
  new->next = list;
  return (new);
}

t_list		*delete_top(t_list *list)
{
  t_list	*new;

  if (list == NULL)
    return (NULL);
  new = list->next;
  free(list);
  return (new);
}

t_list		*delete_list(t_list *list)
{
  t_list       *tmp;
  t_list       *tmpnxt;

  tmp = list;
  while (tmp != NULL)
    {
      tmpnxt = tmp->next;
      free(tmp);
      tmp = tmpnxt;
    }
  return (NULL);
}

void		print_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      printf("%s\n", tmp->data);
      tmp = tmp->next;
    }
}
