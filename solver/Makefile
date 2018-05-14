##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	solver

all:	$(OBJ)
	gcc -Werror -Wextra -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
