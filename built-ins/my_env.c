/*
** my_env.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell1
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Fri Dec 13 13:03:54 2013 lhomme
** Last update Sun May 11 18:00:50 2014 romaric
*/

#include "my.h"

void	my_env_vh(char *str)
{
  if (strcmp(str, "--version") == 0)
    {
      printf("env (GNU coreutils) 8.17\nCopyright (C) 2012 Free Software ");
      printf("Foundation, Inc.\nLicense GPLv3+: GNU GPL version 3 or late");
      printf("r <http://gnu.org/licenses/gpl.html>.\nThis is free softwar");
      printf("e: you are free to change and redistribute it.\nThere is NO");
      printf("WARRANTY, to the extent permitted by law.\n\n");
      printf("Written by Richard Mlynarik and David MacKenzie.\n");
    }
  else if (strcmp(str, "--help") == 0)
    {
      printf("Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]..");
      printf(".]\nSet each NAME to VALUE in the environment and run COMMA");
      printf("ND.\n\n  -i, --ignore-environment  start with an empty envi");
      printf("ronment\n  -0, --null           end each output line with 0");
      printf(" byte rather than newline\n  -u, --unset=NAME     remove va");
      printf("riable from the environment\n      --help     display this ");
      printf("help and exit\n      --version  output version information ");
      printf("and exit\n\nA mere - implies -i.  If no COMMAND, print the ");
      printf("resulting environment.\n\nReport env bugs to bug-coreutils@");
      printf("gnu.org\nGNU coreutils home page: <http://www.gnu.org/softw");
      printf("are/coreutils/>\nGeneral help using GNU software: <http://w");
      printf("ww.gnu.org/gethelp/>\nFor complete documentation, run:");
      printf(" info coreutils 'env invocation'\n");
    }
}

void	my_env_null(t_env *env)
{
  t_env	*tmp;

  tmp = env->next;
  while (tmp != env)
    {
      printf("%s", tmp->str);
      tmp = tmp->next;
    }
  printf("\n");
}

t_env	*my_env_i(t_env *env)
{
  env->next = env;
  return (env);
}

char	*env_arg(char *str)
{
  char	*arg;
  int	i;
  int	j;

  if (!str)
    return (NULL);
  i = 0;
  j = 0;
  arg = malloc(sizeof(*arg) * strlen(str));
  while (i < 6)
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

t_env	*my_env(t_env *env, char *str)
{
  char	*arg;

  arg = env_arg(str);
  if (strlen(str) == 6)
    my_print_envlist(env);
  else if ((strcmp(arg, "-0") == 1)
	   || (strcmp(arg, "--null") == 1))
    my_env_null(env);
  else if ((strcmp(arg, "--version") == 1)
	   || (strcmp(arg, "--help") == 1))
    my_env_vh(str);
  else if ((strcmp(arg, "-i") == 1)
	   || (strcmp(arg, "--ignore-environment") == 1))
    env = my_env_i(env);
  else if ((strncmp(arg, "-u", 2) == 0)
	   || (strcmp(arg, "--unset") == 1))
    env = my_unsetenv(env, arg);
  else
    printf("env: invalid option: %s\n", str);
  return (env);
}
