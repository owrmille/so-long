NAME        = so_long
LIBFT       = ./libft/libft/libft.a
LIBFT_DIR   = ./libft/libft
MLX_DIR     = ./minilibx-linux

CC          = cc -Wextra -Werror -Wall
CFLAGS      = -Imlx -g

MLXFLAGS    = -L $(MLX_DIR) -lmlx -lXext -lX11

SRCS        = so_long.c \
              ./src/read_map.c \
              ./src/check_valid_map.c \
              ./src/check_valid_path.c \
              ./src/start_game.c \
              ./src/move_player.c \
              ./src/build_utils.c \
              ./src/utils.c \
              ./src/utils_2.c \
              temp.c

OBJS        = $(SRCS:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME)..."
	@echo "Checking libft submodule..."
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
        echo "Initializing libft submodule..."; \
        git submodule update --init --recursive libft; \
    else \
        echo "Updating libft submodule..."; \
        git submodule update --recursive libft; \
    fi
	@make -C $(LIBFT_DIR)

	@echo "Checking minilibx submodule..."
	@if [ ! -d "$(MLX_DIR)" ]; then \
        echo "Initializing minilibx submodule..."; \
        git submodule update --init --recursive minilibx-linux; \
    else \
        echo "Updating minilibx submodule..."; \
        git submodule update --recursive minilibx-linux; \
    fi
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLXFLAGS) -o $@

clean:
	@echo "Cleaning up..."
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)
	@rm -rf $(OBJS)
			
fclean: clean
	@rm -rf $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
