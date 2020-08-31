##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## t1
##

SRC		=	main.c	\
			solve.c	\
			make_map.c	\
			str_to_word_array.c	\
			manage_path.c	\
			modify_map.c	\

OBJ		=	$(SRC.c=.o)

CFLAGS  =	-W -Wall -I./include/

NAME    =   solver

all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(CFLAGS) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all
