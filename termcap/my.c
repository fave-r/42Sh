/*
** my.c for my in /home/odet/work/42Sh/termcap
** 
** Made by odet
** Login   <odet@epitech.net>
** 
** Started on  Thu May 22 14:57:51 2014 odet
** Last update Thu May 22 15:18:47 2014 odet
*/

#include "my.h"
#include "struct.h"

char		*my_tab(char *tmp, char *new, char *result, int *x)
{

  tmp[*x] = 0;
  new = dup_last_word(tmp);
  if ((result = auto_completion(new)) != NULL)
    {
      if (result != NULL)
	*x += write(1, result, strlen(result));
      else if (*x > 0)
	*x = *x - 1;
      tmp = strcat(tmp, result);
      free(result);
      free(new);
    }
  if (result == NULL)
    {
      if ((tmp = glob_complete(new, tmp)))
	*x += write(1, tmp, strlen(tmp));
    }
  return (tmp);
}

char		*my_entry(char *tmp, char *new, char *result, int *x)
{
  (void)result;
  tmp[*x] = 0;
  *x = 0;
  new = my_dupstr(tmp, 1024);
  bzero(tmp, 1024);
  write(1, "\n", 1);
  return (new);
}

int		my_char(char *tmp, char to_copy, int *x)
{
  int	a;

  a = *x;
  write(1, &to_copy, 1);
  tmp[a] = to_copy;
  a++;
  return (a);
}

void		my_delete(char *tmp, int *x)
{
  tmp[*x] = '\b';
  if (*x == 0)
    write(1, "\a", 1);
  else
    write(1, "\b \b", 3);
  if (*x > 0)
    *x -= 1;
}
