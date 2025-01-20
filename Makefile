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
NAME_BONUS  =   fdf_bonus

CC          =   cc
CFLAGS      =   -Wall -Wextra -Werror -g -I./libft/srcs -Iincludes
FLAGS       =   -lm -L./minilibx-linux -lmlx -L./libft -lft -lXext -lX11

# Commandes colorées et décoratives
GREEN       =   \033[1;35m
CYAN        =   \033[1;34m
RESET       =   \033[0m
SMILEY      =   👍
SMILEY2	    =   😎

# Règle pour générer chaque fichier .o dans obj/
$(OBJ_DIR)/%.o: src/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cible principale
all: libft mlx $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@echo "$(CYAN)Linking...$(RESET)"
	@$(CC) $(OBJS) -o $(NAME) $(FLAGS)
	@echo "$(GREEN)Executable $(NAME) created! $(SMILEY2)$(RESET)"
	@echo "$(GREEN)Usage: ./fdf [map.fdf]$(RESET)"

# Cible bonus
bonus: libft mlx $(NAME_BONUS)

$(NAME_BONUS): $(OBJS) $(HEADERS)
	@echo "$(CYAN)Linking bonus...$(RESET)"
	@$(CC) $(OBJS) -o $(NAME_BONUS) $(FLAGS)
	@echo "$(GREEN)Executable $(NAME_BONUS) created! $(SMILEY2)$(RESET)"
	@echo "$(GREEN)Usage: ./fdf_bonus [map.fdf]$(RESET)"

# Nettoyage des fichiers objets
clean:
	@rm -rf $(OBJ_DIR)
	@make -s clean -C libft
	@make -s clean -C minilibx-linux >/dev/null 2>&1
	@echo "$(CYAN)Object files cleaned!$(RESET)"

# Nettoyage complet
fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@make -s fclean -C libft
	@echo "$(CYAN)Executable $(NAME) or $(NAME_BONUS) removed!$(RESET)"

# Recompiler à partir de zéro
re: fclean all

# Génération de la bibliothèque libft avec sortie masquée
libft:
	@make -s -C libft

# Génération de la bibliothèque minilibx avec sortie masquée
mlx:
	@make -s -C minilibx-linux all >/dev/null 2>&1

# Éviter les conflits avec des fichiers portant les noms des cibles
.PHONY: all clean fclean re libft mlx bonus
