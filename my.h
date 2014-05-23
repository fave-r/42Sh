/*
** my.h for my.h in /home/alex-odet/work/42Sh
**
** Made by alex-odet
** Login   <alex-odet@epitech.net>
**
** Started on  Tue Apr 15 17:07:43 2014 alex-odet
** Last update Fri May 23 18:21:30 2014 bourrel
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
#include <errno.h>

#define BUFF_SIZE 1024
#define TERM "xterm"
#define PATH "/usr/lib64/mpi/gcc/openmpi/bin:/home/leo/bin:/usr/local/bin:/usr/bin:/bin:/usr/bin/X11:/usr/X11R6/bin:/usr/games:/usr/netsoul/sbin:/usr/netsoul/bin:/usr/kerberos/sbin:/usr/kerberos/bin:/usr/arla/sbin:/usr/arla/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/site/sbin:/usr/site/bin:/usr/netsoul/sbin:/usr/netsoul/bin:/usr/kerberos/sbin:/usr/kerberos/bin:/usr/arla/sbin:/usr/arla/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/site/sbin:/usr/site/bin"

typedef struct		s_env
{
  char			*str;
  struct s_env		*prev;
  struct s_env		*next;
}			t_env;

typedef struct		s_env_var
{
  t_env			*env;
  int			wat;
  int			var_close;
}			t_env_var;

typedef struct		s_lft
{
  int			ret;
  int			fd;
  int			i;
  char			*str;
}			t_lft;

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

typedef struct		s_tree
{
  void			*data;
  struct s_tree		*left;
  struct s_tree		*right;
}			t_tree;

typedef struct		s_list
{
  void			*data;
  t_tree		*tree;
  struct s_list		*next;
}			t_list;

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
  int			wat;
  int			var_close;
}			t_inp;

typedef struct		s_gnl_icanon
{
  char			buffer[BUFF_SIZE];
  int			x;
  char			*tmp;
  char			*result;
  char			*new;
}			t_gnl_icanon;

typedef struct		s_arbre
{
  char			c;
  struct s_arbre	*next;
  struct s_arbre	*deep;
}			t_arbre;

typedef struct		s_npi
{
  t_list		*stack;
  t_list		*output;
  t_tree		*tree;
}			t_npi;

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
int	my_oldpwd(t_env*);
int     my_strcmp(char*, char*);
int	my_strlen(char *str);
int     my_strncmp(char*, char*, int);
char    *my_strcat(char*, char*);
char    *my_strdup(char*);
char    *my_strndup(char*, int);
char    *my_strcpy(char*, char*);
void	my_putchar(char c, int fd);
int	my_putstr(char *str, int fd);
t_env   *my_env_inlist(char **);
void    my_print_envlist(t_env *, int);
t_env   *my_unsetenv(t_env*, char**);
t_env   *my_setenv(t_env*, char**);
t_env   *my_add_env(t_env*, char*);
t_env	*my_env(t_env*, char**, int);
void	my_echo(char**, int);
int	my_echo_arg(char*, int);
t_env	*my_history(t_env *history, char *str);
char    *my_epur_str(char *str);
int     is_spe(char c);
int     is_alpha(char c);
t_tree	*npi(t_token *token, char *str, t_env *env);
t_tree  *createNode(t_tree *elem, void *data);
int     npi_add_end(t_list **list, void *data);
int     npi_add_top(t_list **list, void *data, t_tree *tree);
int     npi_delete_top(t_list **list);
int     npi_delete_last(t_list **list);
int     my_priority(char *d1, char *d2);
int     check_full_tree(t_tree *tree);
void    aff(t_tree *tree, int pos);
void    addNode(t_tree **tree, void *data, int pos);
void    make_tree(t_list **output, void *op);
int     check_fn(t_tree *tree, int in, int out, t_env_var *env);
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
int     my_semi_col(t_tree *tree, int in, int out, t_env_var *env);
int     my_and(t_tree *tree, int in, int out, t_env_var *env);
int     my_or(t_tree *tree, int in, int out, t_env_var *env);
int     redir_right(t_tree *tree, int in, int out, t_env_var *env);
int     doble_right(t_tree *tree, int in, int out, t_env_var *env);
int     redir_left(t_tree *tree, int in, int out, t_env_var *env);
int     xopen(const char *pathname, int flags, mode_t mode);
ssize_t xread(int fd, void *buf, size_t count);
char    *my_strcpyfinal(char *dest, char *cmd);
void    free_tree(t_tree *tree);
void    delete_list(t_token **list);
void    npi_delete_list(t_list **list);
void	my_delete_envlist(t_env **list);
char	*my_strcat(char *dest, char *src);
t_env	*my_swap_old(t_env *env);
void	change_oldpwd(t_env *env, char *pwd);
int	doble_left(t_tree *tree, int in, int out, t_env_var *env);
char	*get_next_line(const int fd);
char	*my_strdup_new(char *src);
int	my_pipe(t_tree *tree, int in, int out, t_env_var *env);
int     my_exec(char *cmd, int in, int out, t_env_var *env);
int     my_getnbr(char*);
int     check_path(char **pathsep, char *cmd, char **str, t_inp p);
void	echo_vh(char **cmd, int fd);
char	*my_tab(char *tmp, char *new, char *result, int *x);
char	*my_entry(char *tmp, char *new, char *result, int *x);
void	my_delete(char *tmp, int *x);
char	*get_next_line_icanon(const int fd);
void	init();
int	xtgetent(const char *name);
char	*my_dupstr(char *src, int len);
char	*dup_last_word(char *src);
void	init_value(t_gnl_icanon *ptr);
t_arbre	*make_root(void);
t_arbre	*add_char(char c);
t_arbre	*creat_word(char *str);
int	add_word(t_arbre *arbre, char *str);
int	go_to(t_arbre *arbre, char *str, t_arbre **ret);
int	calc_len(t_arbre *cur);
char	*run_auto_completion(t_arbre *arbre, char *str);
int	fill_tree_bin(char **path, t_arbre *arbre);
char	*auto_completion(char *test);
void	display_prompt(t_env *env);
void	display_sigint();
void	unset_term();
t_token	*check_exotic(t_token *token);
t_token *check_varenv(t_token *list, t_env *env);
int	my_char(char *tmp, char to_copy, int *x);
char	*glob_complete(char *new, char *tmp);
void	doble_left_next(int *i, int *ret, int *fd);

#endif
