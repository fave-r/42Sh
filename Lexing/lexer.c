/*
** main.c for main in /home/alex-odet/work/Tp_42
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Mar  7 16:12:05 2014 alex-odet
** Last update Thu Apr  3 14:43:40 2014 alex-odet
*/

#include "my.h"

void	my_show_list(t_token *list)
{
  while (list)
    {
      my_putstr("list->cmd = ", 1);
      my_putstr(list->buff, 1);
      my_putstr("\n", 1);
      list = list->next;
    }
}

t_token		*lexer(char *str)
{
  int		j;
  t_token      	*list;
  int		i;
  static char	buffer[4096];
  char		c;
  static char	tmp = -1;
  i = 0;
  static int	state  = 0;

  list = NULL;
  j = 0;
  bzero(buffer, strlen(str));
  while (str[j] != '\n' && str[j])
    {
      while ((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z'))
	{
	  state = 1;
	  buffer[i] = str[j];
	  i = i + 1;
	  j++;
	}
      if (state == 1)
	{
	  tmp = str[j];
	  if (tmp == '|')
	    c = tmp;
	  else
	    tmp = -1;
	  list = my_put_in_list(list, buffer, 1);
	}
      j++;
    }
  tmp = -1;
  state = 0;
  my_show_list(list);
  return (list);
}
