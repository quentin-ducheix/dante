##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	generator/main.c	\
		generator/generator.c

OBJ	=	$(SRC:.c=.o)

NAME	=	./generator/generator

all:	$(OBJ)
	gcc -o $(NAME) $(SRC)
	make -C ./solver/
	cp solver/solver ./tournament
	cp generator/generator ./tournament

clean:
	rm -f $(OBJ)
	make clean -C ./solver/

fclean: clean
	rm -f $(NAME)
	make fclean -C ./solver/
	rm ./tournament/solver
	rm ./tournament/generator

re:	fclean all
