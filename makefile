##
## EPITECH PROJECT, 2019
## makefile 
## File description:
## test2
##

SRC 	=	my_hunter-h.c 	\
			my_hunter.c \
			int_to_str.c 	\
			my_revstr.c 	\
			my_strlen.c 	\
			my_putstr.c 	\
			my_putchar.c 	\
			my_hunter-play.c

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	
		    gcc $(SRC) -l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio
			mv a.out my_hunter
clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)
	
re:	fclean all
