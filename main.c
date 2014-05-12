/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
<<<<<<< HEAD
** Last update Mon May 12 16:50:42 2014 romaric
=======
** Last update Mon May 12 14:52:34 2014 lhomme
>>>>>>> c2346d5f2f1c4249414822963af76110705c8c65
*/

#include "my.h"

void		my_show_list(t_token *list)
{
  while (list)
    {
      printf("token = %s\n", list->token);
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
      tmp = my_epur_str(tmp);
      if (tmp && tmp[0] != 0)
        {
          list = fill_list_token(tmp);
          aff(npi(list), 0);
	  check_fn(npi(list), 0, 1);
          //  history = my_history(history, tmp);
	  bzero(tmp, 4096);
        }
	display_prompt();
    }
  write(1, "\n", 1);
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
  my_show_list(list);
  return (list);
}
