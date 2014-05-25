/*
** check_varenv.c for npi in /home/lhomme_a/rendu/42Sh
**
** Made by lhomme
** Login   <lhomme_a@epitech.net>
**
** Started on  Thu May 22 15:02:29 2014 lhomme
** Last update Sun May 25 21:20:00 2014 romaric
*/

#include "my.h"

char		*check_dollar(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '$')
	return (str + i);
      i++;
    }
  return (NULL);
}

char		*is_in_env(char *var, t_env *env)
{
  int		i;
  t_env		*tmp;

  tmp = env->next;
  while (tmp != env)
    {
      i = 0;
      while (tmp->str[i] && tmp->str[i] != '=')
	i++;
      if (strncmp(var, tmp->str, i) == 0)
	{
	  var[i] = 0;
	  return (tmp->str + i + 1);
	}
      tmp = tmp->next;
    }
  return (NULL);
}

char		*swap_var_next(char *str, char *token, int i, int k)
{
  k += strlen(str);
  while (token[i])
    {
      str[k] = token[i];
      i++;
      k++;
    }
  str[k] = 0;
  free(token);
  return (str);
}

char		*swap_var(char *token, char *var, char *var_env)
{
  int		i;
  int		j;
  int		k;
  char		*str;

  i = 0;
  j = 0;
  k = 0;
  str = strdup(token);
  while (token[i] && token[i] != var[0])
    {
      i++;
      k++;
    }
  str[k] = 0;
  while (var[j] && token[i] && token[i] == var[j])
    {
      i++;
      j++;
    }
  str = my_strcat(str, var_env);
  return (swap_var_next(str, token, i, k));
}

t_token		*check_varenv(t_token *list, t_env *env)
{
  t_token	*tmp;
  char		*var;
  char		*var_env;

  tmp = list;
  while (tmp != NULL)
    {
      if ((var = check_dollar(tmp->token)) != NULL)
	{
	  if ((var_env = is_in_env(var + 1, env)) != NULL)
	    tmp->token = swap_var(tmp->token, var, var_env);
	  else
	    tmp->token = delete_varenv(tmp->token, var);
	}
      tmp = tmp->next;
    }
  return (list);
}
