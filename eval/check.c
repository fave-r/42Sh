/*
** check.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr 30 17:30:19 2014 romaric
** Last update Tue May 13 19:05:31 2014 romaric
*/

#include "my.h"

extern char **environ;

char    *my_strcpyfinal(char *dest, char *cmd)
{
  int   i;
  int   x;
  char  *tmp;

  x = 0;
  i = my_strlen_n(dest);
  tmp = xmalloc((my_strlen_n(dest) + my_strlen_n(cmd) + 2) * sizeof(char));
  while (x < (my_strlen_n(dest)))
    {
      tmp[x] = dest[x];
      x++;
    }
  x = 0;
  tmp[i] = '/';
  i++;
  while (cmd[x] != '\0')
    {
      tmp[i] = cmd[x];
      i++;
      x++;
    }
  tmp[i] = '\0';
  return (tmp);
}

int	execute(char *pathutil, char *cmd, char **arv, int in, int out)
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
	  if(out != 1)
	    dup2(out, 1);
	  if(in != 0)
	    dup2(in, 0);
	  execve(pathforexec, arv, environ);
	  fprintf(stderr, "%s: command not found\n", pathforexec);
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

int	check_path(char **pathsep, char *cmd, char **str, int in, int out)
{
  int	ret;
  char  *filepath;

  ret = 1;
  filepath = NULL;
  if (*environ != NULL)
    filepath = find_lib(pathsep, cmd);
  ret = execute(filepath, cmd, str, in, out);
  free(str);
  free(filepath);
  free(pathsep);
  return (ret);
}

int	my_exec(char *cmd, int in, int out, t_env **env)
{
  int	ret;
  char	**tab;
  char	**pathsep;

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
  pathsep = save_env(&(*env));
  return (check_path(pathsep, tab[0], tab, in, out));
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
  /*
    else if (strcmp(tree->data, "<<") == 0)
    return (doble_left(tree, in, out));
    else if (strcmp(tree->data, "|") == 0)
    return (my_pipe(tree, in, out));
  */
  else if (strcmp(tree->data, "&&") == 0)
    return (my_and(tree, in, out, &(*env)));
  else if (strcmp(tree->data, "||") == 0)
    return (my_or(tree, in, out, &(*env)));
  else if (strcmp(tree->data, ";") == 0)
    return (my_semi_col(tree, in, out, &(*env)));
  else
    return (my_exec(tree->data, in, out, &(*env)));
}
