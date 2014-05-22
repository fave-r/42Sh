/*
** display.c for 42sh in /home/leo/rendu/42Sh
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Thu May 22 11:49:29 2014 bourrel
** Last update Thu May 22 11:49:53 2014 bourrel
*/

#include "my.h"

void            display_prompt()
{
  write(1, "$> ", 3);
}

void            display_sigint()
{
  write(1, "\n$> ", 4);
}
