/*
** npi.c for npi in /home/lhomme_a/rendu/42Sh/npi
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Apr 23 16:24:59 2014 lhomme
** Last update Tue May 13 18:37:37 2014 
*/

#include "my.h"

t_token	*check_exotic(t_token *token)
{
  t_token	*tmp;
  char		**tab;
  int		i;

  tmp = NULL;
  while (token)
    {
      i = 0;
      if ((token->token[0] == '>' || token->token[0] == '<') && i == 0)
	{
	  tab = my_str_to_wordtab(token->next->token, ' ');
	  if (tab[1])
	    tmp = add_token(tmp, tab[1]);
	  while (token->next->token[i] && token->next->token[i] != ' ')
	    i++;
	  token->next->token[i] = 0;
	}
      tmp = add_token(tmp, token->token);
      token = token->next;
    }
  return (tmp);
}

void	my_stack(char *token, t_list **stack, t_list **output)
{
  if (token[0] == ';' || token[0] == '|'
      || token[0] == '>' || token[0] == '<' || token[0] == '&')
    {
      while (*stack != NULL && (my_priority(token, (*stack)->data) == 1))
	{
	  make_tree(output, (*stack)->data);
	  npi_delete_top(stack);
	}
      npi_add_top(stack, token, NULL);
    }
  else
    npi_add_top(output, token, NULL);
}

t_tree	*npi(t_token *token)
{
  t_list	*stack;
  t_list	*output;

  stack = NULL;
  output = NULL;
  if (!token)
    return (NULL);
  if (!token->next)
    return (createNode(NULL, token->token));
  token = check_exotic(token);
  while (token)
    {
      my_stack(token->token, &stack, &output);
      token = token->next;
    }
  while (stack)
    {
      make_tree(&output, stack->data);
      stack = stack->next;
    }
  return (output->tree);
}
