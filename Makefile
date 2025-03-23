NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
PRINTF = ft_printf/printf

SRC = src/main.c \
      src/move_stack/push.c src/move_stack/reverse_rotate.c src/move_stack/rotate.c src/move_stack/swap.c \

UTILS = utils/utils_print.c utils/free_stack.c utils/add_stack.c utils/index_stack.c

VERIF = verif/utils_verif.c verif/verif_args.c verif/ft_split.c

ALGO = algorithmes/sort.c algorithmes/sort_utils.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o) $(UTILS:%.c=$(OBJ_DIR)/%.o) $(VERIF:%.c=$(OBJ_DIR)/%.o) $(ALGO:%.c=$(OBJ_DIR)/%.o)

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
CYAN = \033[36m

all: $(OBJ_DIR) $(PRINTF) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src/move_stack $(OBJ_DIR)/utils $(OBJ_DIR)/verif $(OBJ_DIR)/algorithmes
	@echo "$(BLUE)📁 Création du dossier objet...$(RESET)"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(PRINTF) -o $@
	@echo "$(GREEN)✅ Compilation terminée : $(NAME) généré !$(RESET)"

$(PRINTF):
	@echo "$(CYAN) Compilation de ft_printf...$(RESET)"
	@make -C ft_printf

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW) Compilation : $<$(RESET)"

debug: $(OBJ)
	@$(CC) $(OBJ) $(PRINTF) -o debug -g3
	@echo "$(GREEN) Compilation en mode debug terminée !$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ft_printf
	@echo "$(RED) Suppression des fichiers objets...$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ft_printf
	@echo "$(RED) Suppression de l'exécutable $(NAME)...$(RESET)"

re: fclean all

.PHONY: all clean fclean re

