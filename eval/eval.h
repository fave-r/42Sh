/*
** struct.h for 42sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri Apr 25 17:28:32 2014 romaric
** Last update Thu May  1 16:04:51 2014 romaric
*/

#ifndef __EVAL__
#define __EVAL__

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

typedef struct          s_tree
{
  void                  *data;
  struct s_tree         *left;
  struct s_tree         *right;
}                       t_tree;

typedef struct  s_word
{
  int   nbwords;
  int   i;
  char  **strpar;
  char  *ptr;
}               t_word;

void    aff(t_tree *tree, int pos);
t_tree  *createNode(t_tree *elem, void *data);
void    Node_add(t_tree *tmpTree, t_tree *elem, int pos);
void    addNode(t_tree **tree, void *data, int pos);
void    go_left(t_tree *tree);
void    check_fn(t_tree *tree);
void    *xmalloc(size_t n);
int     my_strlen_n(char *str);
char    **my_str_to_wordtab(char *str, char sep);
char    **save_env(void);
int     checkenv(char **env);
char    **envcy(char **env);
int      checkpath(char **env);
char    *pathcpy(char **env, int i);
char    *rmpath(char *dest, char * src);
char    *my_strcpy(char *dest, char *src);

#endif
