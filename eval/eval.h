/*
** struct.h for 42sh in /home/blackbird/work/42Sh/eval
**
** Made by romaric
** Login   <fave_r@epitech.net>
**
** Started on  Fri Apr 25 17:28:32 2014 romaric
** Last update Tue Apr 29 12:44:05 2014 romaric
*/

#ifndef __EVAL__
#define __EVAL__

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct          s_tree
{
  void                  *data;
  struct s_tree         *left;
  struct s_tree         *right;
}                       t_tree;

void    aff(t_tree *tree, int pos);
t_tree  *createNode(t_tree *elem, void *data);
void    Node_add(t_tree *tmpTree, t_tree *elem, int pos);
void    addNode(t_tree **tree, void *data, int pos);
void    go_left(t_tree *tree);

#endif
