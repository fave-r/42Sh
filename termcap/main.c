/*
** main.c for main in /home/odet_a/work/42Sh/termcap
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon May 19 22:57:58 2014 
** Last update Tue May 20 19:34:47 2014 odet
*/

#include "struct.h"

char		*my_tab(char *tmp, char *new, char *result, int *x)
{
  tmp[*x] = 0;
  new = dup_last_word(tmp);
  if ((result = auto_completion(new)))
    tmp = strcat(tmp, result);
  if (result != NULL)
    *x += write(1, result, strlen(result));
  else if (x > 0)
    *x = *x - 1;
  return (tmp);
}

char		*my_entry(char *tmp, char *new, char *result, int *x)
{
  (void)result;
  tmp[*x] = 0;
  *x = 0;
  new = my_dupstr(tmp, BUFF_SIZE);
  bzero(tmp, BUFF_SIZE);
  write(1, "\n", 1);
  return (new);
}

void		my_char(char *tmp, char to_copy, int *x)
{
  write(1, &to_copy, 1);
  tmp[*x] = to_copy;
  *x += 1;
}

void		my_delete(char *tmp, int *x)
{
  tmp[*x] = '\b';
  write(1, "\b \b", 3);
  *x -= 1;
}

char		*get_next_line_icanon(const int fd)
{
  t_gnl_icanon	p;

  init();
  init_value(&p);
  while ((read(fd, p.buffer, BUFF_SIZE)))
    {
      if (p.buffer[0] == '\t')
	p.tmp = my_tab(p.tmp, NULL, NULL, &(p.x));
      if (p.buffer[0] >= 32 && p.buffer[0] < 127)
	my_char(p.tmp, p.buffer[0], &(p.x));
      if (p.buffer[0] == '\n')
	{
	  p.new = my_entry(p.tmp, NULL, NULL, &(p.x));
	  return (p.new);
	}
      if (p.buffer[0] == 127)
	my_delete(p.tmp, &(p.x));
      bzero(p.buffer, BUFF_SIZE);
    }
  free(p.tmp);
  return (NULL);
}
