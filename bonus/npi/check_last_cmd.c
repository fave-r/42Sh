/*
** check_last_cmd.c for npi in /home/lhomme_a/rendu/42Sh/bonus
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Sun May 25 17:17:15 2014 lhomme
** Last update Sun May 25 17:33:23 2014 lhomme
*/

#include "my.h"

int	check_exclam(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '!' && str[i + 1] != ' ' && str[i + 1] != '\t'
	  && str[i + 1] != 0)
	return (1);
      i++;
    }
  return (0);
}

char	*replace_history(char *str, t_env *history)
{
  char	*tmp;
  int	i;

  i = 0;
  tmp = strdup(str);
  while (str[i] && str[i] != '!')
    i++;
  tmp[i] = 0;
  if (str[i + 1] && str[i + 1] == '!')
    {
      tmp = my_strcat(tmp, history->prev->str);
      i += 2;
    }
  else
    while (str[i] && str[i] != ' ' && str[i] != '\t')
      i++;
  free(str);
  return (tmp);
}

t_token	*check_last_cmd(t_token *list, t_env *history)
{
  t_token	*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      if (check_exclam(tmp->token) == 1)
	tmp->token = replace_history(tmp->token, history);
      tmp = tmp->next;
    }
  return (list);
}
