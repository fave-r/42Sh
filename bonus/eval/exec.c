/*
** exec.c for 42Sh in /home/leo/rendu/42Sh/eval
**
** Made by bourrel
** Login   <leo@epitech.net>
**
** Started on  Tue May 20 15:24:47 2014 bourrel
** Last update Sun May 25 16:08:42 2014 lhomme
*/

#include "my.h"

int	check_exit_value(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '-' && i == 0 && str[i + 1] != 0)
	i++;
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i++;
    }
  return (0);
}

int	my_exit(char **tab, t_env *env)
{
  t_env	*tmp;

  tmp = env->next;
  while (tmp != env && strncmp(tmp->str, "EXIT_VALUE", 10) != 0)
    tmp = tmp->next;
  if (tab[1] && (check_exit_value(tab[1]) == -1))
    return (-1);
  if (tmp == env)
    {
      my_add_env(env, "EXIT_VALUE=0");
      return (my_exit(tab, env));
    }
  if (tab[1] && (my_getnbr(tab[1]) != 0))
    tmp->str = my_strcat(tmp->str, tab[1]);
  else
    tmp->str = my_strcat(tmp->str, "256");
  return (1);
}

int     built(char **tab, t_env *env, t_env *history, int out)
{
  if (strncmp(tab[0], "setenv", 6) == 0 && !tab[0][6])
    env = my_setenv(env, tab);
  else if (strncmp(tab[0], "cd", 2) == 0
           && (!tab[0][2] || tab[0][2] == '-'
	       || (tab[0][2] == '.' && !tab[0][4])))
    return (my_cd(env, tab));
  else if (strncmp(tab[0], "unsetenv", 8) == 0 && !tab[0][8])
    env = my_unsetenv(env, tab);
  else if (strncmp(tab[0], "env", 3) == 0 && !tab[0][3])
    env = my_env(env, tab, out);
  else if (strncmp(tab[0], "echo", 4) == 0 && !tab[0][4])
    my_echo(tab, out);
  else if (strncmp(tab[0], "exit", 4) == 0 && !tab[0][4])
    return (my_exit(tab, env));
  else if (strncmp(tab[0], "history", 7) == 0 && !tab[0][7])
    return (my_print_history(env, history, tab, out));
  else
    {
      fprintf(stderr, "%s : command not found\n", tab[0]);
      return (-1);
    }
  return (0);
}

int	exec_builtins(char *cmd, char **tab, t_env_var env, t_inp p)
{
  char  **pathsep;

  if (strncmp(cmd, "setenv", 6) == 0 || strncmp(cmd, "cd", 2) == 0
      || strncmp(cmd, "unsetenv", 8) == 0 || strncmp(cmd, "env", 3) == 0
      || strncmp(cmd, "echo", 4) == 0 || strncmp(cmd, "exit", 4) == 0
      || strncmp(cmd, "history", 7) == 0)
    return (built(tab, env.env, env.history, p.out));
  else
    {
      pathsep = save_env(&(env.env));
      return (check_path(pathsep, tab[0], tab, p));
    }
}

int     my_exec(char *cmd, int in, int out, t_env_var *env)
{
  char  **tab;
  t_inp p;

  p.in = in;
  p.out = out;
  p.wat = env->wat;
  p.var_close = env->var_close;
  tab = NULL;
  if (strchr(cmd, ' ') != NULL)
    tab = my_str_to_wordtab(cmd, ' ');
  else
    {
      tab = xmalloc(2 * sizeof(char *));
      tab[0] = xmalloc(strlen(cmd) * sizeof(char));
      tab[0] = cmd;
      tab[1] = NULL;
    }
  return (exec_builtins(cmd, tab, *env, p));
}
