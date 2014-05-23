/*
** auto_complete.c for test in /home/thibaud/rendu/test
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Mon Mar 31 15:38:57 2014 thibaud
** Last update Fri May 23 22:41:05 2014 bourrel
*/

#include "my.h"

extern char	**environ;

t_arbre		*make_root(void)
{
  t_arbre	*root;

  if ((root = malloc(sizeof(t_arbre))) == NULL)
    {
      printf("Malloc error\n");
      return (NULL);
    }
  root->next = NULL;
  root->deep = NULL;
  root->c = '\0';
  return (root);
}

int		go_to(t_arbre *arbre, char *str, t_arbre **ret)
{
  t_arbre	*cur;
  t_arbre	*save;
  int		i;

  i = 0;
  cur = arbre;
  while (str[i] && cur && i < my_strlen(str))
    {
      save = cur;
      if (str[i] == cur->c)
	cur = cur->deep;
      else
	{
	  cur = cur->next;
	  i--;
	}
      i++;
    }
  ret[0] = save;
  return (i);
}

char		*run_auto_completion(t_arbre *arbre, char *str)
{
  char		*result;
  t_arbre	*cur;
  int		i;
  int		len;

  if (!str || str[0] == '\0')
    return (NULL);
  cur = arbre->deep;
  i = go_to(arbre, str, &cur);
  if (i == 0 || i != my_strlen(str))
    return (NULL);
  len = calc_len(cur);
  if ((result = malloc(sizeof(char) * len + 1)) == NULL)
      exit(-1);
  result[len] = '\0';
  i = 0;
  cur = cur->deep;
  while (i < len)
    {
      result[i] = cur->c;
      cur = cur->deep;
      i++;
    }
  return (result);
}

int		fill_tree_bin(char **path, t_arbre *arbre)
{
  DIR		*ptr;
  struct dirent	*entry;
  int		i;

  i = 0;
  while (path[i] != NULL)
    {
      if ((ptr = opendir(path[i])) == NULL)
	i++;
      else
	{
	  if (ptr != NULL)
	    while ((entry = readdir(ptr)) != NULL)
	      add_word(arbre, entry->d_name);
	}
      i++;
    }
  return (1);
}

char		*auto_completion(char *test)
{
  t_arbre	*arbre;
  char		*result;
  char		*path;
  char		**path_tab;

  arbre = make_root();
  add_word(arbre, "unsetenv");
  add_word(arbre, "setenv");
  add_word(arbre, "cd");
  add_word(arbre, "echo");
  add_word(arbre, "env");
  add_word(arbre, "exit");
  path = getpath(environ);
  path_tab = my_str_to_wordtab(path, ':');
  fill_tree_bin(path_tab, arbre);
  result = run_auto_completion(arbre, test);
  free_arbre(arbre);
  return (result);
}
