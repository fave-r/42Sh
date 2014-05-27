##
## Makefile for Makefile in /home/alex-odet/work/42Sh
##
## Made by alex-odet
## Login   <alex-odet@epitech.net>
##
## Started on  Tue Apr 15 17:06:27 2014 alex-odet
## Last update Tue May 27 13:23:47 2014 romaric
##

CC=		gcc

RM=		rm -f

INCLUDES=	-I.

CFLAGS=		-Wall -Wextra -Werror -I.

NAME=		42sh

SRCS=		main.c \
		display.c \
		my_get_line.c \
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
		built-ins/my_echo_arg_next.c \
		built-ins/echo_vh.c \
		built-ins/cd_next.c \
		npi/npi.c \
		npi/list_func.c \
		npi/tree_func.c \
		npi/make_tree.c \
		npi/priority.c \
		npi/check_full_tree.c \
		npi/check_exotic.c \
		npi/check_varenv.c \
		npi/delete_varenv.c \
		eval/my_str_to_wordtab.c \
		eval/env.c \
		eval/check.c \
		eval/char.c \
		eval/xfunction.c \
		eval/mys.c \
		eval/check_next.c \
		eval/exec.c \
		eval/mys_next.c

OBJS=		$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		@echo "[Building] " | tr -d '\n'
		$(CC) -o $@ $(OBJS) $(CFLAGS) -lncurses

%.o:		%.c
		@echo "[Doing object] " | tr -d '\n'
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<
clean:
		@echo "[Cleaning] " | tr -d '\n'
		$(RM) $(OBJS)

fclean:		clean
		@echo "[File cleaning] " | tr -d '\n'
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all fclean re
