/*
** main.c for main in /home/alex-odet/work/Tp_42
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Mar  7 16:12:05 2014 alex-odet
** Last update Mon Mar 17 10:47:56 2014 alex-odet
*/

#include "struct.h"


int	init_lexer()
{
  char	*tmp;

  display_prompt();
  while ((tmp = lexer()) != NULL)
    {
      my_putstr(tmp, 1);
      display_prompt();
    }
  return (0);
}

char	*lexer()
{
  int		i;
  char		c;
  static char	buffer[BUFF_SIZE];
  static int	state  = 0;
  static	char	tmp = -1;
  
  i = 0;
  bzero(buffer, BUFF_SIZE);
  while ((c = get_char(0)) != '\n')
    {
      if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
	  state = 1;
	  buffer[i] = c;
	  i = i + 1;
	}
      else if (((c <= 'A' || c >= 'Z') || (c <= 'a' || c >= 'z')) && (state == 1))
	return (buffer);
    }
  tmp = -1;
  state = 0;
  return (buffer);
}
