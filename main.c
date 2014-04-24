/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
** Last update Thu Apr 24 16:15:12 2014 bourrel
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
  t_token	*list;
  t_env         *env;
  char		*tmp;

  env = my_env_inlist(envp);
  display_prompt();
  while ((tmp = get_next_line(0)))
    {
      list = fill_list_token(tmp);
      /*      if (my_strncmp(tmp, "cd", my_strlen("cd")) == 0)
	env = my_cd(env, tmp);
      else if (tmp[0] == 's')
	env = my_env(env, tmp);
      else if (tmp[0] == 'u')
	env = my_unsetenv(env, tmp);
      else if (tmp[0] == 'e')
        env = my_echo(env, tmp);
      */display_prompt();
    }
  return (0);
}

void		display_prompt()
{
  my_putstr("$>", 1);
}

t_token		*fill_list_token(char *str)
{
  t_token	*list;

  list = fill_token(str);
  fill_type(list);
  my_show_list(list);
  return (list);
}
