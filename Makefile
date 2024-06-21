NAME		=	so_long
LIBFT 		= ./libft/libft/libft.a
LIBFT_DIR 	= ./libft/libft
MLX_DIR 	= ./minilibx-linux

CC			=	cc -Wextra -Werror -Wall
CFLAGS		=	-Imlx -g

MLXFLAGS	=	-L $(MLX_DIR) -lmlx -lXext -lX11

SRCS	=	so_long.c \
			./src/read_map.c \
			./src/check_valid_map.c \
			./src/check_valid_path.c \
			./src/start_game.c \
			./src/move_player.c \
			./src/build_utils.c \
			./src/utils.c \
			./src/utils_2.c \
			temp.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME): 	$(OBJS) 
	@make -C  $(LIBFT_DIR)
	@make -C  $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $@

clean:
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)
	rm -rf $(NAME) $(OBJS)
			
fclean:	clean
	rm -rf $(LIBFT)

re:		fclean all

.PHONY: all clean fclean re