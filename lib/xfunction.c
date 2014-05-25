/*
** xfunction.c for xfunction in /home/alex-odet/work/42Sh/lib
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Thu Apr  3 13:47:46 2014 alex-odet
** Last update Sun May 25 21:50:45 2014 romaric
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
