/*
** env.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr 30 17:29:35 2014 romaric
** Last update Wed Apr 30 20:19:43 2014 romaric
*/

#include "eval.h"

extern char **environ;

char	**save_env(void)
{
  char	**pathsep;
  char	*path;
  char	**envcpy;
  int	pathi;

  pathsep = NULL;
  path = NULL;
  if (*environ != NULL)
    {
      envcpy = envcy(environ);
      pathi = checkpath(envcpy);
      path = pathcpy(envcpy, pathi);
      pathsep = my_str_to_wordtab(path, ':');
    }
  return (pathsep);
}

int     checkenv(char **env)
{
  int   i;

  i = 0;
  while (env[i] != NULL)
    i++;
  return (i);
}

char    **envcy(char **env)
{
  char **envcpy;
  int   i;
  int   check;

  i = 0;
  check = checkenv(env);
  envcpy = xmalloc(sizeof(char*) * (check + 1));
  while (i < check)
    {
      envcpy[i] = xmalloc(sizeof(char) * (my_strlen_n(env[i]) + 1));
      strcpy(envcpy[i], env[i]);
      i++;
    }
  return (envcpy);
}

int      checkpath(char **env)
{
  int   i;
  int   x;

  i = 0;
  x = 1;
  while (i < checkenv(env))
    {
      x = strncmp("PATH=", env[i], 5);
      if (x == 0)
        return (i);
      i++;
    }
  return (0);
}

char    *pathcpy(char **env, int i)
{
  char  *path;

  path = xmalloc(my_strlen_n(env[i]) * sizeof(char) - 5);
  rmpath(path, env[i]);
  return (path);
}

char    *rmpath(char *dest, char * src)
{
  int   i;
  int   x;

  i = 5;
  x = 0;
  while (src[i] != '\0')
    {
      dest[x] = src[i];
      i++;
      x++;
    }
  return (dest);
}
