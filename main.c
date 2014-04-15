/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
** Last update Tue Apr 15 18:09:19 2014 alex-odet
*/

#include "my.h"

extern char	**environ;

int		main(void)
{
  t_token	*list;
  char		*tmp;

  display_prompt();
  while ((tmp = get_next_line(0)))
    list = fill_list_token(tmp);
  return (0);
}

void	display_prompt()
{
  my_putstr("$>", 1);
}

t_token		*fill_list_token(char *str)
{
  t_token	*list;

  list = fill_token(str);
  fill_type(list);
  display_prompt();
  return (list);
}
