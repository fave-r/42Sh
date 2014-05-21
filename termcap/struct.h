/*
** my.h for mt in /home/odet/work/42Sh/termcap
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Tue May 20 15:47:59 2014 odet
** Last update Tue May 20 19:21:48 2014 odet
*/

#ifndef __GNLICANON__
#define __GNLICANON__

#include <term.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <curses.h>
#include <strings.h>
#include <string.h>

#include "my.h"

#define BUFF_SIZE 1024

typedef struct	s_gnl_icanon
{
  char	buffer[BUFF_SIZE];
  int	x;
  char	*tmp;
  char	*result;
  char	*new;
}		t_gnl_icanon;

char	*get_next_line_icanon(const int fd);
void	init();
int	xtgetent(char *bp, const char *name);
char	*my_dupstr(char *src, int len);
char	*dup_last_word(char *src);
char	*auto_completion(char *test);
void	init_value(t_gnl_icanon *ptr);

#endif
