/*
** my.h for my in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Mar 28 09:50:29 2014 alex-odet
** Last update Mon Apr  7 18:55:44 2014 romaric
*/

#ifndef __42Sh__
#define __42Sh__

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFF_SIZE 1024

typedef struct	s_get
{
  char		*s;
  int		c;
  int		l;
}		t_get;

typedef struct		s_token
{
  char			*buff;
  int			type;
  struct s_token	*next;
}			t_token;

t_token		*new_node(char *token, int type);
t_token		*my_put_in_list(t_token *list, char *token, int type);
void		*xmalloc(size_t);
t_token		*lexer(char *str);
int		my_strlen(char *str);
int		my_putstr(char *str, int fd);
char		*my_get_strdup(char *src);
char		*get_next_line(const int fd);
void		display_prompt();

#endif
