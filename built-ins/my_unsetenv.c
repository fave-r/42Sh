/*
** my_unsetenv.c for mysh in /home/lhomme_a/rendu/minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Tue Feb 25 17:56:42 2014 lhomme
** Last update Mon May 19 14:40:58 2014 
*/

#include "my.h"

void	my_delete_elem(t_env* elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}

t_env	*my_unsetenv(t_env *env, char **tab)
{
  t_env	*tmp;

  tmp = env->next;
  if (!tab[1])
    printf("Error: no argument\n");
  else
    {
      while (tmp != env && (strncmp(tmp->str, tab[1], strlen(tab[1])) != 0))
	tmp = tmp->next;
      if (tmp == env)
	printf("Error: %s does not exist in the environment\n", tab[1]);
      else
	{
	  if (tmp->str[strlen(tab[1])] == '=')
	    my_delete_elem(tmp);
	  else
	    printf("Error: %s does not exist in the environment\n", tab[1]);
	}
    }
  return (env);
}

