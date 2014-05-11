/*
** my_echo_arg.c for 42Sh in /home/leo/rendu/42Sh/built-ins
** 
** Made by bourrel
** Login   <leo@epitech.net>
** 
** Started on  Fri Apr 25 15:26:05 2014 bourrel
** Last update Sun May 11 17:59:49 2014 romaric
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

int	convert_hex(char *str, int i)
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
  printf("%c", convert_base(cpy, 16));
  free (cpy);
  return (i);
}

int     convert_octal(char *str, int i)
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
  printf("%c", convert_base(cpy, 8));
  free (cpy);
  return (i);
}

int	check_args(char *str, int i)
{
  if (str[i] == 'b')
    printf("\b");
  else if (str[i] == 'e')
    i += 2;
  else if (str[i] == 'n')
    printf("\n");
  else if (str[i] == 'r')
    printf("\r");
  else if (str[i] == 't')
    printf("\t");
  else if (str[i] == 'v' || str[i] == 'f')
    printf("\v");
  else if (str[i] == '\\')
    printf("\\");
  else if (str[i] == 'x')
    i = convert_hex(str, i) - 1;
  else if (str[i] == '0')
    i = convert_octal(str, i) - 1;
  else
    printf("%c", str[i]);
  return (i);
}

int	my_echo_arg(char *str)
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
	i = check_args(str, i + 1);
      else
	printf("%c", str[i]);
      i++;
    }
  printf("\n");
  return (1);
}
