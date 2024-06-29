#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft/libft.h"

# define TILE_WIDTH 64

# define GRASS "./textures/grass.xpm"
# define CHICKEN "./textures/chicken.xpm"
# define CHICK "./textures/chick.xpm"
# define ROCK "./textures/rock.xpm"
# define HOUSE "./textures/house.xpm"

typedef struct s_game_data
{
	int		height;
	int		width;
	int		player_pos_x;
	int		player_pos_y;
	int		required_score;
	int		current_score;
	int		steps;
	int		exit_count;
	int		game_over;
	char	**map;
	void	*mlx;
	void	*win;
	void	*textures[5];
}	t_game_data;

/* src/utils.c */
int		find_symbol(char *s, char c);
int		ft_arrlen(char **arr);
void	free_ptr(char *ptr);
void	free_ptr_ptr(char **ptr);
void	free_data(t_game_data *data);

/* src/utils_2.c */
int		map_line_len(char **map, int height);

/* src/error_messages.c */
int		map_error(t_game_data **data);
void	error_msg_1(void);
void	error_msg_2(void);
void	error_msg_3(void);

/* src/read_map.c*/
void	calculate_size(int fd, char **line, t_game_data **data);
void	store_player_coordinates(int i, char *line, t_game_data **data);
int		store_map(char *file_name, char **line, t_game_data **data);
int		read_map(int argc, char **argv, t_game_data **data);

/* src/check_valid_map.c */
int		is_rectangular(char **map, int height, int width);
int		is_wall_surrounded(char **map, int height, int width);
int		is_full(char **map, int height, int width, int cnt[3]);
int		check_valid_map(char **map, int height, int width);

/* src/check_valid_path.c */
int		find_directions(t_game_data *data_copy, int cur_x, int cur_y);
int		find_path(t_game_data *data_copy, int cur_x, int cur_y);
void	copy_plain_data(t_game_data *data, t_game_data **data_copy);
int		copy_structure(t_game_data *data, t_game_data **data_copy);
int		check_valid_path(t_game_data *data);

/* src/build_utils.c */
void	build_ground(t_game_data **data);
void	build_player(t_game_data **data);
void	build_collectable(t_game_data **data);
void	build_wall(t_game_data **data);
void	build_exit(t_game_data **data);

/* src/start_game.c */
void	build_images(t_game_data **data);
int		key_hook(int keycode, t_game_data **data);
void	*get_figure(t_game_data **data, char img_type);
void	put_images(t_game_data **data);
int		start_game(t_game_data **data);

/* src/move_player.c*/
int		update_row(int row, char direction);
int		update_col(int col, char direction);
void	put_player(t_game_data **data, int row, int col);
void	make_movement(t_game_data **data, int col, int row, char direction);
void	move_player(t_game_data **data, int key);

/* erc/end_game.c */
int		end_game(t_game_data **data);

/* so_long.c */
void	init_data(t_game_data **data);

#endif