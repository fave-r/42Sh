/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
** Last update Tue Apr 15 17:20:38 2014 alex-odet
*/

#include "my.h"

extern char	**environ;

int		main(void)
{
  char		*tmp;

  display_prompt();
  while ((tmp = get_next_line(0)))
    fill_list_token(tmp);
}

void	display_prompt()
{
  my_putstr("$>", 1);
}
