/*
** main.c for main in /home/odet_a/work/42Sh/termcap
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon May 19 22:57:58 2014 
** Last update Thu May 22 13:53:46 2014 odet
*/

#include "my.h"
#include "struct.h"

char		*my_tab(char *tmp, char *new, char *result, int *x)
{
  tmp[*x] = 0;
  new = dup_last_word(tmp);
  if ((result = auto_completion(new)) != NULL)
    {
      if (result != NULL)
	*x += write(1, result, strlen(result));
      tmp = strcat(tmp, result);
      free(result);
      free(new);
    }
  else if (*x > 0)
    *x = *x - 1;
  return (tmp);
}

char		*my_entry(char *tmp, char *new, char *result, int *x)
{
  (void)result;
  tmp[*x] = 0;
  *x = 0;
  new = my_dupstr(tmp, 1024);
  bzero(tmp, 1024);
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

char		*get_next_line_icanon(const int fd)
{
  t_gnl_icanon	p;
  static int	x = 0;

  if (x == 0)
    {
      x = 1;
      init();
    }
  init_value(&p);
  while ((read(fd, p.buffer, BUFF_SIZE)))
    {
      if (p.buffer[0] == '\t')
	p.tmp = my_tab(p.tmp, NULL, NULL, &(p.x));
      else if (p.buffer[0] >= 32 && p.buffer[0] < 127)
	p.x = my_char(p.tmp, p.buffer[0], &(p.x));
      else if (p.buffer[0] == '\n')
	{
	  p.new = my_entry(p.tmp, NULL, NULL, &(p.x));
	  return (p.new);
	}
      else if (p.buffer[0] == 127)
	my_delete(p.tmp, &(p.x));
      else if (p.buffer[0] == 4)
	return (NULL);
      bzero(p.buffer, 1024);
    }
  return (NULL);
}
