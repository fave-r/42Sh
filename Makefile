##
## Makefile for Makefile in /home/alex-odet/work/42Sh
##
## Made by alex-odet
## Login   <alex-odet@epitech.net>
##
## Started on  Tue Apr 15 17:06:27 2014 alex-odet
## Last update Mon May 12 11:40:20 2014 romaric
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I.

NAME=		42sh

SRCS=		main.c \
		lib/xfunction.c \
		lib/get_next_line.c \
		lib/basic.c \
		lib/my_epur_str.c \
		list/my_token_list.c \
		lexing/lexer.c \
		lexing/lexer_fct.c \
		my_auto_complete.c \
		built-ins/my_cd.c \
		built-ins/my_cd_func.c \
		built-ins/my_env_list.c \
		built-ins/my_env.c \
		built-ins/my_setenv.c \
		built-ins/my_unsetenv.c \
		built-ins/my_echo.c \
		built-ins/my_echo_arg.c \
		npi/npi.c \
		npi/list_func.c \
		npi/tree_func.c \
		npi/make_tree.c \
		npi/priority.c \
		eval/my_str_to_wordtab.c \
		eval/env.c \
		eval/check.c \
		eval/char.c \
		eval/xfunction.c \
		eval/mys.c

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)


clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all fclean re
