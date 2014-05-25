/*
** my_clean_strlen.c for 42sh in /home/blackbird/work/42Sh/bonus
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Sun May 25 09:11:30 2014 romaric
** Last update Sun May 25 09:21:45 2014 romaric
*/

#include "my.h"

int	my_clean_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '-' && str[i] != ' ' && str[i] != '\0')
    i++;
  return (i);
}
