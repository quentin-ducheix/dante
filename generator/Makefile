##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	generator

RM	=	rm -f

SRCS	= 	main.c		\
		generator.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
		gcc $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
