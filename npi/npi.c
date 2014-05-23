/*
** npi.c for npi in /home/lhomme_a/rendu/42Sh/npi
**
** Made by lhomme
** Login   <lhomme_a@epitech.net>
**
** Started on  Wed Apr 23 16:24:59 2014 lhomme
** Last update Fri May 23 15:37:33 2014 lhomme
*/

#include "my.h"

t_token	*exotic_and_var(t_token *token, t_env *env)
{
  token = check_exotic(token);
  token = check_varenv(token, env);
  return (token);
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

t_tree	*npi(t_token *token, char *str, t_env *env)
{
  t_npi		npi;

  npi.tree = NULL;
  npi.stack = NULL;
  npi.output = NULL;
  token = exotic_and_var(token, env);
  if (!token)
    return (NULL);
  if (!token->next)
    return (createNode(NULL, token->token));
  while (token)
    {
      my_stack(token->token, &npi.stack, &npi.output);
      token = token->next;
    }
  while (npi.stack)
    {
      make_tree(&npi.output, npi.stack->data);
      npi.stack = npi.stack->next;
    }
  npi.tree = npi.output->tree;
  npi_delete_list(&npi.stack);
  npi_delete_list(&npi.output);
  aff(npi.tree, 0);
  if (check_full_tree(npi.tree) == 1)
    return (npi.tree);
  fprintf(stderr, "'%s': syntax error\n", str);
  return (NULL);
}
