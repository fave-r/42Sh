/*
** priority.c for npi in /home/lhomme_a/rendu/42Sh/npi
**
** Made by lhomme
** Login   <lhomme_a@epitech.net>
**
** Started on  Wed Apr 23 16:23:56 2014 lhomme
** Last update Sun May 25 20:34:07 2014 romaric
*/

#include "my.h"

int	my_priority(char *d1, char *d2)
{
  if (d2 == NULL || d1 == NULL)
    return (0);
  if (d1[0] == ';')
    return (1);
  if (d1[0] != ';' && d2[0] == ';')
    return (0);
  if (d1[1] == '|' || d1[1] == '&' && d2[1] == '|' || d2[1] == '&')
    return (0);
  if (d1[0] == '|' && d1[1] == 0 && (d2[0] == '<' || d2[0] == '>'))
    return (1);
  if (d1[0] == '|' && d1[1] == 0 && d2[0] == '|' && d2[1] == 0)
    return (1);
  if (d1[0] == '|' && d1[1] == 0 && (d2[0] != '|' || d2[1] == '|'))
    return (0);
  return (1);
}
