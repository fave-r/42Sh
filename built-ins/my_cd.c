/*
** my_cd.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell1
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Dec 11 17:12:31 2013 lhomme
** Last update Mon May 19 17:48:25 2014 
*/

#include "my.h"

t_env	*my_cd_thereturn(t_env *env, t_env *tmp, char *arg)
{
  t_env	*tmp2;

  tmp2 = env->next;
  if (arg)
    {
      if (strcmp(arg, "..") == 0)
	{
	  chdir("..");
	  return (my_change_pwd(env, "..", 0));
	}
    }
  while (tmp != env && strncmp(tmp->str, "HOME=", 5) != 0)
    tmp = tmp->next;
  while (tmp2 != env && strncmp(tmp2->str, "PWD=", 4) != 0)
    tmp2 = tmp2->next;
  if (tmp != env)
    {
      chdir(tmp->str + 5);
      change_oldpwd(env, tmp2->str + 5);
      tmp2->str[4] = 0;
      tmp2->str = strcat(tmp2->str, tmp->str + 5);
      return (env);
    }
  printf("cd : 'HOME' non défini\n");
  return (env);
}

int	my_cd(t_env *env, char **tab)
{
  t_env		*tmp;

  tmp = env->next;
  if (tab[1])
    {
      if (tab[1][0] == '-')
	return (my_oldpwd(env));
      if (opendir(tab[1]) == NULL)
	{
	  printf("cd: %s: Not a directory\n", tab[1]);
	  return (-1);
	}
      chdir(tab[1]);
      env = my_swap_old(env);
      env = my_change_pwd(env, tab[1], 0);
      return (0);
    }
  env = my_cd_thereturn(env, tmp, tab[0] + 2);
  return (0);
}
