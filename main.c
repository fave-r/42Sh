/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
** Last update Wed May 21 19:35:38 2014 bourrel
*/

#include "my.h"

void		my_show_list(t_token *list)
{
  while (list)
    {
      printf("token = %s\n", list->token);
      list = list->next;
    }
}

void		display_prompt()
{
  write(1, "$> ", 3);
}

void		display_sigint()
{
  write(1, "\n$> ", 4);
}

int	check_exit(t_env *env)
{
  int	ret;

  if (env->next->str[12] == 0
      || strncmp(env->next->str, "EXIT_VALUE", 10) != 0)
    return (-1);
  ret = my_getnbr(env->next->str + 12);
  if (ret > 0)
    return (ret % 256);
  if (ret == 0)
    return (-1);
  while (ret < 0)
    ret = ret + 256;
  return (ret);
}

int		main(int ac, char **av, char **envp)
{
  t_token	*list;
  t_env_var	env;
  t_tree	*tree;
  char		*tmp;
  int		ret;

  tree = NULL;
  tmp = xmalloc(4096 * sizeof(char));
  if (ac > 1 || av[1] != NULL)
    return (0);
  list = NULL;
  env.env = my_env_inlist(envp);
  display_prompt();
  env.wat = 1;
  env.var_close = -1;
  signal(SIGINT, &display_sigint);
  while ((tmp = get_next_line_icanon(0)) != NULL)
    {
      tmp = my_epur_str(tmp);
      if (tmp && tmp[0] != 0)
	{
	  list = fill_token(tmp);
	  tree = npi(list, tmp);
	  check_fn(tree, 0, 1, &env);
	  free_tree(tree);
	  delete_list(&list);
	  if ((ret = check_exit(env.env)) != -1)
	    {
	      free(tmp);
	      my_delete_envlist(&(env.env));
	      return (ret);
	    }
	}
      display_prompt();
    }
  write(1, "\n", 1);
  free(tmp);
  my_delete_envlist(&(env.env));
  return (0);
}
