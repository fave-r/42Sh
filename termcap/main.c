/*
** main.c for main in /home/odet_a/work/42Sh/termcap
** 
** Made by 
** Login   <odet_a@epitech.net>
** 
** Started on  Mon May 19 22:57:58 2014 
** Last update Sat May 24 10:46:41 2014 odet
*/

#include "my.h"
#include "struct.h"

int		my_len(char **array)
{
  int		i;

  i = 0;
  while (array != NULL && array[i])
    i++;
  return (i);
}

void		my_display(char **array, char *tmp, t_env_var *env)
{
  int		i;

  i = 0;
  write(1, "\n", 1);
  while (array != NULL && array[i])
    {
      write(1, array[i], strlen(array[i]));
      write(1, "\t", 1);
      i++;
    }
  write(1, "\b \b\n", 4);
  display_prompt(env->env);
  write(1, tmp, strlen(tmp));
}

char		*glob_complete(char *new, char *tmp, t_env_var *env)
{
  glob_t	ptr;

  if ((tmp && new) && (!tmp[0] && !new[0]))
    return (tmp);
  if (new[strlen(new) - 1] != '*' && new[strlen(new) - 1] != ' ')
    new = my_strcat(new, "*");
  if ((glob(new, GLOB_BRACE | GLOB_TILDE, NULL, &ptr))
      != GLOB_NOMATCH)
    {
      if (my_len(ptr.gl_pathv) == 1)
	return (ptr.gl_pathv[0]);
      else
	my_display(ptr.gl_pathv, tmp, env);
    }
  return (tmp);
}

char		*get_next_line_icanon(const int fd, t_env_var env)
{
  t_gnl_icanon	p;
  char		*save;

  init_value(&p, env);
  save = "";
  while ((read(fd, p.buffer, BUFF_SIZE)))
    {
      if (p.buffer[0] == '\t')
	{
	  if (strcmp(save, p.tmp) != 0)
	    p.tmp = my_tab(&p, NULL, NULL, &env);
	  save = p.tmp;
	}
      else if (p.buffer[0] >= 32 && p.buffer[0] < 127)
	p.x = my_char(p.tmp, p.buffer[0], &(p.x));
      else if (p.buffer[0] == '\n')
	return (p.new = my_entry(p.tmp, NULL, NULL, &(p.x)));
      else if (p.buffer[0] == 127)
	my_delete(p.tmp, &(p.x));
      else if (p.buffer[0] == 4)
	return (NULL);
      else if (p.buffer[0] == 12)
	return (strdup("clear"));
      bzero(p.buffer, 1024);
    }
  return (NULL);
}
