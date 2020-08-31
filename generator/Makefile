##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Moi
##

SRC     =	main.c	\

NAME    =       generator

OBJ 	= 	$(SRC:.c=.o)

CFLAGS  =       -I../include -Wall -Wextra

all:    		$(NAME)

$(NAME):		$(OBJ)
				gcc -o $(NAME) $(OBJ) $(CFLAGS)

debug : 		clean
debug : 		CFLAGS += -g
debug : 		all


clean:
				rm -f *.o
				rm -f *~

fclean:
				make clean
				rm -f $(NAME)
				ls

re:				fclean all
