/*
** npi.h for npi in /home/lhomme_a/rendu/42Sh/NPI
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Thu Mar 27 14:07:18 2014 lhomme
** Last update Tue May  6 18:04:19 2014 lhomme
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
  void			*data;
  t_tree		*tree;
  struct s_list		*next;
}			t_list;

int	npi_add_end(t_list **list, void *data);
int	npi_add_top(t_list **list, void *data, t_tree *tree);
int	npi_delete_top(t_list **list);
int	npi_delete_last(t_list **list);
int	my_priority(char *d1, char *d2);
void	aff(t_tree *tree, int pos);
void	addNode(t_tree **tree, void *data, int pos);
t_tree	*npi(t_token *token);
void	make_tree(t_list **output, void *op);
t_tree  *createNode(t_tree *elem, void *data);

#endif
