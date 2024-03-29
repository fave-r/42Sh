/*
** check.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr 30 17:30:19 2014 romaric
** Last update Sun May 25 20:59:34 2014 romaric
*/

#include "my.h"

extern char	**environ;

void		show(char **array)
{
  int		i;

  i = 0;
  if (array == NULL)
    printf("NULL.\n");
  else
    while (array != NULL && array[i])
      printf("%s\n", array[i++]);
}

int		execute(char *pathutil, char *cmd, char **arv, t_inp p)
{
  int		pid;
  int		ret;
  char		*pathforexec;
  char		**glob;

  ret = 1;
  glob = send_to_glob(arv);
  pathforexec = ((pathutil == NULL) ? cmd : my_strcpyfinal(pathutil, cmd));
  pid = fork();
  if (pid == 0)
    {
      if (p.out != 1)
	dup2(p.out, 1);
      if (p.in != 0)
	dup2(p.in, 0);
      if (p.var_close != -1)
	close(p.var_close);
      execve(pathforexec, glob, environ);
      fprintf(stderr, "42sh: %s: command not found\n", pathforexec);
      exit(1);
    }
  if (p.wat == 1)
    waitpid(pid, &ret, 0);
  return (ret);
}

char		*find_lib(char **path, char *cmd)
{
  DIR		*ptr;
  struct dirent	*entry;
  int		i;

  i = 0;
  if ((path))
    {
      while (path[i] != NULL)
	{
	  if ((ptr = opendir(path[i])) != NULL)
	    if (ptr != NULL)
	      {
		while ((entry = readdir(ptr)))
		  if (strcmp(cmd, entry->d_name) == 0)
		    return (strdup(path[i]));
	      }
	  i++;
	}
    }
  return (NULL);
}

int		check_path(char **pathsep, char *cmd, char **str, t_inp p)
{
  int		ret;
  char		*filepath;

  ret = 1;
  filepath = NULL;
  if (pathsep != NULL)
    filepath = find_lib(pathsep, cmd);
  ret = execute(filepath, cmd, str, p);
  free(str);
  free(filepath);
  free(pathsep);
  return (ret);
}

/*
** fonction eval
*/

int		check_fn(t_tree *tree, int in, int out, t_env_var *env)
{
  if (!tree)
    return (-1);
  else if (strcmp(tree->data, ">") == 0)
    return (redir_right(tree, in, out, env));
  else if (strcmp(tree->data, ">>") == 0)
    return (doble_right(tree, in, out, env));
  else if (strcmp(tree->data, "<") == 0)
    return (redir_left(tree, in, out, env));
  else if (strcmp(tree->data, "&&") == 0)
    return (my_and(tree, in, out, env));
  else if (strcmp(tree->data, "||") == 0)
    return (my_or(tree, in, out, env));
  else if (strcmp(tree->data, ";") == 0)
    return (my_semi_col(tree, in, out, env));
  else if (strcmp(tree->data, "<<") == 0)
    return (doble_left(tree, in, out, env));
  else if (strcmp(tree->data, "|") == 0)
    return (my_pipe(tree, in, out, env));
  else
    return (my_exec(tree->data, in, out, env));
}
