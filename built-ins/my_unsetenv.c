/*
** my_unsetenv.c for mysh in /home/lhomme_a/rendu/minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Tue Feb 25 17:56:42 2014 lhomme
** Last update Wed Apr 30 18:18:20 2014 lhomme
*/

#include "../my.h"

char	*unset_arg(char *str, int nbr)
{
  char	*arg;
  int	i;
  int	j;

  i = nbr - 1;
  j = 0;
  arg = malloc(sizeof(*arg) * strlen(str));
  while (str[++i] != ' ')
    if (str[i] == '\0')
      return (NULL);
  i++;
  while (str[i] != '\0')
    {
      arg[j] = str[i];
      j++;
      i++;
    }
  arg[j] = '\0';
  return (arg);
}

void	my_delete_elem(t_env* elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}

t_env	*my_unsetenv(t_env *env, char *str)
{
  t_env	*tmp;
  char	*arg;

  if (strncmp(str, "unsetenv", 8))
    arg = unset_arg(str, 10);
  else
    arg = unset_arg(str, 0);
  tmp = env->next;
  if (arg == NULL)
    printf("Error: no argument\n");
  else
    {
      while (tmp != env && (strncmp(tmp->str, arg, strlen(arg)) != 0))
	tmp = tmp->next;
      if (tmp == env)
	printf("Error: %s does not exist in the environment\n", arg);
      else
	my_delete_elem(tmp);
    }
  return (env);
}
