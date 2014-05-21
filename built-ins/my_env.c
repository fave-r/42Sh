/*
** my_env.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell1
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Fri Dec 13 13:03:54 2013 lhomme
** Last update Wed May 21 12:02:24 2014 lhomme
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
  return (env);
}

t_env	*my_env(t_env *env, char **tab)
{
  if (!tab[1])
    my_print_envlist(env);
  else if ((strcmp(tab[1], "-0") == 0)
	   || (strcmp(tab[1], "--null") == 0))
    my_env_null(env);
  else if ((strcmp(tab[1], "--version") == 0)
	   || (strcmp(tab[1], "--help") == 0))
    my_env_vh(tab[1]);
  else if ((strcmp(tab[1], "-i") == 0)
	   || (strcmp(tab[1], "--ignore-environment") == 0))
    env = my_env_i(env);
  else if ((strncmp(tab[1], "-u", 2) == 0)
	   || (strcmp(tab[1], "--unset") == 0))
    env = my_unsetenv(env, tab + 1);
  else
    printf("env: invalid option: %s\n", tab[0]);
  return (env);
}
