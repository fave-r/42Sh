/*
** main.c for test in /home/thibaud/rendu/test
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Mon Mar 31 15:38:57 2014 thibaud
** Last update Wed May 21 16:01:13 2014 Alex
*/

#include "my.h"

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

t_arbre		*add_char(char c)
{
  t_arbre	*new;

  if ((new = malloc(sizeof(t_arbre))) == NULL)
    {
      printf("Malloc error\n");
      return (NULL);
    }
  new->c = c;
  new->next = NULL;
  new->deep = NULL;
  return (new);
}

t_arbre		*creat_word(char *str)
{
  t_arbre	*new;
  t_arbre	*cur;
  int		i;

  i = 1;
  new = add_char(str[0]);
  cur = new;
  while (str[i])
    {
      cur->deep = add_char(str[i]);
      cur = cur->deep;
      i++;
    }
  if (i != 0)
    cur->deep = add_char(' ');
  else
    cur->next = add_char(' ');
  return (new);
}

int		add_word(t_arbre *arbre, char *str)
{
  int		i;
  t_arbre	*cur;

  i = 0;
  cur = arbre;
  while (str && i <= my_strlen(str))
      {
	if (cur->c != str[i] && !cur->next)
	  {
	    cur->next = creat_word(str + i);
	    return (0);
	  }
	else if (cur->c == str[i])
	    cur = cur->deep;
	else
	  {
	    cur = cur->next;
	    i--;
	  }
	i++;
      }
  return (-1);
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
  if ((result = malloc(sizeof (char) * len + 1)) == NULL)
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
	      add_word(arbre, strdup(entry->d_name));
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
  return (result);
}
