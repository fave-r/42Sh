/*
** send_to_glob.c for send_to_glob in /tmp/42Sh/bonus/eval
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Sun May 25 04:01:59 2014 odet
** Last update Sun May 25 04:04:44 2014 odet
*/

#include "my.h"

void		sfree(char **array)
{
  int		i;

  i = 0;
  while (array != NULL && array[i] != NULL)
    {
      free(array[i]);
      i++;
    }
  if (array != NULL)
    free(array);
}

int		len_tab(char **array)
{
  int		i;

  i = 0;
  while (array[i] && array)
    i++;
  return (i);
}

char		**my_strscat(char **array, char *str)
{
  char		**new;
  int		i;

  i = 0;
  if (array == NULL)
    new = xmalloc(sizeof(char *) * 2);
  else
    {
      new = xmalloc(sizeof(char *) * (len_tab(array) + 2));
      while (array != NULL && array[i] != NULL)
	{
	  new[i] = strdup(array[i]);
	  i++;
	}
    }
  new[i] = strdup(str);
  new[i + 1] = NULL;
  sfree(array);
  return (new);
}

char		**send_to_glob(char **arv)
{
  char		**new;
  glob_t	ptr;
  int		i;
  int		j;
  int		k;

  i = -1;
  new = NULL;
  new = my_strscat(new, arv[0]);
  while (arv[++i] != NULL && arv != NULL && i < len_tab(arv))
    {
      j = -1;
      while (arv[i][++j] != '\0' && arv[i][j] != '\n' && j < strlen(arv[i]))
	if (my_strchr(arv[i][j], GLOBSEP) != -1)
	  if ((glob(arv[i], GLOBFLAG, NULL, &ptr)) != GLOB_NOMATCH)
	    {
	      k = -1;
	      while (ptr.gl_pathv[++k] && ptr.gl_pathv)
		new = my_strscat(new, ptr.gl_pathv[k]);
	      new[k] = NULL;
	      return (new);
	    }
    }
  return (arv);
}

