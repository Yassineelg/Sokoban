##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	find_and_check.c	\
		in_game.c	\
		cheats.c	\
		main.c

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):
	make re -C lib/my
	gcc -L. -lmy -lncurses $(SRC) -o $(NAME)

clean:
	rm -rf *~ \#*\# .\#*

fclean:
	rm -f $(NAME)

re:	fclean all clean