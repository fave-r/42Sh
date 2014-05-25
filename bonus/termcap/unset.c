/*
** unset.c for unset in /home/odet/work/42Sh/termcap
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Thu May 22 13:18:05 2014 odet
** Last update Sun May 25 16:01:10 2014 lhomme
*/

#include "my.h"
#include "struct.h"

void			unset_term()
{
  struct termios	p;

  tcgetattr(0, &p);
  p.c_lflag = (ICANON | ECHO);
  tcsetattr(0, 0, &p);
}
