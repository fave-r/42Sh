/*
** mys.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon May 12 15:48:41 2014 romaric
** Last update Tue May 20 12:23:06 2014 romaric
*/

#include "my.h"

int	my_semi_col(t_tree *tree, int in, int out, t_env **env)
{
  if (!tree->right)
    return (check_fn(tree->left, in, out, &(*env)));
  if (tree->left)
    check_fn(tree->left, in, out, &(*env));
  return (check_fn(tree->right, in, out, &(*env)));
}

int	my_and(t_tree *tree, int in, int out, t_env **env)
{
  int	ret;

  ret = check_fn(tree->left, in, out, &(*env));
  if (ret == 0)
    ret = check_fn(tree->right, in, out, &(*env));
  return (ret);
}

int	my_or(t_tree *tree, int in, int out, t_env **env)
{
  int	ret;

  ret = check_fn(tree->left, in, out, &(*env));
  if (ret != 0)
    ret = check_fn(tree->right, in, out, &(*env));
  return (ret);
}

int	redir_right(t_tree *tree, int in, int out, t_env **env)
{
  int	ret;
  int	fd;
  int	i;
  int	save;

  i = 0;
  save = out;
  fd = xopen(tree->right->data, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (fd == -1)
    return (-1);
  if (out != 1)
    {
      close(fd);
      fd = out;
      i = 1;
    }
  ret = check_fn(tree->left, in, fd, &(*env));
  if (i != 1)
    close(fd);
  return (ret);
}

int	doble_right(t_tree *tree, int in, int out, t_env **env)
{
  int	ret;
  int	fd;
  int	i;

  i = 0;
  fd = xopen(tree->right->data, O_WRONLY | O_CREAT | O_APPEND, 0666);
  if (fd == -1)
    return (-1);
  if (out != 1)
    {
      close(fd);
      fd = out;
      i = 1;
    }
  ret = check_fn(tree->left, in, fd, &(*env));
  if (i != 1)
    close(fd);
  return (ret);
}

int	redir_left(t_tree *tree, int in, int out, t_env **env)
{
  int	ret;
  int	fd;
  int	i;

  i = 0;
  fd = xopen(tree->right->data, O_RDONLY, 0666);
  if (fd == -1)
    return (-1);
  if (in != 0)
    {
      close(fd);
      fd = in;
      i = 1;
    }
  ret = check_fn(tree->left, fd, out, &(*env));
  if (i != 1)
    close(fd);
  return (ret);
}

int	doble_left(t_tree *tree, int in, int out, t_env **env)
{
  int	ret;
  int	fd;
  int	i;
  int	save;
  char	*str;

  i = 0;
  save = out;
  fd = xopen(".dobleleft", O_WRONLY | O_RDONLY | O_CREAT | O_TRUNC, 0666);
  if (fd == -1)
    return (-1);
  while ((str = get_next_line(0)) && strcmp(str, tree->right->data) != 0)
    {
      my_putstr(str, fd);
      i++;
    }
  if (str == NULL)
    {
      fprintf(stderr, "42sh: warning: here-document at line %d delimited by end-of-file (wanted `%s')\n", i+1, tree->right->data);
    }
  //close(fd);
  ret = check_fn(tree->left, in, fd, &(*env));
  return (ret);
}
