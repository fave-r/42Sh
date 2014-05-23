/*
** init.c for init in /home/odet/work/42Sh/termcap
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Tue May 20 14:11:09 2014 odet
** Last update Fri May 23 23:10:47 2014 bourrel
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

char			*find_term(t_env_var env)
{
  t_env			*tmp;
  char			*str;
  int			i;
  int			j;

  i = 0;
  j = 5;
  if (!env.env->str)
    return (NULL);
  tmp = env.env->next;
  while (strncmp(tmp->str, "TERM=", 5))
    {
      if (!tmp->next->str)
	return (NULL);
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
  ptr->x = xtgetent(find_term(env));
  ptr->x = 0;
  ptr->tmp = xmalloc(sizeof(char) * BUFF_SIZE);
  ptr->new = NULL;
  ptr->result = NULL;
  bzero(ptr->buffer, BUFF_SIZE);
  bzero(ptr->tmp, BUFF_SIZE);
}
