/*
** my.h for my.h in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Tue Apr 15 17:07:43 2014 alex-odet
** Last update Fri May 16 11:23:44 2014 
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
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define BUFF_SIZE 1024

typedef struct		s_env
{
  char			*str;
  struct s_env		*prev;
  struct s_env		*next;
}			t_env;

typedef struct		s_token
{
  char			*token;
  struct s_token	*next;
}			t_token;

typedef struct		s_get
{
  char			*s;
  int			c;
  int			l;
}			t_get;

typedef struct          s_tree
{
  void                  *data;
  struct s_tree         *left;
  struct s_tree         *right;
}                       t_tree;

typedef struct          s_list
{
  void                  *data;
  t_tree                *tree;
  struct s_list         *next;
}                       t_list;

typedef struct		s_word
{
  int			nbwords;
  int			i;
  char			**strpar;
  char			*ptr;
}			t_word;

typedef struct		s_inp
{
  int			in;
  int			out;
}			t_inp;

int	print_token(t_token *list);
t_token	*add_token(t_token *list, char *token);
char	*my_strxdup(char *source, int len);
int	get_operator(char *str, int i, int save[2]);
int	get_other(char *str, int i, int save[2]);
t_token	*fill_token(char *str);
int	fill_type(t_token *list);
int	is_alpha(char c);
void	*xmalloc(size_t n);
char	*my_auto_complete(char *path);
int	my_cd(t_env*, char**);
t_env	*my_change_pwd(t_env*, char*, int);
t_env   *my_oldpwd(t_env*);
int     my_strcmp(char*, char*);
int     my_strncmp(char*, char*, int);
char    *my_strcat(char*, char*);
char    *my_strdup(char*);
char    *my_strndup(char*, int);
char    *my_strcpy(char*, char*);
int	my_putstr(char *str, int fd);
t_env   *my_env_inlist(char **);
void    my_print_envlist(t_env *);
t_env   *my_unsetenv(t_env*, char**);
t_env   *my_setenv(t_env*, char**);
t_env   *my_add_env(t_env*, char*);
t_env	*my_env(t_env*, char**);
void	my_echo(char**, int);
int	my_echo_arg(char*);
t_env	*my_history(t_env *history, char *str);
char    *my_epur_str(char *str);
int     is_spe(char c);
int     is_alpha(char c);
t_tree	*npi(t_token *token);
t_tree  *createNode(t_tree *elem, void *data);
int     npi_add_end(t_list **list, void *data);
int     npi_add_top(t_list **list, void *data, t_tree *tree);
int     npi_delete_top(t_list **list);
int     npi_delete_last(t_list **list);
int     my_priority(char *d1, char *d2);
void    aff(t_tree *tree, int pos);
void    addNode(t_tree **tree, void *data, int pos);
void    make_tree(t_list **output, void *op);
int     check_fn(t_tree *tree, int in, int out, t_env **env);
int     my_strlen_n(char *str);
char    **my_str_to_wordtab(char *str, char sep);
char    **save_env(t_env **env);
int     checkenv(char **env);
char    **envcy(char **env);
char	*checkpath(t_env **env);
char    *pathcpy(char *tmp);
char    *rmpath(char *dest, char * src);
char    *my_strcpy(char *dest, char *src);
void    free_doble(char **kill);
int     my_semi_col(t_tree *tree, int in, int out, t_env **env);
int     my_and(t_tree *tree, int in, int out, t_env **env);
int     my_or(t_tree *tree, int in, int out, t_env **env);
int     redir_right(t_tree *tree, int in, int out, t_env **env);
int     doble_right(t_tree *tree, int in, int out, t_env **env);
int     redir_left(t_tree *tree, int in, int out, t_env **env);
int     xopen(const char *pathname, int flags, mode_t mode);
ssize_t xread(int fd, void *buf, size_t count);
char    *my_strcpyfinal(char *dest, char *cmd);
void    free_tree(t_tree *tree);
void    delete_list(t_token **list);
void    npi_delete_list(t_list **list);
void    my_delete_envlist(t_env **list);

#endif
