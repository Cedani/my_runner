##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

LIBMY 	=		./lib/my/linked_list_library.c	\
				./lib/my/my_str_to_word_array.c	\
				./lib/my/my_strlen.c			\
				./lib/my/my_revstr.c

CRE_OBJ = 		./lib/creating_object/create_object.c	\
				./lib/creating_object/init_rect_sprite.c 	\
				./lib/creating_object/loading_map.c			\
				./lib/creating_object/menu.c				\
				./lib/creating_object/init_window.c

MOV_FUN =		./lib/moving_functions/manage_window.c 	\
				./lib/moving_functions/run.c			\
				./lib/moving_functions/collision.c		\
				./lib/moving_functions/score.c			\
				./lib/moving_functions/ending.c

MAIN 	=		main.c

SFML_FLAG	=		-lcsfml-window -lcsfml-graphics -lcsfml-audio -lcsfml-system

C_FLAG	=		-lm -g3

CC 		=		gcc

SRC		=		$(LIBMY)	\
				$(CRE_OBJ)	\
				$(MOV_FUN)	\
				$(MAIN)

NAME	=		my_runner

all:
		$(CC) $(SFML_FLAG) $(C_FLAG) $(SRC) -o $(NAME)

clean:
		rm -rf *.o

fclean: clean
		rm -f $(NAME)

re:	fclean all
