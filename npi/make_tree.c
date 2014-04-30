/*
** make_tree.c for npi in /home/lhomme_a/rendu/42Sh/npi
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Apr 23 16:33:30 2014 lhomme
** Last update Wed Apr 30 15:04:57 2014 lhomme
*/

#include "npi.h"

void	make_tree(t_list **output, void *op)
{
  t_tree	*tree;

  tree = NULL;
  addNode(&tree, op, 0);
  if (*output)
    {
      if ((*output)->tree)
	tree->right = (*output)->tree;
      else
	addNode(&tree, (*output)->data, 2);
      delete_top(output);
    }
  if (*output)
    {
      if ((*output)->tree)
	tree->left = (*output)->tree;
      else
	addNode(&tree, (*output)->data, 1);
      delete_top(output);
    }
  add_top(output, NULL, tree);
}
