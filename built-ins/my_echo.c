/*
** my_echo.c for 42Sh in /home/leo/rendu/42Sh/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Thu Apr 24 14:30:23 2014 bourrel
** Last update Fri May 16 12:49:47 2014 
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
  my_putstr("\n", fd);
}

void	unknown_arg(char *text, char *arg, int i, int fd)
{
  while (arg[i] != '\0')
    {
      print_echo_str(&arg[i], fd);
      i++;
    }
  my_putstr(" ", fd);
  print_echo_str(text, fd);
}

void	check_echo_args(char **tab, int fd)
{
  int	i;

  i = 0;
  while (tab[1][i] != '\0')
    {
      if (tab[2] && tab[1][i + 1] == 'e')
	my_echo_arg(tab[2], fd);
      else if (tab[2] && tab[1][i + 1] == 'E')
	{
	  print_echo_str(tab[2], fd);
	  my_putstr("\n", fd);
	}
      else if (tab[2] && tab[1][i + 1] == 'n')
	  print_echo_str(tab[2], fd);
      else if (tab[2])
	unknown_arg(tab[2], tab[1], i, fd);
      else if (tab[1][i + 1] != 'n')
	my_putstr("\n", fd);
      i += 2;
    }
}

void	my_echo(char **tab, int fd)
{
  int	i;

  i = 0;
  if (tab[1] == NULL)
    my_putstr("\n", fd);
  else if (tab[1][0] != '-')
    print_text(tab, fd);
  else
    check_echo_args(tab, fd);
}
