/*
** my.h for test in /home/thibaud/rendu/test
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Thu May 15 02:09:37 2014 thibaud
** Last update Thu May 15 03:01:39 2014 thibaud
*/

#ifndef MY_H_
#define MY_H_

typedef struct		s_arbre
{
  char			c;
  struct s_arbre	*next;
  struct s_arbre	*deep;
}			t_arbre;

#endif
