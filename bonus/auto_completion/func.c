/*
** func.c for 42sh in /home/leo/rendu/42Sh/auto_completion
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Fri May 23 22:25:46 2014 bourrel
** Last update Fri May 23 22:40:18 2014 bourrel
*/

#include "my.h"

int	calc_len(t_arbre *cur)
{
  int	i;

  i = 0;
  cur = cur->deep;
  while (cur->c != ' ' && cur->next == NULL)
    {
      cur = cur->deep;
      i++;
    }
  return (i);
}

char	*getpath(char **environ)
{
  int	i;

  i = 0;
  if (*environ != NULL)
    {
      while (environ[i])
        {
          if (strncmp("PATH=", environ[i], 5) == 0)
            return (strdup(environ[i] + 5));
          i++;
        }
    }
  return (PATH);
}

void	free_arbre(t_arbre *tree)
{
  if (tree != NULL)
    {
      free_arbre(tree->next);
      free_arbre(tree->deep);
      free(tree);
    }
}
