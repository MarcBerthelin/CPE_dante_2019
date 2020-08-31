##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## t1
##

SRC		=	generator/main.c	\
			solver/main.c	\
			solver/manage_path.c	\
			solver/modify_map.c	\
			solver/str_to_word_array.c	\
			solver/make_map.c	\
			solver/solve.c

OBJ		=	$(SRC.c=.o)

all:
	make -C generator/
	make -C solver/

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf generator/generator
	rm -rf solver/solver

re:	fclean all
