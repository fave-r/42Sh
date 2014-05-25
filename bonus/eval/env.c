/*
** env.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr 30 17:29:35 2014 romaric
** Last update Tue May 13 21:13:58 2014 romaric
*/

#include "my.h"

char	**save_env(t_env **env)
{
  char	**pathsep;
  char	*path;

  pathsep = NULL;
  path = NULL;
  if ((*env)->next != *env)
    {
      if ((path = checkpath(&(*env))) != NULL)
	{
	  path = pathcpy(path);
	  pathsep = my_str_to_wordtab(path, ':');
	}
    }
  free(path);
  return (pathsep);
}

char	*checkpath(t_env **env)
{
  int   x;
  t_env *tmp;

  tmp = (*env)->next;
  x = 1;
  while ((*env) != tmp)
    {
      if (tmp->str != NULL)
	x = strncmp("PATH=", tmp->str, 5);
      if (x == 0)
        return (strdup(tmp->str));
      tmp = tmp->next;
    }
  return (NULL);
}

char    *pathcpy(char *tmp)
{
  char  *path;

  path = xmalloc(my_strlen_n(tmp) * sizeof(char) - 4);
  rmpath(path, tmp);
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
