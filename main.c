/*
** main.c for main in /home/alex-odet/work/42Sh
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Mon Mar 10 14:34:57 2014 alex-odet
** Last update Sat Mar 15 12:51:54 2014 alex-odet
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
  printf("$>");
}
