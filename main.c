/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
** Last update Sun May 11 18:12:26 2014 romaric
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
  t_hist	*history;
  t_token	*list;
  t_env         *env;
  char		*tmp;

  if (ac > 1 || av[1] != NULL)
    return (0);
  history = NULL;
  list = NULL;
  env = my_env_inlist(envp);
  display_prompt();
  while ((tmp = get_next_line(0)))
    {
      tmp = my_epur_str(tmp);
      if (tmp && tmp[0] != 0)
        {
          list = fill_list_token(tmp);
          //aff(npi(list), 0);
	  check_fn(npi(list), 0, 1);
          //  history = my_history(history, tmp);
	  free(tmp);
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
