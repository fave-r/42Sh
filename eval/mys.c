/*
** mys.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Mon May 12 15:48:41 2014 romaric
** Last update Fri May 23 21:47:54 2014 bourrel
*/

#include "my.h"

int	redir_right(t_tree *tree, int in, int out, t_env_var *env)
{
  int	ret;
  int	fd;
  int	i;

  i = 0;
  ret = 0;
  fd = -1;
  if (tree->right)
  fd = xopen(tree->right->data, O_WRONLY | O_CREAT | O_TRUNC, 0666);
  if (fd == -1)
    return (-1);
  if (out != 1)
    {
      close(fd);
      fd = out;
      i = 1;
    }
  if (tree->left)
  ret = check_fn(tree->left, in, fd, env);
  if (i != 1)
    close(fd);
  return (ret);
}

int	doble_right(t_tree *tree, int in, int out, t_env_var *env)
{
  int	ret;
  int	fd;
  int	i;

  i = 0;
  ret = 0;
  fd = -1;
  if (tree->right)
  fd = xopen(tree->right->data, O_WRONLY | O_CREAT | O_APPEND, 0666);
  if (fd == -1)
    return (-1);
  if (out != 1)
    {
      close(fd);
      fd = out;
      i = 1;
    }
  if (tree->left)
  ret = check_fn(tree->left, in, fd, env);
  if (i != 1)
    close(fd);
  return (ret);
}

int	redir_left(t_tree *tree, int in, int out, t_env_var *env)
{
  int	ret;
  int	fd;
  int	i;

  i = 0;
  ret = 0;
  fd = -1;
  if (tree->right)
  fd = xopen(tree->right->data, O_RDONLY, 0666);
  if (fd == -1)
    return (-1);
  if (in != 0)
    {
      close(fd);
      fd = in;
      i = 1;
    }
  if (tree->left)
  ret = check_fn(tree->left, fd, out, env);
  if (i != 1)
    close(fd);
  return (ret);
}

int	doble_left(t_tree *tree, __attribute__((unused))int in
		   , int out, t_env_var *env)
{
  t_lft	p;

  doble_left_next(&(p.i), &(p.ret), &(p.fd));
  if (p.fd == -1)
    return (-1);
  write(1, ">", 1);
  while ((p.str = get_next_line(0, *env)) && strcmp(p.str, tree->right->data))
    {
      my_putstr(p.str, p.fd);
      write(p.fd, "\n", 1);
      p.i = p.i + 1;
      write(1, ">", 1);
    }
  if (p.str == NULL)
    {
      fprintf(stderr, "42sh: warning: here-document at ");
      fprintf(stderr, "line %d delimited ", p.i + 1);
      fprintf(stderr, "by end-of-file (wanted `%s')\n"
	      , strdup(tree->right->data));
    }
  close(p.fd);
  p.fd = xopen(".dobleleft", O_RDONLY | O_CREAT, 0666);
  if (tree->left)
    p.ret = check_fn(tree->left, p.fd, out, env);
  return (p.ret);
}

int	my_pipe(t_tree *tree, int in, int out, t_env_var *env)
{
  int	p[2];
  int	ret;
  int	i;

  if (pipe(p) == -1)
    return (-1);
  ret = 0;
  i = env->wat;
  env->wat = 0;
  env->var_close = p[0];
  if (tree->left)
    ret = check_fn(tree->left, in, p[1], env);
  close(p[1]);
  env->var_close = -1;
  env->wat = i;
  if (tree->right)
    ret = check_fn(tree->right, p[0], out, env);
  close(p[0]);
  return (ret);
}
