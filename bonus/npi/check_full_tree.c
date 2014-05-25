/*
** check_full_tree.c for npi in /home/lhomme_a/rendu/42Sh
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed May 21 15:20:03 2014 lhomme
** Last update Fri May 23 22:20:04 2014 lhomme
*/

#include "my.h"

int	check_full_tree(t_tree *tree, char *str)
{
 if (!tree->right && !tree->left)
   return (1);
  if (!tree->right || !tree->left)
    {
      fprintf(stderr, "'%s': syntax error\n", str);
      return (0);
    }
  return (check_full_tree(tree->left, str));
  return (check_full_tree(tree->right, str));
  return (1);
}
