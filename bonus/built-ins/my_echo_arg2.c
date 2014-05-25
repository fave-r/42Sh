/*
** my_echo_arg2.c for 42sh in /home/leo/rendu/42Sh/bonus/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Sun May 25 20:26:25 2014 bourrel
** Last update Sun May 25 20:26:43 2014 bourrel
*/

#include "my.h"

void	unknown_arg(char *text, char *arg, int i, int fd)
{
  while (arg[i] != '\0')
    {
      print_echo_str(&arg[i], fd);
      i++;
    }
  my_putchar(' ', fd);
  print_echo_str(text, fd);
}

int	check_invalid_arg(char *arg, char *text, int fd)
{
  int	i;

  i = 0;
  while (arg[i] != '\0')
    {
      if (arg[i] != 'e' || arg[i] != 'E' || arg[i] != 'n' || arg[i] != '-')
        {
          print_echo_str(arg, fd);
          if (text)
            print_echo_str(text, fd);
          return (0);
        }
      i++;
    }
  return (1);
}
