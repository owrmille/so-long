#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft/libft.h"

# define TILE_WIDTH 40

# define CHICKEN "./textures/chicken.xpm"
# define CHICK "./textures/chick.xpm"
# define ROCK "./textures/rock.xpm"
# define HOUSE "./textures/house.xpm"

# define GREEN 0xB6D7A8

# define WIN_MSG "You won :)"
# define LOSE_MSG "You lose :p"

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
	void	*end_img;
	void	*wall;
	void	*exit;
	void	*player;
	void	*collectable;
	void	*background;
}	t_game_data;

typedef struct s_render_v
{
	void	*mlx;
	void	*win;
	void	*textures[5];
}	t_render_v;

void	free_ptr(char *ptr);
void	free_ptr_ptr(char **ptr);
void	free_map(t_game_data *data);
int		find_symbol(char *s, char c);
int		ft_arrlen(char **arr);

int		map_line_len(char **map, int height);
int		map_error(t_game_data **data);

void	calculate_size(int fd, char **line, t_game_data **data);
void	store_player_coordinates(int i, char *line, t_game_data **data);
int		store_map(char *file_name, char **line, t_game_data **data);
int		read_map(int argc, char **argv, t_game_data **data);

int		is_rectangular(char **map, int height, int width);
int		is_wall_surrounded(char **map, int height, int width);
int		is_full(char **map, int height, int width, int cnt[3]);
int		check_valid_map(char **map, int height, int width);

int		find_directions(t_game_data *data_copy, int cur_x, int cur_y);
int		find_path(t_game_data *data_copy, int cur_x, int cur_y);
void	copy_plain_data(t_game_data *data, t_game_data **data_copy);
int		copy_structure(t_game_data *data, t_game_data **data_copy);
int		check_valid_path(t_game_data *data);

void	build_player(t_game_data **data, t_render_v **var);
void	build_collectable(t_game_data **data, t_render_v **var);
void	build_wall(t_game_data **data, t_render_v **var);
void	build_exit(t_game_data **data, t_render_v **var);

void	build_images(t_game_data **data, t_render_v **var);
int		start_game(t_game_data *data);

void	print_map(t_game_data *data);
void	print_difference(t_game_data *data, t_game_data *data_copy);

#endif