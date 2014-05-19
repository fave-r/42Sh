/*
** main.c for test in /home/thibaud/rendu/test
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Mon Mar 31 15:38:57 2014 thibaud
** Last update Mon May 19 14:53:53 2014 
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

t_arbre		*make_root(void)
{
  t_arbre	*root;

  if ((root = malloc(sizeof(t_arbre))) == NULL)
    {
      my_putstr("Malloc error\n");
      exit(-1);
    }
  root->next = NULL;
  root->deep = NULL;
  root->c = '\0';
  return (root);
}

t_arbre		*add_char(char c)
{
  t_arbre	*new;

  if ((new = malloc(sizeof(t_arbre))) == NULL)
    {
      my_putstr("Malloc error\n");
      exit(-1);
    }
  new->c = c;
  new->next = NULL;
  new->deep = NULL;
  return (new);
}

t_arbre		*creat_word(char *str)
{
  t_arbre	*new;
  t_arbre	*cur;
  int		i;

  i = 1;
  new = add_char(str[0]);
  cur = new;
  while (str[i])
    {
      cur->deep = add_char(str[i]);
      cur = cur->deep;
      i++;
    }
  if (i != 0)
    cur->deep = add_char(' ');
  else
    cur->next = add_char(' ');
  return (new);
}

int		add_word(t_arbre *arbre, char *str)
{
  int		i;
  t_arbre	*cur;

  i = 0;
  cur = arbre;
  while (str && i <= my_strlen(str))
      {
	if (cur->c != str[i] && !cur->next)
	  {
	    cur->next = creat_word(str + i);
	    return (0);
	  }
	else if (cur->c == str[i])
	    cur = cur->deep;
	else
	  {
	    cur = cur->next;
	    i--;
	  }
	i++;
      }
  return (-1);
}

int		print_arbre(t_arbre *arbre)
{
  if (arbre == NULL || arbre->c == ' ')
    {
      if (arbre && arbre->c == ' ')
	my_putchar('\n');
      return (0);
    }
  if (arbre->deep)
    {
      my_putchar(arbre->c);
      print_arbre(arbre->deep);
    }
  print_arbre(arbre->next);
  return (0);
}

int		go_to(t_arbre *arbre, char *str, t_arbre **ret)
{
  t_arbre	*cur;
  t_arbre	*save;
  int		i;

  i = 0;
  cur = arbre;
  while (str[i] && cur && i < my_strlen(str))
    {
      save = cur;
      if (str[i] == cur->c)
	cur = cur->deep;
      else
	{
	  cur = cur->next;
	  i--;
	}
      i++;
    }
  ret[0] = save;
  return (i);
}

int	calc_len(t_arbre *cur)
{
  int	i;

  i = 0;
  cur = cur->deep;
  while (cur->c != ' ' && cur->next == NULL)
    {
      cur = cur->deep;
      i++;
    }
  return (i);
}

char		*auto_completion(t_arbre *arbre, char *str)
{
  char		*result;
  t_arbre	*cur;
  int		i;
  int		len;

  if (!str || str[0] == '\0')
    return (NULL);
  cur = arbre->deep;
  i = go_to(arbre, str, &cur);
  if (i == 0 || i != my_strlen(str))
    return (NULL);
  len = calc_len(cur);
  if ((result = malloc(sizeof (char) * len + 1)) == NULL)
      exit(-1);
  result[len] = '\0';
  i = 0;
  cur = cur->deep;
  while (i < len)
    {
      result[i] = cur->c;
      cur = cur->deep;
      i++;
    }
  return (result);
}

int		main(void)
{
  t_arbre	*arbre;
  char		*result;
  char		*test;

  arbre = make_root();
  add_word(arbre, "Pomme");
  add_word(arbre, "Hello");
  add_word(arbre, "Hella");
  add_word(arbre, "Hell");
  add_word(arbre, "Hell");
  add_word(arbre, "Kurdistan");
  add_word(arbre, "Nikoumouk");
  // print_arbre(arbre);

  test = "K";
  result = auto_completion(arbre, test);

  if (result == NULL)
    my_putstr("Pas d'auto-completion possible\n");
  else
    {
      my_putstr("Auto_completion :");
      my_putstr(result);
      my_putstr("\n");
    }
  return (0);
}
