/*
** main.c for lexer in /home/thibaud/rendu/42sh
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Sat Apr 12 03:06:33 2014 thibaud
** Last update Sat Apr 12 06:23:42 2014 thibaud
*/

#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int     my_putstr(char *str)
{
  if (!str || str[0] == '\0')
    return (0);
  write(1, &str[0], 1);
  my_putstr(str + 1);
  return (0);
}

int		print_list(t_list *list)
{
  t_list	*cur;

  cur = list;
  if (list != NULL)
    while (cur != NULL)
      {
	printf("%s\t%d\n",cur->token, cur->type);
	cur = cur->next;
      }
  return (0);
}

t_list		*add_token(t_list *list, char *token)
{
  t_list	*new;
  t_list	*cur;

  cur = list;
  new = malloc(sizeof(t_list));
  new->token = token;
  new->type = 0;
  new->next = NULL;
  if (list == NULL)
    return (new);
  while (cur->next != NULL)
    cur = cur->next;
  cur->next = new;
  return (list);
}

char	*my_strxdup(char *source, int len)
{
  char	*copy;
  int	i;

  i = 0;
  copy = malloc(sizeof(char) * len + 1);
  while (i < len - 1)
    {
      copy[i] = source[i];
      i++;
    }
  copy[i] = '\0';
  return (copy);
}

int	get_operator(char *str, int i, int save[2])
{
  if (str[i] == str[i + 1])
    i += 2;
  else
    i++;
  save[1] = i;
  return (i);
}

int	get_other(char *str, int i, int save[2])
{
  while ((str[i] == '-' || (save[1] == save[0])) && str[i] != '\0')
    {
      while (str[i] != '\t' && str[i] != ' ' && str[i] != '\0'
	     && str[i] != '|' && str[i] != '&' && str[i] != '>' && str[i] != '<')
	i++;
      save[1] = i;
      while (((str[i] == '\t' || str[i] == ' ') && str[i] != '\0'))
	i++;
    }
  return (i);
}

t_list		*fill_token(char *str)
{
  int		i;
  int		save[2];
  t_list	*list;

  i = 0;
  list = NULL;
  while (str && str[i] != '\0')
    {
      while ((str[i] == '\t' || str[i] == ' ') && str[i] != '\0')
	i++;
      save[0] = i;
      save[1] = save[0];
      if (str[i] == '|' || str[i] == '&' || str[i] == '>' || str[i] == '<')
	{
	  i = get_operator(str, i, save);
	  list = add_token(list, my_strxdup(str + save[0], save[1] - save[0] + 1));
	}
      else if (str[i] != '\0')
	{
	  i = get_other(str, i, save);
      	  list = add_token(list, my_strxdup(str + save[0], save[1] - save[0] + 1));
	}
    }
  return (list);
}

int	fill_type(t_list *list)
{
  t_list	*cur;

  cur = list;
  if (list)
    {
      while (cur != NULL)
	{
	  if (cur->token[0] == '|' || cur->token[0] == '&' || cur->token[0] == '>' || cur->token[0] == '<')
	    cur->type = 1;
	  else
	    cur->type = 2;
	  cur = cur->next;
	}
    }
  return (0);
}

int		main()
{
  char		*str;
  t_list	*list;

  str = "     ls-l|cat  --help -r  ./hello >> world    ";
  list = fill_token(str);
  fill_type(list);
  print_list(list);
  my_putstr("This is Spartan\n");
  return (0);
}
