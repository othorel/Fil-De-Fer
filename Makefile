SRCS		=	src/controls_utils.c    \
				src/controls.c          \
				src/convert_map_utils.c \
				src/convert_map.c       \
				src/draw_matrix.c       \
				src/draw_order.c        \
				src/get_matrix.c        \
				src/get_next_matrix.c   \
				src/get_rotor_matrix.c  \
				src/mlx.c               \
				src/main.c              \
				libft/srcs/get_next_line.c 

HEADERS		= 	includes/fdf.h          \
				includes/keyboard.h

NAME		=	fdf

CC			=	cc

CFLAGS		= -Wall -Wextra -Werror -g -I./libft/srcs

FLAGS = -lm -Llib/minilibx-linux -lmlx -Llibft -lft -lXext -lX11


%.o: %.c ${HEADERS} libft/libft.a
			${CC} -c $< -o $@

all:		libft mlx ${NAME}

${NAME}:	${SRCS:.c=.o} ${HEADERS}
			${CC} ${SRCS:.c=.o} -o ${NAME} ${FLAGS}

clean:
			rm -rf ${SRCS:.c=.o}
			make clean -C libft
			make clean -C minilibx-linux

fclean:		clean
			make fclean -C libft
			rm -rf ${NAME}

re:			fclean all

libft:
			@make -C libft

mlx:
			@make -C minilibx-linux

.PHONY:		all clean fclean re libft mlx
