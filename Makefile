##
## Makefile for Makefile in /home/alex-odet/work/42Sh
## 
## Made by alex-odet
## Login   <alex-odet@epitech.net>
## 
## Started on  Fri Mar 28 09:53:49 2014 alex-odet
## Last update Thu Apr  3 14:07:53 2014 alex-odet
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I.

NAME=		42sh

SRCS=		main.c \
		lib/xfunction.c \
		lib/get_next_line.c \
		lib/basic.c \
		List/my_put_in_list.c \
		Lexing/lexer.c

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