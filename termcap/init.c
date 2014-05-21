/*
** init.c for init in /home/odet/work/42Sh/termcap
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Tue May 20 14:11:09 2014 odet
** Last update Wed May 21 16:10:57 2014 Alex
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

int			xtgetent(char *bp, const char *name)
{
  int			x;

  x = tgetent(bp, name);
  if (x != 1)
    {
      printf("error termcaps.\n");
      return (-1);
    }
  return (x);
}

char	*my_dupstr(char *src, int len)
{
  char	*new;

  new = malloc(sizeof(char) * (len + 1));
  bzero(new, len);
  strcpy(new, src);
  return (new);
}

char	*dup_last_word(char *src)
{
  int	i;
  int	len;
  char	*new;

  i = 0;
  if (src == NULL)
    return (NULL);
  len = strlen(src);
  while (len > 0 && src[len] != ' ')
      len--;
  if (src[len] == ' ')
    len++;
  new = strdup(src + len);
  return (new);
}

void		init_value(t_gnl_icanon *ptr)
{
  ptr->x = xtgetent(NULL, "xterm");
  ptr->x = 0;
  ptr->tmp = malloc(sizeof(char) * BUFF_SIZE);
  bzero(ptr->buffer, BUFF_SIZE);
}
