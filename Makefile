##
## Makefile for Makefile in /home/alex-odet/work/42Sh
##
## Made by alex-odet
## Login   <alex-odet@epitech.net>
##
## Started on  Mon Mar 10 14:33:31 2014 alex-odet
## Last update Mon Mar 17 10:44:09 2014 alex-odet
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wextra -Wall -ggdb3 -g3 -I.

NAME=		42sh

SRCS=		main.c \
		lib/basic.c \
		Lexer/lexer.c \
		Lexer/get_char.c

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