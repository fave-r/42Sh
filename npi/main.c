/*
** main.c for NPI in /home/lhomme_a/rendu/42Sh
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Thu Mar 27 14:05:59 2014 lhomme
** Last update Mon Apr  7 18:48:14 2014 lhomme
*/

#include "npi.h"

void	aff(t_tree *tree, int size)
{
  int	 i;

  i = 0;
  while (i < size)
    {
      printf("|___");
      i++;
    }
  printf("[%s]\n", tree->data);
  if (tree->left)
    aff(tree->left, size + 1);
  if (tree->right)
    aff(tree->right, size + 1);
}
/*
void	addNode(t_tree **tree, void *a, void *b)
{
  t_tree	*tmpNode;
  t_tree	*tmpTree;
  t_tree	*elema;
  t_tree	*elemb;

  tmpTree = *tree;
  elema = malloc(sizeof(t_tree));
  elema->data = a;
  elema->left = NULL;
  elema->right = NULL;
  elemb = malloc(sizeof(t_tree));
  elemb->data = b;
  elemb->left = NULL;
  elemb->right = NULL;
  while (tmpTree)
    {
      tmpNode = tmpTree;
      tmpTree = tmpTree->right;
      if(!tmpTree)
	tmpNode->right = elemb;
      tmpTree = tmpNode;
      tmpTree = tmpTree->left;
      if(!tmpTree)
	tmpNode->left = elema;
    }
}

int	my_priority(char *d1, char *d2)
{
  if (d1[0] == ';')
    return (1);
  if ((d1[0] == '&' || d1[1] == '|') && d2[0] != ';')
    return (1);
  if ((d1[0] == '<' || d1[0] == '>') && d2[0] == '|' && d2[1] == 0)
    return (1);
  return (0);
}

int	op_token(t_list *stack, t_list *output)
{
  char		*o;
  void		*a;
  void		*b;
  t_tree	*t;

  t = NULL;
  o = strdup(stack->data);
  stack = delete_top(stack);
  a = strdup(output->data);
  output = delete_top(output);
  b = strdup(output->data);
  output = delete_top(output);
  printf("o = %s\na = %s\nb = %s\n", o, a, b);
  t = malloc(sizeof(t_tree));
  t->data = strdup(o);
  addNode(&t, a, b);
  t = malloc(sizeof(t_tree));
  t->data = strdup(o);
  t->left->data = strdup(a);
  t->right->data = strdup(b);
  printf("tree =\n");
  aff(t, 0);
  output = add_top(output, t);
  printf("stack =\n");
  print_list(stack);
  free(o);
  free(a);
  free(b);
  return (0);
}

void	*npi(t_list *token, t_list *stack, t_list *output)
{
  char	*o1;

  while (token != NULL)
    {
      printf("token =\n");
      print_list(token);
      printf("\n\n");
      printf("stack =\n");
      print_list(stack);
      printf("\n\n");
      printf("output =\n");
      print_list(output);
      printf("\n\n");
      if (token->data[0] == ';' || token->data[0] == '|'
	  || token->data[0] == '>' || token->data[0] == '<' || token->data[0] == '&')
	{
	  o1 = strdup(token->data);
	  printf("op\n\n");
	  while (stack != NULL)
	    {
	      if (my_priority(o1, stack->data) == 1)
		{
		  printf("priority\n");
		  op_token(stack, output);
		}
	    }
	  stack = add_top(stack, o1);
	}
      else
	output = add_top(output, token->data);
      token = token->next;
    }
  printf("ok\n");
  while (stack != NULL)
    op_token(stack, output);
  return (output->data);
  }*/

int	main(int ac, char **av)
{
  t_list	*token;
  t_list	*stack;
  t_list	*output;
  t_tree	*t;
  int		i;

  i = 1;
  token = NULL;
  stack = NULL;
  output = NULL;
  t = NULL;
  while (av[i] != NULL)
    {
      token = add_end(token, av[i]);
      i++;
    }
  print
  t = npi(token, stack, output);
  printf("\n\n\nTree =\n");
  aff(t, 0);
  return (0);
}
