/*
** my_echo.c for 42Sh in /home/leo/rendu/42Sh/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Thu Apr 24 14:30:23 2014 bourrel
** Last update Sun May 11 18:00:00 2014 romaric
*/

#include "my.h"

char	*is_text(char *str)
{
  char	*text;
  int	i;
  int	j;
  int	arg;

  j = 0;
  i = 5;
  arg = 0;
  if (!str)
    return (NULL);
  text = malloc(sizeof(*text) * strlen(str) + 1);
  while (str[i] != '\0')
    {
      if (str[i] == '-' && arg == 0)
	i += 2;
      else
	{
	  text[j] = str[i];
	  arg = 1;
	  j++;
	}
      i++;
    }
  text[i] = '\0';
  return (text);
}

char    *find_echo_arg(char *str)
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
  if (str[i] == '\0' || str[++i] != '-')
    return (NULL);
  while (str[i] == '-')
    {
      arg[j] = str[i];
      arg[++j] = str[++i];
      j++;
      i += 2;
    }
  arg[j] = '\0';
  return (arg);
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

t_env	*my_echo(t_env *env, char *str)
{
  char	*arg;
  char	*text;
  int	i;

  i = 0;
  arg = find_echo_arg(str);
  text = is_text(str);
  if (arg == NULL)
    return (env);
  while (arg[i] != '\0')
    {
      if (arg[i + 1] == 'e')
	my_echo_arg(text);
      else if (arg[i + 1] == 'E')
        printf("%s\n", text);
      else if (arg[i + 1] == 'n')
	printf("%s", text);
      else
	return (unknown_arg(text, arg, env, i));
      i += 2;
    }
  free (arg);
  free (text);
  return (env);
}
