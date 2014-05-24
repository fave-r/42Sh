/*
** init.c for init in /home/odet/work/42Sh/termcap
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Tue May 20 14:11:09 2014 odet
** Last update Sat May 24 11:35:33 2014 odet
*/

#include "my.h"
#include "struct.h"

void			init()
{
  struct termios	p;

  tcgetattr(1, &p);
  p.c_lflag &= ~ICANON;
  p.c_lflag &= ~ECHO;
  p.c_cc[VMIN] = 1;
  p.c_cc[VTIME] = 0;
  tcsetattr(1, 0, &p);
}

int			xtgetent(const char *name)
{
  int			x;

  x = tgetent(NULL, name);
  if (x != 1)
    {
      printf("error termcaps.\n");
      return (-1);
    }
  return (x);
}

char			*find_term(t_env_var env, char *str)
{
  t_env			*tmp;
  int			i;
  int			j;

  i = 0;
  j = 5;
  env.env = env.env->next;
  if (!env.env->str)
    return (TERM);
  tmp = env.env;
  while (strncmp(tmp->str, "TERM=", 5))
    {
      if (!tmp->next->str)
	return (TERM);
      tmp = tmp->next;
    }
  str = malloc(sizeof(char) * (strlen(tmp->str) - 4));
  while (tmp->str[j] != '\0')
    {
      str[i] = tmp->str[j];
      j++;
      i++;
    }
  str[i] = '\0';
  return (str);
}

void			init_value(t_gnl_icanon *ptr, t_env_var env)
{
  char			*str;

  str = NULL;
  str = find_term(env, str);
  ptr->x = xtgetent(str);
  ptr->x = 0;
  ptr->tmp = xmalloc(sizeof(char) * BUFF_SIZE);
  ptr->new = NULL;
  ptr->result = NULL;
  ptr->save = "";
  bzero(ptr->buffer, BUFF_SIZE);
  bzero(ptr->tmp, BUFF_SIZE);
  //free (str);
}
