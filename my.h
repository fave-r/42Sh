/*
** my.h for my.h in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Tue Apr 15 17:07:43 2014 alex-odet
** Last update Sun May 11 19:16:52 2014 romaric
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
  int   nbwords;
  int   i;
  char  **strpar;
  char  *ptr;
}			t_word;

int	print_token(t_token *list);
t_token	*add_token(t_token *list, char *token);
char	*my_strxdup(char *source, int len);
int	get_operator(char *str, int i, int save[2]);
int	get_other(char *str, int i, int save[2]);
t_token	*fill_token(char *str);
int	fill_type(t_token *list);
t_token	*fill_list_token(char *str);
int	is_alpha(char c);
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
int	my_echo_arg(char*);
t_hist  *my_history(t_hist *history, char *str);
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
int     check_fn(t_tree *tree, int in, int out);
int     my_strlen_n(char *str);
char    **my_str_to_wordtab(char *str, char sep);
char    **save_env(void);
int     checkenv(char **env);
char    **envcy(char **env);
int      checkpath(char **env);
char    *pathcpy(char **env, int i);
char    *rmpath(char *dest, char * src);
char    *my_strcpy(char *dest, char *src);
void    free_doble(char **kill);
int     my_semi_col(t_tree *tree, int in, int out);
int     my_and(t_tree *tree, int in, int out);
int     my_or(t_tree *tree, int in, int out);
int     redir_right(t_tree *tree, int in, int out);
int     doble_right(t_tree *tree, int in, int out);
int     redir_left(t_tree *tree, int in, int out);
int     xopen(const char *pathname, int flags, mode_t mode);
ssize_t xread(int fd, void *buf, size_t count);

#endif
