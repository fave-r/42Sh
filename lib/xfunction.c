/*
** xfunction.c for xfunction in /home/alex-odet/work/42Sh/lib
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Thu Apr  3 13:47:46 2014 alex-odet
** Last update Wed May 21 14:44:52 2014 lhomme
*/

#include "my.h"

void	*xmalloc(size_t n)
{
  void	*p;

  p = malloc(n);
  if (p == NULL)
    my_putstr("Malloc failed.\n", 2);
  return (p);
}
