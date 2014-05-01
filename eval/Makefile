##
## Makefile for corewar in /home/blackbird/work/Corewar/asm
##
## Made by romaric
## Login   <fave_r@epitech.net>
##
## Started on  Mon Mar 24 12:19:30 2014 romaric
## Last update Wed Apr 30 20:23:04 2014 romaric
##

CC=		clang

RM=		rm -f

CFLAGS=		-Wall -Wextra -Werror -g3 -ggdb3

NAME=		eval

SRCS=		test.c \
		check.c \
		my_str_to_wordtab.c \
		env.c \
		char.c \
		xfunction.c

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
