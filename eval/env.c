/*
** env.c for 42Sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Wed Apr 30 17:29:35 2014 romaric
** Last update Tue May 13 19:35:00 2014 romaric
*/

#include "my.h"

//extern char **environ;

char	**save_env(t_env **env)
{
  char	**pathsep;
  char	*path;

  pathsep = NULL;
  path = NULL;
  if (*env != NULL)
    {
      //envcpy = envcy(environ);
      if (checkpath(&(*env)) == 0)
	{
	  path = pathcpy(&(*env));
	  printf("path = %s\n", path);
	  pathsep = my_str_to_wordtab(path, ':');
	}
    }
  free(path);
  return (pathsep);
}

/*int     checkenv(char **env)
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
  envcpy[i] = NULL;
  return (envcpy);
  }*/

int	checkpath(t_env **env)
{
  int   x;
  t_env *tmp;

  tmp = (*env);
  x = 1;
  (*env) = (*env)->next;
  while ((*env) != tmp)
    {
      if((*env)->str != NULL)
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
  //free_doble(env);
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
