/*
** my_setenv.c for mysh in /home/lhomme_a/rendu/minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Tue Feb 25 17:48:44 2014 lhomme
** Last update Thu Apr 17 15:40:43 2014 bourrel
*/

#include "../my.h"

t_env	*my_setenv(t_env *env, char **tab)
{
  if (tab[1] == NULL)
    printf("Error setenv: no argument\n");
  else
    {
      tab[1] = my_strcat(tab[1], "=");
      if (tab[2] != NULL)
	env = my_add_env(env, my_strcat(tab[1], tab[2]));
      else
	env = my_add_env(env, tab[1]);
    }
  return (env);
}