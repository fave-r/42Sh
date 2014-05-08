/*
** lexer_fct.c for 42sh in /home/thibaud/rendu/42sh/42Sh/lexing/test
** 
** Made by thibaud
** Login   <thibaud@epitech.net>
** 
** Started on  Mon Apr 14 23:48:28 2014 thibaud
** Last update Thu May  8 18:16:09 2014 thibaud
*/

#include "my.h"

int		is_spe(char c)
{
  if (c != '\t' && c != ' ' && c != '\0' && c != '|'
      && c != '&' && c != '>' && c != '<' && c != ';')
    return (0);
  return (1);
}

int     is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}
