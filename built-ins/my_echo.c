/*
** my_echo.c for 42Sh in /home/leo/rendu/42Sh/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Thu Apr 24 14:30:23 2014 bourrel
** Last update Sun May 25 20:23:34 2014 bourrel
*/

#include "my.h"

void	print_echo_str(char *str, int fd)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] != 34 && str[i] != 39)
	my_putchar(str[i], fd);
      i++;
    }
}

void	print_text(char **tab, int fd)
{
  int	i;

  i = 0;
  while (tab[++i])
    {
      print_echo_str(tab[i], fd);
      my_putstr(" ", fd);
    }
}

int	check_echo_args(char **tab, int fd, int x, int i)
{
  if (check_invalid_arg(tab[1], tab[2], fd) == 0)
    return (x);
  if (tab[1][1] == '-')
    echo_vh(tab, fd);
  if (tab[1][1] == '\0' && tab[2])
    print_echo_str(tab[2], fd);
  while (tab[1][++i] != '\0')
    {
      if (tab[2] && tab[1][i] == 'e')
	my_echo_arg(tab[2], fd);
      else if (tab[2] && tab[1][i] == 'E')
	{
	  print_echo_str(tab[2], fd);
	  x = 1;
	}
      else if (tab[2] && strlen(tab[1]) == 2 && tab[1][i] == 'n')
	{
	  my_putstr(tab[2], fd);
	  x = 1;
	}
      else if (tab[1][i] == 'n')
	x = 1;
    }
  return (x);
}

void	my_echo(char **tab, int fd)
{
  int	x;
  int	i;

  i = 0;
  x = 0;
  if (tab[1] == NULL)
    x = 0;
  else if (tab[1][0] != '-')
    print_text(tab, fd);
  else
    x = check_echo_args(tab, fd, x, i);
  if (x == 0)
    my_putchar('\n', fd);
}
