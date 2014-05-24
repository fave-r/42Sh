/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
** Last update Sun May 25 00:28:26 2014 lhomme
*/

#include "my.h"

extern char	**environ;

int		check_exit(t_env *env)
{
  t_env		*tmp;
  int		ret;

  tmp = env->next;
  while (tmp != env && strncmp(tmp->str, "EXIT_VALUE", 10) != 0)
    tmp = tmp->next;
  if (tmp == env)
    return (-1);
  if (tmp->str[12] == 0)
    return (-1);
  ret = my_getnbr(tmp->str + 12);
  if (ret > 0)
    return (ret % 256);
  if (ret == 0)
    return (-1);
  while (ret < 0)
    ret = ret + 256;
  return (ret);
}

void		start(t_token *list, t_env_var env, char *tmp)
{
  t_tree	*tree;

  tree = NULL;
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
  signal(SIGINT, &display_sigint);
  init();
  *list = NULL;
  *ret = 0;
  env->env = my_env_inlist(envp);
  env->wat = 1;
  env->var_close = -1;
  display_prompt(env->env);
}

int		main(void)
{
  t_token	*list;
  t_env_var	env;
  char		*tmp;
  int		ret;

  signal(SIGINT, &display_sigint);
  init_main(&env, environ, &ret, &list);
  while ((tmp = my_istty(0, env)) != NULL)
    {
      tmp = my_epur_str(tmp);
      if (tmp && tmp[0] != 0)
	{
	  start(list, env, tmp);
	  if ((ret = check_exit(env.env)) != -1)
	    return (exit_42(tmp, env, ret));
	}
      display_prompt(env.env);
    }
  write(1, "\n", 1);
  return (exit_42(tmp, env, 0));
}
