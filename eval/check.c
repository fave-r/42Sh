/*
** check.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr 30 17:30:19 2014 romaric
** Last update Tue May 20 10:37:24 2014 romaric
*/

#include "my.h"

extern char **environ;

int	execute(char *pathutil, char *cmd, char **arv, t_inp p)
{
  int   pid;
  int	ret;
  char  *pathforexec;

  ret = 1;
  if (*environ != NULL)
    {
      pathforexec = ((pathutil == NULL) ? cmd : my_strcpyfinal(pathutil, cmd));
      pid = fork();
      if (pid == 0)
	{
	  if (p.out != 1)
	    dup2(p.out, 1);
	  if (p.in != 0)
	    dup2(p.in, 0);
	  execve(pathforexec, arv, environ);
	  fprintf(stderr, "42sh: %s: command not found\n", pathforexec);
	  exit(1);
	}
      wait(&ret);
      free(pathforexec);
    }
  return (ret);
}

char    *find_lib(char **path, char *cmd)
{
  DIR   *ptr;
  struct dirent *entry;
  int   i;

  i = 0;
  while (path[i] != NULL)
    {
      if ((ptr = opendir(path[i])) == NULL)
        i++;
      else
        if (ptr != NULL)
          {
	    while ((entry = readdir(ptr)))
              if (strcmp(cmd, entry->d_name) == 0)
		return (strdup(path[i]));
          }
      i++;
    }
  return (NULL);
}

int	check_path(char **pathsep, char *cmd, char **str, t_inp p)
{
  int	ret;
  char	*filepath;

  ret = 1;
  filepath = NULL;
  if (*environ != NULL)
    filepath = find_lib(pathsep, cmd);
  ret = execute(filepath, cmd, str, p);
  free(str);
  free(filepath);
  free(pathsep);
  return (ret);
}

void	built(char **tab, t_env **env, int out)
{
  if (strncmp(tab[0], "setenv", 6) == 0 && !tab[0][6])
    *env = my_setenv(*env, tab);
  else if (strncmp(tab[0], "cd", 2) == 0
	   && (!tab[0][2] || tab[0][2] == '-' || (tab[0][2] == '.' && !tab[0][4])))
    my_cd(*env, tab);
  else if (strncmp(tab[0], "unsetenv", 8) == 0 && !tab[0][8])
    *env = my_unsetenv(*env, tab);
  else if (strncmp(tab[0], "env", 3) == 0 && !tab[0][3])
    *env = my_env(*env, tab);
  else if (strncmp(tab[0], "echo", 4) == 0 && !tab[0][4])
    my_echo(tab, out);
  //  else
  //  fprintf(stderr, "%s : command not found\n", tab[0]);
}

int	my_exec(char *cmd, int in, int out, t_env **env)
{
  int	ret;
  char	**tab;
  char	**pathsep;
  t_inp	p;

  p.in = in;
  p.out = out;
  ret = 0;
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
  if (strncmp(cmd, "setenv", 6) == 0 || strncmp(cmd, "cd", 2) == 0
      || strncmp(cmd, "unsetenv", 8) == 0 || strncmp(cmd, "env", 3) == 0
      || strncmp(cmd, "echo", 4) == 0)
    {
      built(tab, &(*env), out);
      return (0);
    }
  else
    {
      pathsep = save_env(&(*env));
      return (check_path(pathsep, tab[0], tab, p));
    }
}

/*
** fonction eval
*/

int	check_fn(t_tree *tree, int in, int out, t_env **env)
{
  if (strcmp(tree->data, ">") == 0)
    return (redir_right(tree, in, out, &(*env)));
  else if (strcmp(tree->data, ">>") == 0)
    return (doble_right(tree, in, out, &(*env)));
  else if (strcmp(tree->data, "<") == 0)
    return (redir_left(tree, in, out, &(*env)));
  else if (strcmp(tree->data, "&&") == 0)
    return (my_and(tree, in, out, &(*env)));
  else if (strcmp(tree->data, "||") == 0)
    return (my_or(tree, in, out, &(*env)));
  else if (strcmp(tree->data, ";") == 0)
    return (my_semi_col(tree, in, out, &(*env)));
  else
    return (my_exec(tree->data, in, out, &(*env)));
}
