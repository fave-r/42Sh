/*
** main.c for main in /home/alex-odet/work/Tp_42
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Fri Mar  7 16:12:05 2014 alex-odet
** Last update Sun Apr  6 01:19:32 2014 alex-odet
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
       if ((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z') || (str[j] == ' ' && str[j + 1] == '-') || str[j] == '-')
	{
	  state = 1;
	  buffer[i] = str[j];
	  i = i + 1;
	}
      else
	{
	  if (state == 1)
	    tmp = str[j];
	  if (tmp == '|')
	    {
	      c = tmp;
	      tmp = -1;
	      list = my_put_in_list(list, strdup(buffer), 1);
	      bzero(buffer, strlen(str));
	      list = my_put_in_list(list, strdup("|"), 2);
	      i = 0;
	      state = 2;
	    }
	  else
	    tmp = -1;
	}
      j++;
    }
  list = my_put_in_list(list, strdup(buffer), 1);
  bzero(buffer, strlen(str));
  tmp = -1;
  state = 0;
  my_show_list(list);
  display_prompt();
  return (list);
}
