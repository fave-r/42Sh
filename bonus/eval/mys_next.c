/*
** mys_next.c for 42sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri May 23 13:39:34 2014 romaric
** Last update Fri May 23 17:01:37 2014 romaric
*/

#include "my.h"

int	my_semi_col(t_tree *tree, int in, int out, t_env_var *env)
{
  if (!tree->right)
    return (check_fn(tree->left, in, out, env));
  if (tree->left)
    check_fn(tree->left, in, out, env);
  return (check_fn(tree->right, in, out, env));
}

int	my_and(t_tree *tree, int in, int out, t_env_var *env)
{
  int	ret;

  ret = 1;
  if (tree->left)
    ret = check_fn(tree->left, in, out, env);
  if (ret == 0 && tree->right)
    ret = check_fn(tree->right, in, out, env);
  return (ret);
}

int	my_or(t_tree *tree, int in, int out, t_env_var *env)
{
  int	ret;

  ret = 0;
  if (tree->left)
    ret = check_fn(tree->left, in, out, env);
  if (ret != 0 && tree->right)
    ret = check_fn(tree->right, in, out, env);
  return (ret);
}

void	doble_left_next(int *i, int *ret, int *fd)
{
  *i = 0;
  *ret = 0;
  *fd = xopen(".dobleleft", O_RDWR | O_CREAT | O_TRUNC, 0666);
}
