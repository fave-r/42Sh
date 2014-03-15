/*
** main.c for main in /home/alex-odet/work/Tp_42
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Mar  7 16:12:05 2014 alex-odet
** Last update Sat Mar 15 12:01:23 2014 alex-odet
*/

#include "struct.h"


int	init_lexer()
{
  char	*tmp;

  display_prompt();
  while ((tmp = lexer()))
    {
      printf("%s\n", tmp);
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
  bzero(buffer, 4096);
  while ((c = getchar()) != '\n')
    {
      if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) && c != '|')
	{
	  state = 1;
	  buffer[i] = c;
	  i = i + 1;
	}
      else if ((c <= 'A' || c >= 'Z') || (c <= 'a' || c >= 'z')
	       && (state == 1 && tmp != '|'))
	return (buffer);
    }
  tmp = -1;
  state = 0;
  return (buffer);
}
