/*
** check_exotic.c for npi in /home/lhomme_a/rendu/42Sh
**
** Made by lhomme
** Login   <lhomme_a@epitech.net>
**
** Started on  Thu May 22 14:55:03 2014 lhomme
** Last update Sun May 25 21:17:23 2014 romaric
*/

#include "my.h"

int		exotic(t_token **token, t_token **tmp)
{
  char		**tab;
  int		i;

  i = 0;
  tab = my_str_to_wordtab((*token)->next->token, ' ');
  if (tab[1])
    (*tmp) = add_token((*tmp), strdup(tab[1]));
  while ((*token)->next->token[i] && (*token)->next->token[i] != ' ')
    i++;
  (*token)->next->token[i] = 0;
  (*tmp) = add_token((*tmp), (*token)->token);
  (*token) = (*token)->next;
  free(tab);
  return (0);
}

t_token		*check_exotic(t_token *token)
{
  t_token	*tmp;

  tmp = NULL;
  if ((token->token[0] == '>' || token->token[0] == '<'))
    exotic(&token, &tmp);
  while (token)
    {
      if (token->next &&
	  (token->next->token[0] == '>' || token->next->token[0] == '<') &&
	  (token->token[0] == ';' || token->token[0] == '|'
	   || token->token[0] == '&'))
	{
	  tmp = add_token(tmp, token->token);
	  exotic(&token->next, &tmp);
	}
      else
	tmp = add_token(tmp, token->token);
      token = token->next;
    }
  delete_list(&token);
  return (tmp);
}
