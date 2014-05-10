/*
** semi_col.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sat May 10 10:32:33 2014 romaric
** Last update Sat May 10 13:33:05 2014 romaric
*/

int	my_semi_col(t_tree *tree, int in, int out)
{
  check_fn(tree->left, in, out);
  return(check_fn(tree->right, in, out))
}

int	my_and(t_tree *tree, int in, int out)
{
  int	ret;

  ret = check_fn(tree->left, in, out);
  if (ret == 0)
    ret = check_fn(tree->right, in, out);
  return (ret);
}

int	my_or(t_tree *tree, int in, int out)
{
  int	ret;

  ret = check_fn(tree->left, in, out);
  if (ret != 0)
    ret = check_fn(tree->right, in, out);
  return (ret);
}

int	redir_right(t_tree *tree, int in, int out)
{
  int	ret;
  int	fd;
  int	i;

  i = 0;
  fd = xopen(tree->right, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (fd == -1)
    return (-1);
  if (out != 1)
    {
      close(fd);
      fd = out;
      i = 1;
    }
  ret = check_fn(tree->left, in, fd);
  if (i != 1)
  close(fd);
  return (ret);
}

int	doble_right(t_tree *tree, int in, int out)
{
  int	ret;
  int	fd;
  int	i;

  i = 0;
  fd = xopen(tree->right, O_WRONLY | O_CREAT | O_APPEND, 0666);
  if (fd == -1)
    return (-1);
  if (out != 1)
    {
      close(fd);
      fd = out;
      i = 1;
    }
  ret = check_fn(tree->left, in, fd);
  if (i != 1)
  close(fd);
  return (ret);
}

int	redir_left(t_tree *tree, int in, int out)
{
  int	ret;
  int	fd;
  int	i;

  i = 0;
  fd = xopen(tree->right, O_RDONLY);
  if (fd == -1)
    return (-1);
  if (in != 0)
    {
      close(fd);
      fd = in;
      i = 1;
    }
  ret = check_fn(tree->left, fd, out);
  if (i != 1)
  close(fd);
  return (ret);
}