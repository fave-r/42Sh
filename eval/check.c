/*
** check.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr 30 17:30:19 2014 romaric
** Last update Tue May  6 17:54:16 2014 romaric
*/

#include "eval.h"

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

void	execute(char *pathutil, char *cmd, char **arv)
{
  int   pid;
  char  *pathforexec;

  if (*environ != NULL)
    {
      pathforexec = my_strcpyfinal(pathutil, cmd);
      pid = fork();
      if (pid == 0)
	execve(pathforexec, arv, environ);
      wait(NULL);
      free(pathforexec);
    }
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

void	check_path(char **pathsep, char *cmd, char **str)
{
  char  *filepath;

  filepath = NULL;
  if (*environ != NULL)
    filepath = find_lib(pathsep, cmd);
  if (filepath != NULL)
      execute(filepath, cmd, str);
  free(str);
  free(filepath);
  free(pathsep);
}

void	my_exec(char *cmd)
{
  char	**tab;
  char	**pathsep;

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
  check_path(pathsep, tab[0], tab);
}

void	check_fn(t_tree *tree)
{
  /*  if (strcmp(tree->data, ">") == 0)
    redir_right(tree);
  else if (strcmp(tree->data, ">>") == 0)
    doble_right(tree);
  else if (strcmp(tree->data, "<") == 0)
    redir_left(tree);
  else if (strcmp(tree->data, "<<") == 0)
    doble_left(tree);
  else if (strcmp(tree->data, "|") == 0)
    pipe(tree);
    else*/
  my_exec(tree->data);
  free(tree);
}
