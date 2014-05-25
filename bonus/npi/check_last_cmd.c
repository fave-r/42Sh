/*
** check_last_cmd.c for npi in /home/lhomme_a/rendu/42Sh/bonus
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Sun May 25 17:17:15 2014 lhomme
** Last update Sun May 25 18:14:58 2014 lhomme
*/

#include "my.h"

int	check_exclam(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '!')
	return (1);
      i++;
    }
  return (0);
}

char	*replace_hist(char *str, char *tmp, t_env *history, int i)
{
  printf("%s\n", str);
  if (!str[i + 1])
    return (NULL);
  if (str[i + 1] == ' ' || str[i + 1] == '\t')
    return (my_strcat(tmp, str + i + 1));
}

char	*replace_history(char *str, t_env *history)
{
  char	*tmp;
  int	i;
  int	j;

  i = 0;
  j = 0;
  tmp = strdup(str);
  tmp = NULL;
  while (str[i])
    {
      if (str[i] == '!')
	{
	  i++;
	  if (!str[i])
	    tmp[j] = 0;
	  else if (str[i] == '!')
	    {
	      tmp = my_strcat(tmp, history->prev->prev->str);
	      j = j + strlen(history->prev->prev->str);
	      i++;
	      if (str[i] && str[i] == '!'
		  && (!str[i + 1] || str[i + 1] == ' ' || str[i + 1] == '\t'))
		{
		  tmp[j] = str[i];
		  i++;
		}
	    }
	}
      else
	j++;
      if (str[i])
	{
	  tmp[j] = str[i];
	  i++;
	}
    }
  if (tmp[j])
    tmp[j] = 0;
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
