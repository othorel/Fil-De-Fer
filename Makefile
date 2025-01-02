SRCS		=	src/close.c    \
				src/draw.c     \
				src/read.c	   \
				src/isometrie.c\
				src/main.c

OBJ_DIR		=	obj
OBJS		=	$(OBJ_DIR)/close.o $(OBJ_DIR)/draw.o $(OBJ_DIR)/main.o $(OBJ_DIR)/read.o $(OBJ_DIR)/isometrie.o  

HEADERS		=	includes/fdf.h     

NAME		=	fdf

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror -g -I./libft/srcs -Iincludes

FLAGS		=	-lm -L./minilibx-linux -lmlx -L./libft -lft -lXext -lX11

# Règle pour générer chaque fichier .o dans obj/
$(OBJ_DIR)/%.o: src/%.c $(HEADERS)
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@

all:		libft mlx $(NAME)

$(NAME):	$(OBJS) $(HEADERS)
			$(CC) $(OBJS) -o $(NAME) $(FLAGS)

clean:
			rm -rf $(OBJ_DIR)
			make clean -C libft
			make clean -C minilibx-linux

fclean:		clean
			make fclean -C libft
			rm -rf $(NAME)

re:			fclean all

libft:
			@make -C libft

mlx:
			@make -C minilibx-linux

.PHONY:		all clean fclean re libft mlx


