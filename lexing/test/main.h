/*
** main.h for lexer in /home/thibaud/rendu/42sh
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Sat Apr 12 03:29:52 2014 thibaud
** Last update Sat Apr 12 03:33:19 2014 thibaud
*/

#include <unistd.h>

typedef	struct	s_list
{
  char		*token;
  int		type;
  struct s_list	*next;

}		t_list;
