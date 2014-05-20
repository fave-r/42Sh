##
## Makefile for gnltermcap in /home/blackbird/work/42Sh/termcap
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Tue May 20 10:48:11 2014 romaric
## Last update Tue May 20 16:01:40 2014 odet
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -ggdb3 -g3 -I../auto_completion

NAME=		gnltermcap

SRCS=		main.c \
		init.c \
		../auto_completion/main.c \
		../auto_completion/my_str_to_wordtab.c

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
