/*
** my_cd.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell1
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Dec 11 17:12:31 2013 lhomme
** Last update Fri May 16 10:39:12 2014 
*/

#include "../my.h"

t_env	*my_cd_thereturn(t_env *env, t_env *tmp, char *arg)
{
  if (arg)
    {
      if (strcmp(arg, "..") == 1)
	{
	  chdir("..");
	  return (my_change_pwd(env, "..", 0));
	}
    }
  while (strncmp(tmp->str, "HOME=", 5) != 0)
    tmp = tmp->next;
  chdir(tmp->str + 5);
  return (my_change_pwd(env, tmp->str + 5, 0));
}

int	my_cd(t_env *env, char **tab)
{
  t_env		*tmp;

  tmp = env->next;
  if (tab[1])
    {
      if (tab[1][0] == '-')
	{
	  env = my_oldpwd(env);
	  return (0);
	}
      if (opendir(tab[1]) == NULL)
	{
	  printf("cd: %s: Not a directory\n", tab[1]);
	  return (-1);
	}
      chdir(tab[1]);
      env = my_change_pwd(env, tab[1], 0);
      return (0);
    }
  env = my_cd_thereturn(env, tmp, tab[1]);
  return (0);
}
