/*
** env.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr 30 17:29:35 2014 romaric
** Last update Tue May 13 20:53:12 2014 romaric
*/

#include "my.h"

char	**save_env(t_env **env)
{
  char	**pathsep;
  char	*path;

  pathsep = NULL;
  path = NULL;
  if (*env != NULL)
    {
      if (checkpath(&(*env)) == 0)
	{
	  path = pathcpy(&(*env));
	  pathsep = my_str_to_wordtab(path, ':');
	}
    }
  free(path);
  return (pathsep);
}

int	checkpath(t_env **env)
{
  int   x;
  t_env *tmp;

  tmp = (*env);
  x = 1;
  (*env) = (*env)->next;
  (*env) = (*env)->next;
  while ((*env) != tmp)
    {
      if ((*env)->str != NULL)
	x = strncmp("PATH=", (*env)->str, 5);
      if (x == 0)
        return (0);
      (*env) = (*env)->next;
    }
  return (1);
}

char    *pathcpy(t_env **env)
{
  char  *path;

  path = xmalloc(my_strlen_n((*env)->str) * sizeof(char) - 4);
  rmpath(path, (*env)->str);
  return (path);
}

char    *rmpath(char *dest, char *src)
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
  dest[x] = '\0';
  return (dest);
}
