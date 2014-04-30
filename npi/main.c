/*
** main.c for NPI in /home/lhomme_a/rendu/42Sh
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Thu Mar 27 14:05:59 2014 lhomme
** Last update Tue Apr 29 15:50:29 2014 lhomme
*/

#include "npi.h"

int	main()
{
  t_list	*token;
  t_tree	*tree;
  
  token = NULL;
  tree = NULL;
  add_end(&token, "ls");
  add_end(&token, "|");
  add_end(&token, "cat");
  add_end(&token, ">");
  add_end(&token, "toto");
  /*  add_end(&token, "pwd");
  add_end(&token, ";");
  add_end(&token, "ls");
  add_end(&token, "|");
  add_end(&token, "cat");
  add_end(&token, "|");
  add_end(&token, "wc");*/
  tree = npi(token);
  printf("\nTree =\n");
  aff(tree, 0);
  return (0);
}
