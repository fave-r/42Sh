/*
** my_echo.c for 42Sh in /home/leo/rendu/42Sh/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Thu Apr 24 14:30:23 2014 bourrel
** Last update Fri May 16 10:57:55 2014 
*/

#include "my.h"

t_env	*print_text(char **tab, t_env *env, int fd)
{
  int	i;

  i = 0;
  while (tab[++i])
    my_putstr(tab[i], fd);
  my_putstr("\n", fd);
  return (env);
}

t_env	*unknown_arg(char *text, char *arg, t_env *env, int i, int fd)
{
  while (arg[i] != '\0')
    {
      my_putstr(&arg[i], fd);
      i++;
    }
  my_putstr(" ", fd);
  my_putstr(text, fd);
  return (env);
}

t_env	*my_echo(t_env *env, char **tab, int fd)
{
  int	i;

  i = 0;
  if (tab[1] == NULL)
    return (env);
  if (tab[1][0] != '-')
    return (print_text(tab, env, fd));
  while (tab[1][i] != '\0')
    {
      if (tab[1][i + 1] == 'e')
	my_echo_arg(tab[2]);
      else if (tab[1][i + 1] == 'E')
	{
	  my_putstr(tab[2], fd);
	  my_putstr("\n", fd);
	}
      else if (tab[1][i + 1] == 'n')
	my_putstr(tab[2], fd);
      else
	return (unknown_arg(tab[2], tab[1], env, i, fd));
      i += 2;
    }
  return (env);
}
