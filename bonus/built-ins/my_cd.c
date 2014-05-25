/*
** my_cd.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell1
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Dec 11 17:12:31 2013 lhomme
** Last update Sat May 24 19:53:58 2014 lhomme
*/

#include "my.h"

int	print_oldpwd(t_env *env)
{
  t_env	*oldpwd;
  t_env	*tmp;
  int	i;

  i = 3;
  oldpwd = env->next;
  tmp = env->prev;
  while (strncmp(oldpwd->str, "PWD", 3) != 0)
    {
      if (oldpwd == tmp)
	return (1);
      oldpwd = oldpwd->next;
    }
  if (oldpwd->str[i])
    {
      while (oldpwd->str[++i])
	my_putchar(oldpwd->str[i], 1);
      my_putchar('\n', 1);
    }
  return (1);
}

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
      if (tmp2 == env)
	return (env);
      change_oldpwd(env, tmp2->str + 5);
      tmp2->str[4] = 0;
      tmp2->str = strcat(tmp2->str, tmp->str + 5);
      return (env);
    }
  fprintf(stderr, "42sh: cd: 'HOME' not set\n");
  return (env);
}

int	empty_pwd(t_env *env)
{
  t_env	*tmp;

  tmp = env->next;
  while (tmp != env && strncmp(tmp->str, "PWD=", 4) != 0)
    tmp = tmp->next;
  if (tmp != env)
    tmp->str[4] = 0;
  return (0);
}

int	cd_error(char *pwd)
{
  if (errno == EACCES)
    fprintf(stderr, "cd: %s: Permission denied\n", pwd);
  else
    fprintf(stderr, "cd: %s: No such file or directory\n", pwd);
  return (-1);
}

int	my_cd(t_env *env, char **tab)
{
  t_env		*tmp;

  tmp = env->next;
  if (tab[1])
    {
      if (tab[1][0] == '/')
	empty_pwd(env);
      if (tab[1][0] == '-')
	{
	  print_oldpwd(env);
	  return (my_oldpwd(env));
	}
      if (opendir(tab[1]) == NULL)
	return (cd_error(tab[1]));
      chdir(tab[1]);
      env = my_swap_old(env);
      env = my_change_pwd(env, tab[1], 0);
      return (0);
    }
  env = my_cd_thereturn(env, tmp, tab[0] + 2);
  return (0);
}
