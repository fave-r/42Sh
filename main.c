/*
** main.c for main in /home/alex-odet/work/42Sh
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr  3 14:01:18 2014 alex-odet
** Last update Thu Apr  3 14:19:31 2014 alex-odet
*/

#include "my.h"

extern char	**environ;

int	main(void)
{
  char	*tmp;

  display_prompt();
  while ((tmp = get_next_line(0)))
    lexer(tmp);
  return (0);
}

void	display_prompt()
{
  my_putstr("42Sh>", 1);
}
