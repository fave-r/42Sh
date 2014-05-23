/*
** tree_func.c for npi in /home/lhomme_a/rendu/42Sh/npi
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Apr 23 15:44:31 2014 lhomme
** Last update Fri May 23 16:43:21 2014 bourrel
*/

#include "my.h"

void	free_tree(t_tree *tree)
{
  if (tree != NULL)
    {
      free_tree(tree->left);
      free_tree(tree->right);
      free(tree);
    }
}

t_tree	*createNode(t_tree *elem, void *data)
{
  elem = malloc(sizeof(t_tree));
  if (elem == NULL)
    return (NULL);
  elem->data = data;
  elem->left = NULL;
  elem->right = NULL;
  return (elem);
}

void	Node_add(t_tree *tmpTree, t_tree *elem, int pos)
{
  t_tree	*tmpNode;

  while (tmpTree)
    {
      tmpNode = tmpTree;
      if (pos == 1)
	{
	  tmpTree = tmpTree->left;
	  if (!tmpTree)
	    tmpNode->left = elem;
	}
      else if (pos == 2)
	{
	  tmpTree = tmpTree->right;
	  if (!tmpTree)
	    tmpNode->right = elem;
	}
    }
}

void	addNode(t_tree **tree, void *data, int pos)
{
  t_tree	*tmpTree;
  t_tree	*elem;

  tmpTree = *tree;
  elem = NULL;
  elem = createNode(elem, data);
  if (!tmpTree)
    *tree = elem;
  else
    Node_add(tmpTree, elem, pos);
}
