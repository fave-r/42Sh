/*
** list_func.c for npi in /home/lhomme_a/rendu/42Sh/NPI
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Thu Mar 27 14:15:33 2014 lhomme
<<<<<<< HEAD
** Last update Wed Apr 30 18:13:51 2014 lhomme
=======
** Last update Tue Apr 15 18:26:19 2014 romaric
>>>>>>> 994c751f1e558733ec8eb2745749d5cd4f75c6d1
*/

#include "npi.h"

int	add_end(t_list **list, void *data)
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

int	add_top(t_list **list, void *data, t_tree *tree)
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

void	delete_list(t_list **list)
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

int	delete_last(t_list **list)
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

int	delete_top(t_list **list)
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
