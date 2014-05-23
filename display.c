/*
** display.c for 42sh in /home/leo/rendu/42Sh
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Thu May 22 11:49:29 2014 bourrel
** Last update Fri May 23 04:47:20 2014 odet
*/

#include "my.h"

void            display_prompt()
{
  write(1, "$> ", 3);
}

void            display_sigint()
{
  write(1, "^C\n", 3);
}
