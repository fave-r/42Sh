/*
** main.c for main in /home/alex-odet/work/42Sh
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Apr  4 11:05:16 2014 alex-odet
** Last update Fri Apr  4 11:06:02 2014 alex-odet
*/

#include "my.h"

extern char	**envrion;

int		main(void)
{
  char	*tmp;

  while ((tmp = get_next_line(0)))
    lexer(tmp);
}
