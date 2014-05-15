/*
** my_cd_func.c for my_cd in /home/lhomme_a/rendu/PSU_2013_minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Fri Mar 21 14:22:18 2014 lhomme
** Last update Thu May 15 19:18:33 2014 bourrel
*/

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"

void	change_oldpwd(t_env *env, char *pwd)
{
  t_env	*tmp;

  tmp = env->next;
  while (strncmp(tmp->str, "OLDPWD", 6) != 0)
    tmp = tmp->next;
  tmp->str[7] = 0;
  tmp->str = strcat(tmp->str, pwd);
}

t_env	*my_oldpwd(t_env *env)
{
  t_env	*oldpwd;
  t_env	*pwd;
  char	*str;
  char	*str2;

  oldpwd = env->next;
  pwd = env->next;
  while (strncmp(oldpwd->str, "OLDPWD", 6) != 0)
    oldpwd = oldpwd->next;
  chdir(oldpwd->str + 7);
  str = strdup(oldpwd->str + 6);
  while (strncmp(pwd->str, "PWD", 3) != 0)
    pwd = pwd->next;
  str2 = strdup(pwd->str + 3);
  oldpwd->str[6] = 0;
  pwd->str[3] = 0;
  oldpwd->str = strcat(oldpwd->str, str2);
  pwd->str = strcat(pwd->str, str);
  return (env);
}

char	*my_dup_pwd(char *pwd)
{
  char	*tmp;
  int	i;
  int	j;

  i = 2;
  j = 0;
  tmp = malloc(sizeof(char) * (strlen(pwd) - 1));
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
  while (strncmp(tmp->str, "PWD=", 4) != 0)
    tmp = tmp->next;
  change_oldpwd(env, tmp->str + 4);
  if ((strcmp(pwd, "..") == 0) || (strncmp(pwd, "..", 2) == 0))
    {
      while (tmp->str[i] != 0)
	i++;
      while (tmp->str[i] != '/')
	i--;
      tmp->str[i] = 0;
      if (pwd[2] != 0)
	my_change_pwd(tmp, my_dup_pwd(pwd), 0);
    }
  else
    {
      tmp->str[4] = '\0';
      tmp->str = strcat(tmp->str, pwd);
      printf("%s\n", tmp->str);
    }
  return (env);
}
