/*
** send_to_glob.c for send_to_glob in /home/odet/work/42Sh/bonus/eval
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Sat May 24 20:06:34 2014 odet
** Last update Sun May 25 16:47:46 2014 lhomme
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

void		print(char **tabl)
{
  int		i;

  i = 0;
  while (tabl[i])
    {
      printf("line : %d\t:%s\n", i, tabl[i]);
      i++;
    }
  printf("--------------\n");
}

char		**send_to_glob(char **arv)
{
  char		**new;
  glob_t	ptr;
  int		i;
  int		j;
  int		k;
  char		**tmp;

  i = 0;
  new = NULL;
  tmp = NULL;
  print(arv);
  if (len_tab(arv) == 1)
    return (arv);
  new = my_strscat(tmp, arv[0]);
  if (len_tab(arv) > 1)
    if (arv[1][0] == '-' && arv[1] != NULL)
      new = my_strscat(tmp, arv[1]);
  while (arv[i] != NULL && arv != NULL && i < len_tab(arv))
    {
      j = 0;
      while (arv[i][j] != '\0' && arv[i][j] != '\n' && j < strlen(arv[i]))
	{
	  if (my_strchr(arv[i][j], GLOBSEP) != -1)
	    {
	      if ((glob(arv[i], GLOBFLAG, NULL, &ptr)) != GLOB_NOMATCH)
		{
		  k = 0;
		  print(ptr.gl_pathv);
		  while (ptr.gl_pathv[k] && ptr.gl_pathv)
		    {
		      new = my_strscat(tmp, ptr.gl_pathv[k]);
		      k++;
		    }
		  return (new);
		}
	      printf("je n'ai trouvé aucun caractère qui glob.\n");
	    }
	  j++;
	}
      i++;
    }
  globfree(&ptr);
  return (arv);
}
