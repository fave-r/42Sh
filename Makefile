##
## Makefile for Makefile in /home/alex-odet/work/42Sh
## 
## Made by alex-odet
## Login   <alex-odet@epitech.net>
## 
## Started on  Mon Mar 10 14:33:31 2014 alex-odet
## Last update Mon Mar 10 14:34:48 2014 alex-odet
##

NAME=	42sh

SRC=	main.c

CC=	gcc -W -Wall -I.

RM=	rm -f

T=	*~

all:
	$(CC) -o $(NAME) $(SRC)

clean:
	$(RM) $(T)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all