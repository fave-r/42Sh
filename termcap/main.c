B1;2802;0c/*
** main.c for main in /home/odet_a/work/42Sh/termcap
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon May 19 22:57:58 2014 
** Last update Tue May 20 00:12:12 2014 
*/

#include <term.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <ncurses/curses.h>
#include <strings.h>
#include <string.h>

int	main(int ac, char **av, char **env)
{
  struct termios	p;
  char	buffer[1024];
  int	x;
  char	*tmp;

  tcgetattr(1, &p);
  p.c_lflag &= ~ICANON;
  p.c_lflag &= ~ECHO;
  tcsetattr(1, 0, &p);
  x = tgetent(NULL, "xterm");
  if (x != 1)
    {
      printf("termcaps error\n");
      exit(EXIT_FAILURE);
    }
  x = 0;
  tmp = malloc(sizeof(char) * 1024);
  while ((read(0, buffer, 1024)))
    {
      if (buffer[0] == '\t')
	printf("AUTOCOMPLETE\n");
      if (buffer[0] >= 32 && buffer[0] < 127)
	{
	  write(1, &buffer[0], 1);
	  tmp[x] = buffer[0];
	  x++;
	}
      if (buffer[0] == '\n')
	{
	  tmp[x] = 0;
	  printf("\nbuffer = %s$\n", tmp);
	  x = 0;
	  bzero(tmp, 1024);
	}
      bzero(buffer, 1024);
    }
  free (tmp);
  return (0);
}
