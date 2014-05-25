/*
** my_unsetenv.c for mysh in /home/lhomme_a/rendu/minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Tue Feb 25 17:56:42 2014 lhomme
** Last update Sat May 24 19:52:54 2014 lhomme
*/

#include "my.h"

void	my_delete_elem(t_env* elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}

void	my_delete_pwd(t_env *env)
{
  t_env	*tmp;
  t_env	*tmp2;

  tmp = env->next;
  tmp2 = env->next;
  while (tmp != env && strncmp(tmp->str, "PWD", 3) != 0)
    tmp = tmp->next;
  while (tmp2 != env && strncmp(tmp2->str, "OLDPWD", 6) != 0)
    tmp2 = tmp2->next;
  if (tmp != env && tmp->str[3] == '=')
    my_delete_elem(tmp);
  if (tmp2 != env && tmp2->str[6] == '=')
    my_delete_elem(tmp2);
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
	    {
	      if (tab[1] && strcmp(tab[1], "PWD") == 0)
		my_delete_pwd(env);
	      else
		my_delete_elem(tmp);
	    }
	  else
	    printf("Error: %s does not exist in the environment\n", tab[1]);
	}
    }
  return (env);
}

