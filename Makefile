##
## Makefile for Makefile in /home/alex-odet/work/42Sh
##
## Made by alex-odet
## Login   <alex-odet@epitech.net>
##
## Started on  Mon Mar 10 14:33:31 2014 alex-odet
## Last update Sat Mar 15 11:51:55 2014 alex-odet
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wextra -Wall -ggdb3 -g3 -I.

NAME=		42sh

SRCS=		main.c \
		Lexer/lexer.c

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