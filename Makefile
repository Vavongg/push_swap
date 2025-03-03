NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
PRINTF = ft_printf/printf

SRC = src/main.c \
      src/move_stack/push.c src/move_stack/reverse_rotate.c src/move_stack/rotate.c src/move_stack/swap.c \

UTILS = utils/utils_print.c utils/free_stack.c utils/add_stack.c utils/index_stack.c

VERIF = verif/utils_verif.c verif/verif_args.c verif/ft_split.c
OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o) $(UTILS:%.c=$(OBJ_DIR)/%.o) $(VERIF:%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(PRINTF) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/src/move_stack $(OBJ_DIR)/utils $(OBJ_DIR)/verif

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(PRINTF) -o $@

$(PRINTF):
	make -C ft_printf

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

debug: $(OBJ)
	$(CC) $(OBJ) $(PRINTF) -o debug -g3

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	make fclean -C ft_printf

re: fclean all

.PHONY: all clean fclean re
