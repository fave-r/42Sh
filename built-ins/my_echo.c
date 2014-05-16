/*
** my_echo.c for 42Sh in /home/leo/rendu/42Sh/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Thu Apr 24 14:30:23 2014 bourrel
** Last update Fri May 16 11:30:08 2014 
*/

#include "my.h"

void	print_text(char **tab, int fd)
{
  int	i;

  i = 0;
  while (tab[++i])
    {
      my_putstr(tab[i], fd);
      my_putstr(" ", fd);
    }
  my_putstr("\n", fd);
}

void	unknown_arg(char *text, char *arg, int i, int fd)
{
  while (arg[i] != '\0')
    {
      my_putstr(&arg[i], fd);
      i++;
    }
  my_putstr(" ", fd);
  my_putstr(text, fd);
}

void	check_echo_args(char **tab, int fd)
{
  int	i;

  i = 0;
  while (tab[1][i] != '\0')
    {
      if (tab[2] && tab[1][i + 1] == 'e')
	my_echo_arg(tab[2]);
      else if (tab[2] && tab[1][i + 1] == 'E')
	{
	  my_putstr(tab[2], fd);
	  my_putstr("\n", fd);
	}
      else if (tab[2] && tab[1][i + 1] == 'n')
	my_putstr(tab[2], fd);
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
