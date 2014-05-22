/*
** my_setenv.c for mysh in /home/lhomme_a/rendu/minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Tue Feb 25 17:48:44 2014 lhomme
** Last update Thu May 22 19:20:04 2014 lhomme
*/

#include "my.h"

int	check_set_exist(t_env *env, char *str)
{
  t_env	*tmp;

  tmp = env->next;
  while (tmp != env)
    {
      if (strncmp(tmp->str, str, strlen(str)) == 0
	  && tmp->str[strlen(str)] == '=')
	return (1);
      tmp = tmp->next;
    }
  return (0);
}

t_env	*my_actualize(t_env *env, char **tab)
{
  t_env	*tmp;

  tmp = env->next;
  while (strncmp(tmp->str, tab[1], strlen(tab[1])) != 0
	 || tmp->str[strlen(tab[1])] != '=')
    tmp = tmp->next;
  tmp->str[strlen(tab[1]) + 1] = 0;
  if (tab[2])
    tmp->str = strcat(tmp->str, tab[2]);
  return (env);
}

t_env	*my_setenv(t_env *env, char **tab)
{
  char	*str;

  if (tab[1] == NULL)
    {
      printf("Error setenv: no argument\n");
      return (env);
    }
  if (check_set_exist(env, tab[1]) == 0)
    {
      str = strdup(tab[1]);
      str = strcat(str, "=");
      if (tab[2] != NULL)
	env = my_add_env(env, strcat(str, tab[2]));
      else
	env = my_add_env(env, str);
    }
  else
    env = my_actualize(env, tab);
  return (env);
}
