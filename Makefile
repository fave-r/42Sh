##
## Makefile for Makefile in /home/alex-odet/work/42Sh
##
## Made by alex-odet
## Login   <alex-odet@epitech.net>
##
## Started on  Tue Apr 15 17:06:27 2014 alex-odet
## Last update Thu May 22 13:20:54 2014 odet
##

CC=		gcc

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I.

NAME=		42sh

SRCS=		main.c \
		display.c \
		lib/xfunction.c \
		lib/basic.c \
		lib/my_epur_str.c \
		lib/my_strcat.c \
		lib/my_getnbr.c\
		list/my_token_list.c \
		lexing/lexer.c \
		lexing/lexer_fct.c \
		built-ins/my_cd.c \
		built-ins/my_cd_func.c \
		built-ins/my_env_list.c \
		built-ins/my_env.c \
		built-ins/my_setenv.c \
		built-ins/my_unsetenv.c \
		built-ins/my_echo.c \
		built-ins/my_echo_arg.c \
		built-ins/echo_vh.c \
		termcap/main.c \
		termcap/init.c \
		termcap/unset.c \
		npi/npi.c \
		npi/list_func.c \
		npi/tree_func.c \
		npi/make_tree.c \
		npi/priority.c \
		npi/check_full_tree.c \
		eval/my_str_to_wordtab.c \
		eval/env.c \
		eval/check.c \
		eval/char.c \
		eval/xfunction.c \
		eval/mys.c \
		eval/check_next.c \
		eval/get_next_line.c \
		eval/exec.c \
		auto_completion/main.c

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -lncurses

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all fclean re
