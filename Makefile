# Variables
SRCS        =   src/close.c     \
				src/color.c	    \
                src/draw.c      \
				src/error.c     \
				src/init.c      \
				src/init_utils.c\
				src/isometrie.c \
				src/key_handle.c\
				src/main.c      \
				src/menu.c      \
                src/read.c      \
				src/render.c    \
				src/rotate.c    \
				src/transform.c \
				src/atoi_base.c \
				src/utils.c

OBJ_DIR     =   obj
OBJS        =   $(SRCS:src/%.c=$(OBJ_DIR)/%.o)

HEADERS     =   includes/fdf.h     

NAME        =   fdf

CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror -g -I./libft/srcs -Iincludes
FLAGS       =   -lm -L./minilibx-linux -lmlx -L./libft -lft -lXext -lX11

# Commandes colorées et décoratives
GREEN       =   \033[1;32m
CYAN        =   \033[1;36m
RESET       =   \033[0m
SMILEY      =   😊

# Règle pour générer chaque fichier .o dans obj/
$(OBJ_DIR)/%.o: src/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@echo "$(CYAN)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Cible principale
all: libft mlx $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@echo "$(CYAN)Linking...$(RESET)"
	@$(CC) $(OBJS) -o $(NAME) $(FLAGS)
	@echo "$(GREEN)Executable $(NAME) created! $(SMILEY)$(RESET)"

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJ_DIR)
	@make -s clean -C libft
	@make -s clean -C minilibx-linux >/dev/null 2>&1
	@echo "$(CYAN)Object files cleaned!$(RESET)"

# Nettoyage complet
fclean: clean
	@rm -rf $(NAME)
	@make -s fclean -C libft
	@echo "$(CYAN)Executable $(NAME) removed!$(RESET)"

# Recompiler à partir de zéro
re: fclean all

# Génération de la bibliothèque libft avec sortie masquée
libft:
	@make -s -C libft

# Génération de la bibliothèque minilibx avec sortie masquée
mlx:
	@echo "$(CYAN)Building minilibx-linux...$(RESET)"
	@make -s -C minilibx-linux all >/dev/null 2>&1
	@echo "$(GREEN)Minilibx built successfully!$(RESET)"

# Éviter les conflits avec des fichiers portant les noms des cibles
.PHONY: all clean fclean re libft mlx
