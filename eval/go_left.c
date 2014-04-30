/*
** go_left.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue Apr 29 12:07:45 2014 romaric
** Last update Tue Apr 29 14:57:40 2014 romaric
*/

#include "eval.h"

void	go_left(t_tree *tree)
{
  if (tree->left)
    go_left(tree->left);
}
