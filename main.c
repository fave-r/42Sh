/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
** Last update Thu May 22 14:59:41 2014 lhomme
*/

#include "my.h"

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

void		start(t_token *list, t_env_var env, t_tree *tree, char *tmp)
{
  list = fill_token(tmp);
  tree = npi(list, tmp, env.env);
  check_fn(tree, 0, 1, &env);
  init();
  free_tree(tree);
  delete_list(&list);
}

int		exit_42(char *tmp, t_env_var env, int ret)
{
  unset_term();
  free(tmp);
  my_delete_envlist(&(env.env));
  return (ret);
}

void		init_main(t_env_var *env, char **envp, int *ret, t_token **list)
{
  init();
  *list = NULL;
  *ret = 0;
  env->env = my_env_inlist(envp);
  env->wat = 1;
  env->var_close = -1;
  display_prompt();
}

int		main(int ac, char **av, char **envp)
{
  t_token	*list;
  t_env_var	env;
  t_tree	*tree;
  char		*tmp;
  int	ret;

  tree = NULL;
  if (ac > 1 || av[1] != NULL)
    return (0);
  init_main(&env, envp, &ret, &list);
  signal(SIGINT, &display_sigint);
  while ((tmp = get_next_line_icanon(0)) != NULL)
    {
      tmp = my_epur_str(tmp);
      if (tmp && tmp[0] != 0)
	{
	  start(list, env, tree, tmp);
	  if ((ret = check_exit(env.env)) != -1)
	    return (exit_42(tmp, env, ret));
	}
      display_prompt();
    }
  write(1, "\n", 1);
  return (exit_42(tmp, env, 0));
}
