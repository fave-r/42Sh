/*
** check.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr 30 17:30:19 2014 romaric
** Last update Sun May 11 18:04:24 2014 romaric
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

int	execute(char *pathutil, char *cmd, char **arv)
{
  int   pid;
  int	ret;
  char  *pathforexec;

  ret = 1;
  if (*environ != NULL)
    {
      pathforexec = my_strcpyfinal(pathutil, cmd);
      pid = fork();
      if (pid == 0)
	execve(pathforexec, arv, environ);
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
  if (cmd != '\0' && strcmp(cmd, "exit") != 0)
    fprintf(stderr, "%s: command not found\n", cmd);
  return (NULL);
}

int	check_path(char **pathsep, char *cmd, char **str)
{
  int	ret;
  char  *filepath;

  ret = 1;
  filepath = NULL;
  if (*environ != NULL)
    filepath = find_lib(pathsep, cmd);
  if (filepath != NULL)
    ret = execute(filepath, cmd, str);
  free(str);
  free(filepath);
  free(pathsep);
  return (ret);
}

int	my_exec(char *cmd)
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
  pathsep = save_env();
  return (check_path(pathsep, tab[0], tab));
}

/*
** fonction eval
*/

int	check_fn(t_tree *tree, int in, int out)
{
  if (strcmp(tree->data, ">") == 0)
    return (redir_right(tree, in, out));
  else if (strcmp(tree->data, ">>") == 0)
    return (doble_right(tree, in, out));
  else if (strcmp(tree->data, "<") == 0)
    return (redir_left(tree, in, out));
  /*
    else if (strcmp(tree->data, "<<") == 0)
    return (doble_left(tree, in, out));
    else if (strcmp(tree->data, "|") == 0)
    return (my_pipe(tree, in, out));
  */
  else if (strcmp(tree->data, "&&") == 0)
    return (my_and(tree, in, out));
  else if (strcmp(tree->data, "||") == 0)
    return (my_or(tree, in, out));
  else if (strcmp(tree->data, ";") == 0)
    return (my_semi_col(tree, in, out));
  else
    return (my_exec(tree->data));
}
