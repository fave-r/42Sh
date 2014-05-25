/*
** make_tree.c for npi in /home/lhomme_a/rendu/42Sh/npi
**
** Made by lhomme
** Login   <lhomme_a@epitech.net>
**
** Started on  Wed Apr 23 16:33:30 2014 lhomme
** Last update Sun May 25 21:28:13 2014 romaric
*/

#include "my.h"

void		make_tree(t_list **output, void *op)
{
  t_tree	*tree;

  tree = NULL;
  addnode(&tree, op, 0);
  if (*output)
    {
      if ((*output)->tree)
	tree->right = (*output)->tree;
      else
	addnode(&tree, (*output)->data, 2);
      npi_delete_top(output);
    }
  if (*output)
    {
      if ((*output)->tree)
	tree->left = (*output)->tree;
      else
	addnode(&tree, (*output)->data, 1);
      npi_delete_top(output);
    }
  npi_add_top(output, NULL, tree);
}
