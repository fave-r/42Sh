/*
** my.h for my.h in /home/alex-odet/work/42Sh
** 
** Made by alex-odet
** Login   <alex-odet@epitech.net>
** 
** Started on  Tue Apr 15 17:07:43 2014 alex-odet
** Last update Tue May  6 18:01:46 2014 lhomme
*/

#ifndef __42Sh__
#define __42Sh__

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <glob.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF_SIZE 1024

typedef struct		s_hist
{
  char			*cmd;
  struct s_hist		*next;
}			t_hist;

typedef struct		s_env
{
  char			*str;
  struct s_env		*prev;
  struct s_env		*next;
}			t_env;

typedef struct		s_token
{
  char			*token;
  int			type;
  struct s_token	*next;
}			t_token;

typedef struct		s_get
{
  char			*s;
  int			c;
  int			l;
}			t_get;

int	print_token(t_token *list);
t_token	*add_token(t_token *list, char *token);
char	*my_strxdup(char *source, int len);
int	get_operator(char *str, int i, int save[2]);
int	get_other(char *str, int i, int save[2]);
t_token	*fill_token(char *str);
int	fill_type(t_token *list);
t_token	*fill_list_token(char *str);
int	my_putstr(char *str, int fd);
void	*xmalloc(size_t n);
void	display_prompt();
char	*get_next_line(const int fd);
int	my_strlen(char *str);
char	*my_auto_complete(char *path);
t_env	*my_cd(t_env*, char*);
t_env	*my_change_pwd(t_env*, char*, int);
t_env   *my_oldpwd(t_env*);
int     my_strcmp(char*, char*);
int     my_strncmp(char*, char*, int);
char    *my_strcat(char*, char*);
char    *my_strdup(char*);
char    *my_strndup(char*, int);
char    *my_strcpy(char*, char*);
t_env   *my_env_inlist(char **);
void    my_print_envlist(t_env *);
t_env   *my_unsetenv(t_env*, char*);
t_env   *my_setenv(t_env*, char**);
t_env   *my_add_env(t_env*, char*);
t_env	*my_env(t_env*, char*);
t_env	*my_echo(t_env*, char*);
t_hist  *my_history(t_hist *history, char *str);
int     my_put_nbr(int nb, int fd);

#endif
