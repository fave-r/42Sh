/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
** Last update Mon May 12 11:30:32 2014 lhomme
*/

#include "my.h"

void		my_show_list(t_token *list)
{
  while (list)
    {
      printf("token = %s\ttype = %d\n", list->token, list->type);
      list = list->next;
    }
}

int		main(int ac, char **av, char **envp)
{
  t_env		*history;
  t_token	*list;
  t_env         *env;
  char		*tmp;

  tmp = xmalloc(4096 * sizeof(char));
  if (ac > 1 || av[1] != NULL)
    return (0);
  history = NULL;
  list = NULL;
  env = my_env_inlist(envp);
  display_prompt();
  while ((xread(0, tmp, 4096)) > 0)
    {
      printf("tmp avant: %s\n", tmp);
      tmp = my_epur_str(tmp);
      printf("tmp apres: %s\n", tmp);
      if (tmp && tmp[0] != 0)
        {
          list = fill_list_token(tmp);
          //aff(npi(list), 0);
	  check_fn(npi(list), 0, 1);
          //  history = my_history(history, tmp);
	  bzero(tmp, 4096);
        }
	display_prompt();
    }
  return (0);
}

void		display_prompt()
{
  write(1, "$> ", 3);
}

t_token		*fill_list_token(char *str)
{
  t_token	*list;

  list = fill_token(str);
  fill_type(list);
  my_show_list(list);
  return (list);
}
