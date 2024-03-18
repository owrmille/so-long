
NAME	=	so_long

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -Imlx -g 

MLXFLAGS=	-L ./minilibx-linux -lmlx -lXext -lX11

LIBS	=	./libft/libft/libft.a

SRCS	=	so_long.c \
			./src/read_map.c \
			./src/check_valid_map.c \
			./src/check_valid_path.c \
			./src/utils.c \
			./src/utils_2.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): $(OBJS)
			make -C  ./minilibx-linux
			make -C  ./libft/libft
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

clean:
			make clean -C ./minilibx-linux
			make clean -C ./libft/libft
			rm -rf $(OBJS)
			
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re