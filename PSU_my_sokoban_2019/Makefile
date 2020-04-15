##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for bistro
##

SRC 	=	main.c	\
		update_map.c	\
		manage_key.c	\
		end_condition.c	\
		error.c	\

OBJ 	= 	$(SRC:.c=.o)

NAME 	= 	my_sokoban

CFLAGS = -W -Wall -Wextra -lncurses -lmy -L./lib/my -I./include -g

all: 	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *~

fclean:	clean
	rm -f $(NAME)

re:	fclean all
