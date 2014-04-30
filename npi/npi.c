/*
** npi.c for npi in /home/lhomme_a/rendu/42Sh/npi
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Wed Apr 23 16:24:59 2014 lhomme
** Last update Wed Apr 30 15:05:27 2014 lhomme
*/

#include "npi.h"

void	my_stack(char *token, t_list **stack, t_list **output)
{
  if (token[0] == ';' || token[0] == '|'
      || token[0] == '>' || token[0] == '<' || token[0] == '&')
    {
      while (*stack != NULL && (my_priority(token, (*stack)->data) == 1))
	{
	  make_tree(output, (*stack)->data);
	  delete_top(stack);
	}
      add_top(stack, token, NULL);
    }
  else
    add_top(output, token, NULL);
}

t_tree	*npi(t_list *token)
{
  t_list	*stack;
  t_list	*output;

  stack = NULL;
  output = NULL;
  if (!token)
    return (NULL);
  while (token)
    {
      my_stack(token->data, &stack, &output);
      token = token->next;
    }
  while (stack)
    {
      make_tree(&output, stack->data);
      stack = stack->next;
    }
  return (output->tree);
}
