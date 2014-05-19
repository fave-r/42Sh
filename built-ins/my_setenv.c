/*
** my_setenv.c for mysh in /home/lhomme_a/rendu/minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Tue Feb 25 17:48:44 2014 lhomme
** Last update Mon May 19 15:24:24 2014 
*/

#include "my.h"

t_env	*my_setenv(t_env *env, char **tab)
{
  char	*str;

  str = strdup(tab[1]);
  if (tab[1] == NULL)
    printf("Error setenv: no argument\n");
  else
    {
      str = strcat(str, "=");
      if (tab[2] != NULL)
	env = my_add_env(env, strcat(str, tab[2]));
      else
	env = my_add_env(env, str);
    }
  return (env);
}
