/*
** lexer_fct.c for 42sh in /home/thibaud/rendu/42sh/42Sh/lexing/test
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Mon Apr 14 23:48:28 2014 thibaud
** Last update Sat May 24 16:15:56 2014 lhomme
*/

#include "my.h"

int		is_spe(char c)
{
  if ((c != '\t' && c != ' ' && c != '\0' && c != '|'
       && c != '&' && c != '>' && c != '<' && c != ';'))
    return (0);
  return (1);
}

int     is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
      || (c >= '0' && c <= '9'))
    return (1);
  return (0);
}
