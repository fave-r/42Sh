/*
** cd_next.c for 42sh in /home/blackbird/work/42Sh/built-ins
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun May 25 07:13:05 2014 romaric
** Last update Sun May 25 07:20:00 2014 romaric
*/

#include "my.h"

int	my_cd_next(char *arg)
{
  if (strcmp(arg, "..") == 0)
    {
      chdir("..");
      return (1);
    }
  return (0);
}
