##
## Makefile for gnltermcap in /home/blackbird/work/42Sh/termcap
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Tue May 20 10:48:11 2014 romaric
## Last update Tue May 20 10:49:13 2014 romaric
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3

NAME=		gnltermcap

SRCS=		main.c

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
