/*
** my_echo_arg.c for 42Sh in /home/leo/rendu/42Sh/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Fri Apr 25 15:26:05 2014 bourrel
** Last update Fri May 16 15:27:52 2014 bourrel
*/

#include "my.h"

int     convert_base(char *nbr, int base)
{
  int   len;
  int   result;
  int   rank;

  len = strlen(nbr) - 1;
  rank = 1;
  result = 0;
  while (len >= 0)
    {
      result = result + ((nbr[len] - 48) * rank);
      rank = rank * base;
      len = len - 1;
    }
  return (result);
}

int	convert_hex(char *str, int i, int fd)
{
  char	*cpy;
  int	j;

  j = 0;
  i++;
  cpy = malloc(sizeof(*cpy) * 4);
  while (j < 2 && (str[i] >= '0' && str[i] <= '9'))
    {
      cpy[j] = str[i];
      j++;
      i++;
    }
  cpy[j] = '\0';
  my_putchar(convert_base(cpy, 16), fd);
  free(cpy);
  return (i);
}

int     convert_octal(char *str, int i, int fd)
{
  char  *cpy;
  int   j;

  j = 0;
  i++;
  cpy = malloc(sizeof(*cpy) * 4);
  while (j < 3 && (str[i] >= '0' && str[i] <= '9'))
    {
      cpy[j] = str[i];
      j++;
      i++;
    }
  cpy[j] = '\0';
  my_putchar(convert_base(cpy, 8), fd);
  free(cpy);
  return (i);
}

int	check_args(char *str, int i, int fd)
{
  if (str[i] == 'b')
    my_putstr("\b", fd);
  else if (str[i] == 'e')
    i += 2;
  else if (str[i] == 'n')
    my_putstr("\n", fd);
  else if (str[i] == 'r')
    my_putstr("\r", fd);
  else if (str[i] == 't')
    my_putstr("\t", fd);
  else if (str[i] == 'v' || str[i] == 'f')
    my_putstr("\v", fd);
  else if (str[i] == '\\')
    my_putstr("\\", fd);
  else if (str[i] == 'x')
    i = convert_hex(str, i, fd) - 1;
  else if (str[i] == '0')
    i = convert_octal(str, i, fd) - 1;
  else
    my_putstr(&str[i], fd);
  return (i);
}

int	my_echo_arg(char *str, int fd)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\\' && str[i + 1] == 'a')
        i += 2;
      else if (str[i] == '\\' && str[i + 1] == 'c')
	return (1);
      else if (str[i] == '\\')
	i = check_args(str, i + 1, fd);
      else
	my_putchar(str[i], fd);
      i++;
    }
  return (1);
}
