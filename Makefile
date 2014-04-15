##
## Makefile for Makefile in /home/alex-odet/work/42Sh
## 
## Made by alex-odet
## Login   <alex-odet@epitech.net>
## 
## Started on  Tue Apr 15 17:06:27 2014 alex-odet
## Last update Tue Apr 15 17:06:41 2014 alex-odet
##


CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I.

NAME=		42sh

SRCS=		main.c \
		lib/xfunction.c \
		lib/get_next_line.c \
		lib/basic.c \
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
