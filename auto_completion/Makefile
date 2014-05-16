##
## Makefile for Makefile in /home/thibaud/rendu/Piscine-C-lib/my
## 
## Made by thibaud
## Login   <thibaud@epitech.net>
## 
## Started on  Mon Oct 21 09:07:38 2013 thibaud
## Last update Sun Apr 13 01:59:40 2014 thibaud
##

RM	= rm -f

RMO	= rm *.o

CC	= gcc -W -Wall -Werror

NAME	= test

SRCS	= main.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME) :	$(OBJS)
	$(CC) -o $(NAME) $(SRCS)
	$(RMO)

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) *~

re: fclean all
