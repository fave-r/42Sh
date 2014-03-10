/*
** struct.h for struct in /home/alex-odet/work/42Sh
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Mon Mar 10 14:29:30 2014 alex-odet
** Last update Mon Mar 10 14:33:19 2014 alex-odet
*/

#ifndef __42Sh__
#define __42Sh__

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct		s_btree
{
  struct s_btree	*left;
  struct s_btree	*right;
}			t_btree;

#endif
