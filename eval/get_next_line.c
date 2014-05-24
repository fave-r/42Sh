/*
** get_next_line.c for 42sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Tue May 20 11:54:44 2014 romaric
** Last update Sat May 24 07:57:02 2014 odet
*/

#include "my.h"

char		*get_next_line(const int fd, t_env_var env)
{
  t_gnl_icanon	p;

  init_value(&p, env);
  while ((read(fd, p.buffer, BUFF_SIZE)))
    {
      if ((p.buffer[0] >= 32 && p.buffer[0] < 127))
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
      else if (p.buffer[0] == 12)
        return ("clear");
      else if (p.buffer[0] == 3)
        return ("display");
      bzero(p.buffer, 1024);
    }
  return (NULL);
}
