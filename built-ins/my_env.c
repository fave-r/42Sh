/*
** my_env.c for mysh in /home/lhomme_a/rendu/PSU_2013_minishell1
**
** Made by lhomme
** Login   <lhomme_a@epitech.net>
**
** Started on  Fri Dec 13 13:03:54 2013 lhomme
** Last update Sun May 25 21:39:51 2014 romaric
*/

#include "my.h"

void	my_env_help(int fd)
{
  my_putstr("env (GNU coreutils) 8.17\nCopyright (C) 2012 Free Software ", fd);
  my_putstr("Foundation, Inc.\nLicense GPLv3+: GNU GPL version 3 or late", fd);
  my_putstr("r <http://gnu.org/licenses/gpl.html>.\nThis is free softwar", fd);
  my_putstr("e: you are free to change and redistribute it.\nThere is NO", fd);
  my_putstr("WARRANTY, to the extent permitted by law.\n\n", fd);
  my_putstr("Written by Richard Mlynarik and David MacKenzie.\n", fd);
}

void	my_env_version(int fd)
{
  my_putstr("Usage: env [OPTION]... [-] [NAME=VALUE]... [COMMAND [ARG]..", fd);
  my_putstr(".]\nSet each NAME to VALUE in the environment and run COMMA", fd);
  my_putstr("ND.\n\n  -i, --ignore-environment  start with an empty envi", fd);
  my_putstr("ronment\n  -0, --null           end each output line with 0", fd);
  my_putstr(" byte rather than newline\n  -u, --unset=NAME     remove va", fd);
  my_putstr("riable from the environment\n      --help     display this ", fd);
  my_putstr("help and exit\n      --version  output version information ", fd);
  my_putstr("and exit\n\nA mere - implies -i.  If no COMMAND, print the ", fd);
  my_putstr("resulting environment.\n\nReport env bugs to bug-coreutils@", fd);
  my_putstr("gnu.org\nGNU coreutils home page: <http://www.gnu.org/softw", fd);
  my_putstr("are/coreutils/>\nGeneral help using GNU software: <http://w", fd);
  my_putstr("ww.gnu.org/gethelp/>\nFor complete documentation, run:", fd);
  my_putstr(" info coreutils 'env invocation'\n", fd);
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

t_env	*my_env(t_env *env, char **tab, int fd)
{
  if (!tab[1])
    my_print_envlist(env, fd);
  else if ((strcmp(tab[1], "-0") == 0)
	   || (strcmp(tab[1], "--null") == 0))
    my_env_null(env);
  else if (strcmp(tab[1], "--help") == 0)
    my_env_help(fd);
  else if (strcmp(tab[1], "--version") == 0)
    my_env_version(fd);
  else if ((strcmp(tab[1], "-i") == 0)
	   || (strcmp(tab[1], "--ignore-environment") == 0))
    return (env);
  else if ((strncmp(tab[1], "-u", 2) == 0)
	   || (strcmp(tab[1], "--unset") == 0))
    env = my_unsetenv(env, tab + 1);
  else
    printf("env: invalid option: %s\n", tab[0]);
  return (env);
}
