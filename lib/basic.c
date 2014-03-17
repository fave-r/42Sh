/*
** basic.c for basic in /home/alex-odet/work/42Sh/lib
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Mon Mar 17 10:42:37 2014 alex-odet
** Last update Mon Mar 17 10:43:51 2014 alex-odet
*/

#include "struct.h"

int	my_putstr(char *str, int fd)
{
  return(write(fd, str, strlen(str)));
}
