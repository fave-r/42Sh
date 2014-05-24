/*
** display.c for 42sh in /home/leo/rendu/42Sh
**
** Made by bourrel
** Login   <leo@epitech.net>
**
** Started on  Thu May 22 11:49:29 2014 bourrel
** Last update Sun May 25 00:15:46 2014 lhomme
*/

#include "my.h"

char		*check_user(t_env **env)
{
  int		x;
  t_env		*tmp;

  tmp = (*env)->next;
  x = 1;
  while ((*env) != tmp)
    {
      if (tmp->str != NULL)
	x = strncmp("USER=", tmp->str, 5);
      if (x == 0)
	return (strdup(tmp->str));
      tmp = tmp->next;
    }
  return (NULL);
}

void            display_prompt(t_env *env)
{
  char		*user;

  user = NULL;
  if ((env))
    {
      if (env->next != env)
	{
	user = check_user(&env);
	if (user != NULL)
	user = rmpath(user, user);
	}
    }
  if (user != NULL)
    {
      my_putstr("\033[32m$", 1);
      my_putstr(user, 1);
      my_putstr("> \033[0;m", 1);
    }
  else
    my_putstr("\033[32m$42sh> \033[0;m", 1);
  free(user);
}

void            display_sigint()
{
  write(1, "^C\n", 3);
}
