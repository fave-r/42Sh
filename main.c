/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
** Last update Tue May 20 17:13:47 2014 bourrel
*/

#include "my.h"

int	X;

void		my_show_list(t_token *list)
{
  while (list)
    {
      printf("token = %s\n", list->token);
      list = list->next;
    }
}

void		display_prompt()
{
  write(1, "$> ", 3);
}

void		display_sigint()
{
  write(1, "\n$> ", 4);
}

int		main(int ac, char **av, char **envp)
{
  t_token	*list;
  t_env         *env;
  t_tree	*tree;
  char		*tmp;

  tree = NULL;
  tmp = xmalloc(4096 * sizeof(char));
  if (ac > 1 || av[1] != NULL)
    return (0);
  list = NULL;
  env = my_env_inlist(envp);
  display_prompt();
  signal(SIGINT, &display_sigint);
  while ((xread(0, tmp, 4096)) > 0)
    {
      tmp = my_epur_str(tmp);
      if (tmp && tmp[0] != 0)
        {
          list = fill_token(tmp);
	  tree = npi(list);
	  X = check_fn(tree, 0, 1, &env);
	  if (X != 0)
	    return (X);
	  //return (check_fn(tree, 0, 1, &env) != 0);
	  bzero(tmp, 4096);
	  free_tree(tree);
	  delete_list(&list);
        }
      display_prompt();
    }
  write(1, "\n", 1);
  free(tmp);
  my_delete_envlist(&env);
  return (0);
}
