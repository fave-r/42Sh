/*
** arbrebinairedetest.c for 42sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri Apr 25 17:34:41 2014 romaric
** Last update Sun May 11 15:07:39 2014 romaric
*/

#include "eval.h"

void    aff(t_tree *tree, int pos)
{
  int   i;

  i = -5;
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

t_tree  *createNode(t_tree *elem, void *data)
{
  elem = xmalloc(sizeof(t_tree));
  if (elem == NULL)
    return (NULL);
  elem->data = data;
  elem->left = NULL;
  elem->right = NULL;
  return (elem);
}

void    Node_add(t_tree *tmpTree, t_tree *elem, int pos)
{
  t_tree        *tmpNode;

  while (tmpTree)
    {
      tmpNode = tmpTree;
      if (pos == 1 || pos == 3)
        {
          tmpTree = tmpTree->left;
          if (!tmpTree)
	    {
	      if (pos == 3)
		tmpNode->right = elem;
	      else
		tmpNode->left = elem;
	    }
        }
      else if (pos == 2)
        {
          tmpTree = tmpTree->right;
          if (!tmpTree)
            tmpNode->right = elem;
        }
    }
}

void    addNode(t_tree **tree, void *data, int pos)
{
  t_tree        *tmpTree;
  t_tree        *elem;

  tmpTree = *tree;
  elem = NULL;
  elem = createNode(elem, data);
  if (!tmpTree)
    *tree = elem;
  else
    Node_add(tmpTree, elem, pos);
}

int	main()
{
  t_tree	*tree;

  tree = NULL;
  //addNode(&tree, "coucou", 0);
  addNode(&tree, ">", 1);
  addNode(&tree, "ls", 1);
  addNode(&tree, "toto", 2);
  //addNode(&tree, "cat", 3);
  //aff(tree, 0);
  //go_left(tree);
  check_fn(tree, 0, 1);
  return (0);
}
