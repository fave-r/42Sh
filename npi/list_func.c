/*
** list_func.c for npi in /home/lhomme_a/rendu/42Sh/NPI
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Thu Mar 27 14:15:33 2014 lhomme
** Last update Thu May 22 16:25:55 2014 lhomme
*/

#include "my.h"

int	npi_add_end(t_list **list, void *data)
{
  t_list       *elem;
  t_list       *tmp;

  tmp = *list;
  elem = malloc(sizeof(t_list));
  if (elem == NULL)
    return (-1);
  elem->data = data;
  elem->next = NULL;
  if (tmp == NULL)
    *list = elem;
  else
    {
      while (tmp->next != NULL)
        tmp = tmp->next;
      tmp->next = elem;
    }
  return (0);
}

int	npi_add_top(t_list **list, void *data, t_tree *tree)
{
  t_list	*new;
  t_list	*tmp;

  tmp = *list;
  new = malloc(sizeof(t_list));
  if (new == NULL)
    return (-1);
  new->data = data;
  new->tree = tree;
  new->next = tmp;
  *list = new;
  return (0);
}

void	npi_delete_list(t_list **list)
{
  t_list       *tmp;
  t_list       *tmpnxt;

  tmp = *list;
  while (tmp != NULL)
    {
      tmpnxt = tmp->next;
      free(tmp);
      tmp = tmpnxt;
    }
  *list = tmp;
}

int	npi_delete_last(t_list **list)
{
  t_list	*tmp;
  t_list	*ptmp;

  tmp = *list;
  ptmp = *list;
  if (tmp == NULL || tmp->next == NULL)
    {
      free(tmp);
      *list = NULL;
    }
  else
    {
      while (tmp->next != NULL)
	{
	  ptmp = tmp;
	  tmp = tmp->next;
	}
      ptmp->next = NULL;
      free(tmp);
    }
  return (0);
}

int	npi_delete_top(t_list **list)
{
  t_list	*new;
  t_list	*tmp;

  tmp = *list;
  if (list == NULL)
    return (-1);
  new = tmp->next;
  free(tmp);
  *list = new;
  return (0);
}
