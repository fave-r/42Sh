/*
** npi.c for npi in /home/lhomme_a/rendu/42Sh/npi
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Apr 23 16:24:59 2014 lhomme
** Last update Tue May  6 18:00:47 2014 lhomme
*/

#include "../my.h"
#include "npi.h"

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
