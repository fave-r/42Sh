/*
** my.h for my.h in /home/alex-odet/work/42Sh
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Apr 15 17:07:43 2014 alex-odet
** Last update Thu Apr 17 03:36:50 2014 
*/

#ifndef __42Sh__
#define __42Sh__

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <glob.h>

#define BUFF_SIZE 1024

typedef struct		s_token
{
  char			*token;
  int			type;
  struct s_token	*next;

}			t_token;

typedef struct s_get
{
  char		*s;
  int		c;
  int		l;
}		t_get;

int	print_token(t_token *list);
t_token	*add_token(t_token *list, char *token);
char	*my_strxdup(char *source, int len);
int	get_operator(char *str, int i, int save[2]);
int	get_other(char *str, int i, int save[2]);
t_token	*fill_token(char *str);
int	fill_type(t_token *list);
t_token	*fill_list_token(char *str);
int	my_putstr(char *str, int fd);
void	*xmalloc(size_t n);
void	display_prompt();
char	*get_next_line(const int fd);
int	my_strlen(char *str);
char	*my_auto_complete(char *path);

#endif
