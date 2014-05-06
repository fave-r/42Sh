/*
** my_echo.c for 42Sh in /home/leo/rendu/42Sh/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Thu Apr 24 14:30:23 2014 bourrel
** Last update Wed Apr 30 18:16:14 2014 lhomme
*/

#include "../my.h"

char    *echo_arg(char *str)
{
  char  *arg;
  int   i;
  int   j;

  if (!str)
    return (NULL);
  i = 0;
  j = 0;
  arg = malloc(sizeof(*arg) * strlen(str));
  while (i < 4)
    i++;
  if (str[i] == '\0')
    return (NULL);
  i++;
  while (str[i] != '\0')
    {
      arg[j] = str[i];
      j++;
      i++;
    }
  arg[j] = '\0';
  return (arg);
}

t_env	*my_echo(t_env *env, char *str)
{
  char	*arg;

  arg = echo_arg(str);
  printf("%s\n|%s|\n", str, arg);
  return (env);
}
