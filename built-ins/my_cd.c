/*
** my_cd.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell1
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Dec 11 17:12:31 2013 lhomme
** Last update Sun May 11 17:59:27 2014 romaric
*/

#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include "my.h"

char    *find_arg(char *str)
{
  char	*arg;
  int	i;

  i = 2;
  arg = malloc(sizeof(*str) * strlen(str) + 1);
  if (str[0] == 'c' && str[1] == 'd')
    {
      if (str[2] == '\0')
	return (NULL);
      while (str[i] != '\0')
	{
	  arg[i - 2] = str[i];
	  i++;
	}
      return (arg);
    }
  return (NULL);
}

t_env		*my_cd_thereturn(t_env *env, t_env *tmp, char *arg)
{
  if (strcmp(arg, "..") == 1)
    {
      chdir("..");
      return (my_change_pwd(env, "..", 0));
    }
  while (strncmp(tmp->str, "HOME=", 5) != 0)
    tmp = tmp->next;
  chdir(tmp->str + 5);
  return (my_change_pwd(env, tmp->str + 5, 0));
}

t_env	*my_cd(t_env *env, char *str)
{
  t_env	*tmp;
  char          *arg;

  arg = find_arg(str);
  tmp = env->next;
  if (arg != NULL)
    {
      if (strcmp(arg, "-") == 0)
	return (my_oldpwd(env));
      if (opendir(arg) == NULL)
	{
	  printf("cd: %s: Not a directory\n", arg);
	  return (env);
	}
      else
	{
	  chdir(arg);
	  return (my_change_pwd(env, arg, 0));
	}
    }
  return (my_cd_thereturn(env, tmp, arg));
}
