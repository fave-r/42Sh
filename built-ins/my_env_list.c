/*
** my_env_list.c for mysh in /home/lhomme_a/rendu/minishell2
** 
** Made by lhomme
** Login   <lhomme_a@epitech.net>
** 
** Started on  Tue Feb 25 15:56:42 2014 lhomme
** Last update Wed May 14 19:54:30 2014 bourrel
*/

#include "my.h"

t_env		*my_add_env(t_env *root, char *str)
{
  t_env		*new_elem;

  new_elem = malloc(sizeof(*new_elem));
  if (new_elem == NULL)
    return (NULL);
  new_elem->str = str;
  new_elem->prev = root->prev;
  new_elem->next = root;
  root->prev->next = new_elem;
  root->prev = new_elem;
  return (root);
}

t_env		*my_create_envlist()
{
  t_env		*root;

  root = malloc(sizeof(*root));
  if (root == NULL)
    return (NULL);
  root->prev = root;
  root->next = root;
  return (root);
}

void		my_delete_envlist(t_env **list)
{
  t_env		*tmp;
  t_env		*tmpnxt;

  tmp = (*list)->next;
  while (tmp != (*list))
    {
      tmpnxt = tmp->next;
      free(tmp);
      tmp = tmpnxt;
    }
  free(*list);
  *list = NULL;
}

void		my_print_envlist(t_env *list)
{
  t_env		*tmp;

  tmp = list->next;
  while (tmp != list)
    {
      printf("%s\n", tmp->str);
      tmp = tmp->next;
    }
}

t_env		*my_env_inlist(char **env)
{
  t_env		*env_tmp;
  int		i;

  i = 0;
  env_tmp = my_create_envlist();
  while (env[i] != NULL)
    {
      env_tmp = my_add_env(env_tmp, env[i]);
      i++;
    }
  return (env_tmp);
}
