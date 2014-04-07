/*
** main.c for main in /home/alex-odet/work/Tp_42
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Mar  7 16:12:05 2014 alex-odet
** Last update Mon Apr  7 18:54:09 2014 romaric
*/

#include "my.h"

void		my_show_list(t_token *list)
{
  while (list)
    {
      my_putstr("list->cmd = ", 1);
      if (list->buff == NULL)
      	my_putstr("NULL\n", 1);
      else
      	my_putstr(list->buff, 1);
      my_putstr("\n", 1);
      list = list->next;
    }
}

t_token		*state_one(t_token *list, char *buffer)
{
  list = my_put_in_list(list, strdup(buffer), 1);
  bzero(buffer, strlen(buffer));
  list = my_put_in_list(list, strdup("|"), 2);
  return (list);
}

t_token		*state_two(t_token *list, char *buffer)
{
  list = my_put_in_list(list, strdup(buffer), 1);
  bzero(buffer, strlen(buffer));
  list = my_put_in_list(list, strdup(">"), 3);
  return (list);
}

t_token		*state_three(t_token *list, char *buffer)
{
  list = my_put_in_list(list, strdup(buffer), 1);
  bzero(buffer, strlen(buffer));
  list = my_put_in_list(list, strdup(">>"), 4);
  return (list);
}

t_token		*state_four(t_token *list, char *buffer)
{
  list = my_put_in_list(list, strdup(buffer), 1);
  bzero(buffer, strlen(buffer));
  list = my_put_in_list(list, strdup("||"), 5);
  return (list);
}

t_token		*choose_state(char c, t_token *list, char *buffer, char *str)
{
  int	i;

  i = 0;
  while (str[i] != c)
    i++;
  if (c == '|' && str[i + 1] != c)
    list = state_one(list, buffer);
  else if (c == '|' && str[i + 1] == c)
    list = state_four(list, buffer);
  if (c == '>' && str[i + 1] != c)
    list = state_two(list, buffer);
  else if (c == '>' && str[i + 1] == c)
    list = state_three(list, buffer);
  return (list);
}

t_token		*lexer(char *str)
{
  int		j;
  t_token      	*list;
  int		i;
  static char	buffer[4096];
  i = 0;
  static int	state  = 0;

  list = NULL;
  j = 0;
  bzero(buffer, strlen(buffer));
  while (str[j] != '\n' && str[j])
    {
      if ((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z')
	  || (str[j] == ' ' && str[j + 1] == '-') || str[j] == '-'
	  || (str[j] == ' ' && ((str[j + 1] >= 'a' && str[j + 1] <= 'z')
				|| (str[j + 1 ] >= 'A' && str[j + 1] <= 'Z'))))
	{
	  state = 1;
	  buffer[i] = str[j];
	  i++;
	}
      else
	{
	  list = choose_state(str[j], list, buffer, str);
	  i = 0;
	  state = 0;
	}
      j++;
    }
  list = my_put_in_list(list, strdup(buffer), 1);
  bzero(buffer, strlen(buffer));
  state = 0;
  my_show_list(list);
  display_prompt();
  return (list);
}

