/*
** check_full_tree.c for npi in /home/lhomme_a/rendu/42Sh
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed May 21 15:20:03 2014 lhomme
** Last update Wed May 21 15:31:08 2014 lhomme
*/

#include "my.h"

int	check_full_tree(t_tree *tree)
{
  if (!tree->right || !tree->left)
    return (0);
  return (check_full_tree(tree->left));
  return (check_full_tree(tree->right));
  return (1);
}
