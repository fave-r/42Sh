/*
** main.c for main in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Mon Mar 10 14:34:57 2014 alex-odet
** Last update Mon Mar 31 12:07:04 2014 romaric
*/

#include "struct.h"

extern char	**environ;

int	main(void)
{
  init_lexer();
  return (0);
}

void	display_prompt()
{
  my_putstr("\033[34m$42sh>\033[0;m", 1);
}
