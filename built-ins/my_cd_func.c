/*
** my_cd_func.c for my_cd in /home/lhomme_a/rendu/PSU_2013_minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Fri Mar 21 14:22:18 2014 lhomme
** Last update Wed Apr 23 14:28:55 2014 bourrel
*/

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "../my.h"

void	change_oldpwd(t_env *env, char *pwd)
{
  t_env	*tmp;

  tmp = env->next;
  while (my_strncmp(tmp->str, "OLDPWD", 6) != 0)
    tmp = tmp->next;
  tmp->str[7] = 0;
  tmp->str = my_strcat(tmp->str, pwd);
}

t_env	*my_oldpwd(t_env *env)
{
  t_env	*oldpwd;
  t_env	*pwd;
  char	*str;
  char	*str2;

  oldpwd = env->next;
  pwd = env->next;
  while (my_strncmp(oldpwd->str, "OLDPWD", 6) != 0)
    oldpwd = oldpwd->next;
  chdir(oldpwd->str + 7);
  str = my_strdup(oldpwd->str + 6);
  while (my_strncmp(pwd->str, "PWD", 3) != 0)
    pwd = pwd->next;
  str2 = my_strdup(pwd->str + 3);
  oldpwd->str[6] = 0;
  pwd->str[3] = 0;
  oldpwd->str = my_strcat(oldpwd->str, str2);
  pwd->str = my_strcat(pwd->str, str);
  return (env);
}

char	*my_dup_pwd(char *pwd)
{
  char	*tmp;
  int	i;
  int	j;

  i = 2;
  j = 0;
  tmp = malloc(sizeof(char) * (my_strlen(pwd) - 1));
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
  while (my_strncmp(tmp->str, "PWD=", 4) != 0)
    tmp = tmp->next;
  change_oldpwd(env, tmp->str + 4);
  if ((my_strcmp(pwd, "..") == 0) || (my_strncmp(pwd, "..", 2) == 0))
    {
      while (tmp->str[i] != 0)
	i++;
      while (tmp->str[i] != '/')
	i--;
      tmp->str[i] = 0;
      if (pwd[2] != 0)
	my_change_pwd(tmp, my_dup_pwd(pwd), 0);
    }
  else if (pwd[0] == '/')
    tmp->str = my_strcat("PWD=", pwd);
  else
    {
      tmp->str = my_strcat(tmp->str, "/");
      tmp->str = my_strcat(tmp->str, pwd);
    }
  return (env);
}
