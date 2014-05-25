/*
** print_history.c for history in /home/lhomme_a/rendu/42Sh/bonus
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Sun May 25 15:30:33 2014 lhomme
** Last update Sun May 25 17:03:55 2014 lhomme
*/

#include "my.h"

int	is_nb(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int	size_history(t_env *history, int nb)
{
  int	i;
  t_env	*tmp;

  if (nb == 0)
    return (1);
  i = 1;
  tmp = history->next;
  while (tmp != history)
    {
      i++;
      tmp = tmp->next;
    }
  if (nb >= i)
    return (1);
  return (i - nb);
}

int	print_hist(t_env *history, t_env *tmp, int fd, int nb)
{
  int	line;

  line = size_history(history, nb);
  while (tmp != history)
    {
      my_put_nbr(line, fd);
      my_putchar('\t', fd);
      my_putstr(tmp->str, fd);
      my_putchar('\n', fd);
      tmp = tmp->next;
      line++;
    }
  return (0);
}

int	hist_arg(t_env *history, char *arg, int fd)
{
  t_env	*tmp;
  int	nb;

  if (is_nb(arg) == -1)
    {
      fprintf(stderr, "history: %s: numeric argument required\n", arg);
      return (-1);
    }
  nb = my_getnbr(arg);
  if (nb < 0)
    {
      fprintf(stderr, "history: %s: invalid option\n", arg);
      return (-1);
    }
  if (nb == 0)
    return (0);
  tmp = history->prev;
  while (tmp != history && nb > 1)
    {
      tmp = tmp->prev;
      nb--;
    }
  if (tmp == history)
    tmp = tmp->next;
  return (print_hist(history, tmp, fd, my_getnbr(arg)));
}

int	my_print_history(t_env *env, t_env *history, char **tab, int fd)
{
  if (!env || env->next == env)
    {
      fprintf(stderr, "env: history: No such file or directory\n");
      return (-1);
    }
  if (!history || history->next == env)
    {
      fprintf(stderr, "history: Empty history\n");
      return (-1);
    }
  if (!tab[1])
    return (print_hist(history, history->next, fd, 0));
  else if (tab[2])
    {
      fprintf(stderr, "history: Too many arguments\n");
      return (-1);
    }
  else
    return (hist_arg(history, tab[1], fd));
  return (0);
}
