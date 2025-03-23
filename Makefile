NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
PRINTF = ft_printf/printf

SRC = src/main.c \
      src/move_stack/push.c \
      src/move_stack/reverse_rotate.c \
      src/move_stack/rotate.c \
      src/move_stack/swap.c

UTILS = utils/utils_print.c \
        utils/free_stack.c \
        utils/add_stack.c \
        utils/index_stack.c

VERIF = verif/utils_verif.c \
        verif/verif_args.c \
        verif/ft_split.c

ALGO = algorithmes/sort.c \
       algorithmes/sort_utils.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o) \
      $(UTILS:%.c=$(OBJ_DIR)/%.o) \
      $(VERIF:%.c=$(OBJ_DIR)/%.o) \
      $(ALGO:%.c=$(OBJ_DIR)/%.o)

RESET = \033[0m
BOLD = \033[1m
GREEN = \033[32m
YELLOW = \033[33m
RED = \033[31m
CYAN = \033[36m
BLUE = \033[34m

all: $(OBJ_DIR) $(PRINTF) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)/src/move_stack $(OBJ_DIR)/utils $(OBJ_DIR)/verif $(OBJ_DIR)/algorithmes
	@echo "$(CYAN)───────────────────────────────$(RESET)"
	@echo "$(BOLD)📁 Création du dossier objet...$(RESET)"
	@echo "$(CYAN)───────────────────────────────$(RESET)"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(PRINTF) -o $@
	@echo "$(GREEN)✅ Compilation réussie !$(RESET)"
	@echo "$(CYAN)───────────────────────────────$(RESET)"

$(PRINTF):
	@echo "$(BLUE)⚙️  Compilation de ft_printf...$(RESET)"
	@$(MAKE) --no-print-directory -C ft_printf > /dev/null

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW)⚙️  Compilation : $<$(RESET)"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C ft_printf clean > /dev/null
	@echo "$(RED) Suppression des fichiers objets terminée.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C ft_printf fclean > /dev/null
	@echo "$(RED) Suppression de l'exécutable $(NAME).$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus

