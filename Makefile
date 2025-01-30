NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g

DIR_SRC = src
DIR_INC = include
DIR_UTILS = utils

SRC =

OBJ = $(SRC:.c=.o)

all : $(LIBFT) $(NAME)

clean :
	rm -rf ()
	make clean libft

fclean : clean
	rm -f $(NAME)
	make fclean libft

re : fclean all 

.PHONY : all clean fclean re

