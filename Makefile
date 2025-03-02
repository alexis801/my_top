##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME	=	my_top

CC	=	gcc

SRC	=	main.c				\
		SRC/my_top.c			\
		SRC/task.c			\
		SRC/memory/mem_info.c		\
		SRC/memory/mem_swap.c

OBJ     =       $(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -pedantic

CPPFLAGS	+=	-iquote include

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L./../lib/my/ -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re $(NAME) \
