/*
** my.c for my in /home/odet/work/42Sh/termcap
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Thu May 22 14:57:51 2014 odet
** Last update Sat May 24 17:17:00 2014 odet
*/

#include "my.h"
#include "struct.h"

int		match(char *tmp, int len)
{
  int		result;
  int		x;

  x = len;
  result = strlen (tmp);
  while (tmp[len])
    {
      write(1, &tmp[len], 1);
      len++;
    }
  return (result - x);
}

char		*my_tab(t_gnl_icanon *p, char *new, char *result, t_env_var *env)
{
  int		len;

  p->tmp[p->x] = 0;
  new = dup_last_word(p->tmp);
  len = strlen(new);
  if ((result = auto_completion(new)) != NULL)
    {
      if (result != NULL)
	p->x += write(1, result, strlen(result));
      else if (p->x > 0)
	p->x = p->x - 1;
      p->tmp = strcat(p->tmp, result);
      free(result);
      free(new);
    }
  if (result == NULL)
    if ((result = glob_complete(new, p->tmp, env)))
      if (strcmp(result, p->tmp) != 0)
	{
	  p->x += write(1, result + len, strlen(result) - len);
	  p->tmp = strcat(p->tmp, result + len);
	}
  return (p->tmp);
}

char		*my_entry(char *tmp, char *new, char *result, int *x)
{
  (void)result;
  tmp[*x] = 0;
  *x = 0;
  new = my_dupstr(tmp, 1024);
  new = find(new);
  bzero(tmp, BUFF_SIZE);
  write(1, "\n", 1);
  return (new);
}

int		my_char(char *tmp, char to_copy, int *x)
{
  int	a;

  a = *x;
  write(1, &to_copy, 1);
  tmp[a] = to_copy;
  a++;
  return (a);
}

void		my_delete(char *tmp, int *x)
{
  tmp[*x] = '\b';
  if (*x == 0)
    write(1, "\a", 1);
  else
    write(1, "\b \b", 3);
  if (*x > 0)
    *x -= 1;
}
