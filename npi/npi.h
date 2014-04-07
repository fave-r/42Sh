/*
** npi.h for npi in /home/lhomme_a/rendu/42Sh/NPI
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Thu Mar 27 14:07:18 2014 lhomme
** Last update Mon Apr  7 16:29:20 2014 lhomme
*/

#ifndef NPI_H_
#define NPI_H_

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct          s_tree
{
  void			*data;
  struct s_tree		*left;
  struct s_tree		*right;
}                       t_tree;

typedef struct		s_list
{
  char			*data;
  struct s_list		*next;
}			t_list;

t_list	*add_end(void *list, void *data);
t_list	*add_top(void *list, void *data);
t_list	*delete_top(t_list *list);
void	print_list(t_list *list);

#endif
