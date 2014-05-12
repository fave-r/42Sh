/*
** my_cd.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell1
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Dec 11 17:12:31 2013 lhomme
** Last update Fri May  9 15:19:54 2014 lhomme
*/

#include "../my.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

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

t_env	*my_cd_thereturn(t_env *env, t_env *tmp, char *arg)
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

int	my_cd(t_env *env, char *str)
{
  t_env		*tmp;
  char          *arg;

  arg = find_arg(str);
  arg = my_epur_str(arg);
  tmp = env->next;
  if (arg != NULL)
    {
      if (strcmp(arg, "-") == 0)
	{
	  env = my_oldpwd(env);
	  return (0);
	}
      if (opendir(arg) == NULL)
	{
	  printf("cd: %s: Not a directory\n", arg);
	  return (-1);
	}
      chdir(arg);
      env = my_change_pwd(env, arg, 0);
      return (0);
    }
  env = my_cd_thereturn(env, tmp, arg);
  return (0);
}
