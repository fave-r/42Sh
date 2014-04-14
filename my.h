/*
** my.h for my in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Fri Mar 28 09:50:29 2014 alex-odet
** Last update Tue Apr 15 00:05:33 2014 thibaud
*/

#ifndef __42Sh__
#define __42Sh__

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFF_SIZE 1024

typedef struct  s_list
{
  char          *token;
  int           type;
  struct s_list *next;

}

t_list          *add_token(t_list *, char *);
void		*my_xdup(void *, int);
int		get_operator(char *, int , int [2]);
int		get_other(char *, int , int [2]);
int		is_spe(char );
t_list          *fill_token(char *);
int		fill_type(t_list *);
list		*lexer(char *);


#endif
