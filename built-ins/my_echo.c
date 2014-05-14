/*
** my_echo.c for 42Sh in /home/leo/rendu/42Sh/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Thu Apr 24 14:30:23 2014 bourrel
** Last update Wed May 14 19:25:18 2014 bourrel
*/

#include "my.h"

t_env	*print_text(char **tab, t_env *env)
{
  int	i;

  i = 0;
  while (tab[++i])
    printf("%s ", tab[i]);
  printf("\n");
  return (env);
}

t_env	*unknown_arg(char *text, char *arg, t_env *env, int i)
{
  while (arg[i] != '\0')
    {
      printf("%c", arg[i]);
      i++;
    }
  printf(" %s\n", text);
  return (env);
}

t_env	*my_echo(t_env *env, char **tab)
{
  int	i;

  i = 0;
  if (tab[1] == NULL)
    return (env);
  if (tab[1][0] != '-')
    return (print_text(tab, env));
  while (tab[1][i] != '\0')
    {
      if (tab[1][i + 1] == 'e')
	my_echo_arg(tab[2]);
      else if (tab[1][i + 1] == 'E')
        printf("%s\n", tab[2]);
      else if (tab[1][i + 1] == 'n')
	printf("%s", tab[2]);
      else
	return (unknown_arg(tab[2], tab[1], env, i));
      i += 2;
    }
  return (env);
}
