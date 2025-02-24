NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
PRINTF = ft_printf/printf

SRC = src/main.c \
	  src/move_stack/push.c src/move_stack/reverse_rotate.c src/move_stack/rotate.c src/move_stack/swap.c \

UTILS = utils/print_stack.c utils/free_stack.c utils/ft_lstnew.c utils/add_stack.c utils/ft_lstsize.c

VERIF = verif/ft_isdigit.c verif/ft_atol.c verif/ft_split.c verif/ft_is_duplicate.c verif/verif_args.c

OBJ = $(SRC:.c=.o) $(UTILS:.c=.o) $(VERIF:.c=.o)

all : $(PRINTF) $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) $(PRINTF) -o $@

$(PRINTF) :
	make -C ft_printf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

debug:
	$(CC) $(SRC) $(UTILS) $(VERIF) $(PRINTF) -o debug -g3

clean :
	rm -rf $(OBJ) $(DIR_UTILS)
	make clean -C ft_printf

fclean : clean
	rm -f $(NAME)
	make fclean -C ft_printf

re : fclean all 

.PHONY : all clean fclean re
