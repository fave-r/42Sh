/*
** tree_func.c for npi in /home/lhomme_a/rendu/42Sh/npi
**
** Made by lhomme
** Login   <lhomme_a@epitech.net>
**
** Started on  Wed Apr 23 15:44:31 2014 lhomme
** Last update Sun May 25 20:44:46 2014 romaric
*/

#include "my.h"

void		aff(t_tree *tree, int pos)
{
  int		i;

  i = -5;
  if (tree)
    {
      while (i < pos)
	{
	  printf("_");
	  i++;
	}
      printf("%d %s\n", pos, strdup(tree->data));
      if (tree->left)
	{
	  printf("left ");
	  aff(tree->left, pos - 2);
	}
      if (tree->right)
	{
	  printf("right ");
	  aff(tree->right, pos + 3);
	}
    }
}

void		free_tree(t_tree *tree)
{
  if (tree != NULL)
    {
      free_tree(tree->left);
      free_tree(tree->right);
      free(tree);
    }
}

t_tree		*createnode(t_tree *elem, void *data)
{
  elem = malloc(sizeof(t_tree));
  if (elem == NULL)
    return (NULL);
  elem->data = data;
  elem->left = NULL;
  elem->right = NULL;
  return (elem);
}

void		node_add(t_tree *tmptree, t_tree *elem, int pos)
{
  t_tree	*tmpnode;

  while (tmptree)
    {
      tmpnode = tmptree;
      if (pos == 1)
	{
	  tmptree = tmptree->left;
	  if (!tmptree)
	    tmpnode->left = elem;
	}
      else if (pos == 2)
	{
	  tmptree = tmptree->right;
	  if (!tmptree)
	    tmpnode->right = elem;
	}
    }
}

void		addnode(t_tree **tree, void *data, int pos)
{
  t_tree	*tmptree;
  t_tree	*elem;

  tmptree = *tree;
  elem = NULL;
  elem = createnode(elem, data);
  if (!tmptree)
    *tree = elem;
  else
    node_add(tmptree, elem, pos);
}
