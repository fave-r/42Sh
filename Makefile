##
## Makefile for Makefile in /home/alex-odet/work/42Sh
##
## Made by alex-odet
## Login   <alex-odet@epitech.net>
##
## Started on  Fri Mar 28 09:53:49 2014 alex-odet
## Last update Sun Apr  6 15:07:26 2014 romaric
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I.

NAME=		42sh

SRCS=		main.c \
		lib/xfunction.c \
		lib/get_next_line.c \
		lib/basic.c \
		list/my_put_in_list.c \
		lexing/lexer.c

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