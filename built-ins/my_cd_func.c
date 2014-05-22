/*
** my_cd_func.c for my_cd in /home/lhomme_a/rendu/PSU_2013_minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Fri Mar 21 14:22:18 2014 lhomme
** Last update Thu May 22 18:19:48 2014 bourrel
*/

#include "my.h"

void	change_oldpwd(t_env *env, char *pwd)
{
  t_env		*tmp;

  tmp = env->next;
  while (tmp != env && strncmp(tmp->str, "OLDPWD", 6) != 0)
    tmp = tmp->next;
  if (tmp != env)
    {
      tmp->str[7] = 0;
      tmp->str = my_strcat(tmp->str, pwd);
    }
  else
    env = my_add_env(env, my_strcat("OLDPWD=", pwd));
}

int	my_oldpwd(t_env *env)
{
  t_env	*oldpwd;
  t_env	*pwd;
  char	*str;
  char	*str2;

  oldpwd = env->next;
  pwd = env->next;
  while (oldpwd != env && strncmp(oldpwd->str, "OLDPWD", 6) != 0)
    oldpwd = oldpwd->next;
  if (oldpwd == env)
    {
      printf("cd : 'OLDPWD' non défini\n");
      return (-1);
    }
  chdir(oldpwd->str + 7);
  str = strdup(oldpwd->str + 6);
  while (strncmp(pwd->str, "PWD", 3) != 0)
    pwd = pwd->next;
  str2 = strdup(pwd->str + 3);
  oldpwd->str[6] = 0;
  pwd->str[3] = 0;
  oldpwd->str = my_strcat(oldpwd->str, str2);
  pwd->str = my_strcat(pwd->str, str);
  return (0);
}

char	*my_dup_pwd(char *pwd)
{
  char	*tmp;
  int	i;
  int	j;

  i = 2;
  j = 0;
  tmp = xmalloc(sizeof(char) * (strlen(pwd) - 1));
  while (pwd[i] != 0)
    {
      tmp[j] = pwd[i];
      i++;
      j++;
    }
  tmp[j] = 0;
  return (tmp);
}

t_env	*my_change_pwd(t_env *env, char *pwd, int i)
{
  t_env	*tmp;

  tmp = env->next;
  while (tmp != env && strncmp(tmp->str, "PWD=", 4) != 0)
    tmp = tmp->next;
  if (tmp == env)
    return (env);
  if ((strcmp(pwd, "..") == 0) || (strncmp(pwd, "..", 2) == 0))
    {
      while (tmp->str[i] != 0)
	i++;
      while (tmp->str[i] != '/')
	i--;
      tmp->str[i] = 0;
      if (pwd[2] != 0)
	my_change_pwd(env, my_dup_pwd(pwd), 0);
    }
  else
    {
      if (pwd[0] != '/')
	tmp->str = my_strcat(tmp->str, "/");
      tmp->str = my_strcat(tmp->str, pwd);
    }
  return (env);
}

t_env	*my_swap_old(t_env *env)
{
  t_env	*tmp;

  tmp = env->next;
  while (tmp != env && strncmp(tmp->str, "PWD=", 4) != 0)
    tmp = tmp->next;
  if (tmp == env)
    return (env);
  change_oldpwd(env, tmp->str + 4);
  return (env);
}
