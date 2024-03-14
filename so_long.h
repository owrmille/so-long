#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include "./libft/libft/libft.h"

typedef struct s_game_data
{
	int		height;
	int		width;
	int		player_pos_x;
	int		player_pos_y;
	int		required_score;
	int		current_score;
	int		steps;
	char	**map;

}	t_game_data;

void	free_ptr(char *ptr);
void	free_ptr_ptr(char **ptr);
void	free_map(t_game_data *data);
int		find_symbol(char *s, char c);
int		ft_arrlen(char **arr);

int		map_line_len(char **map, int height);
int		map_error(t_game_data **data);

void	calculate_size(int fd, char **line, t_game_data **data);
int		store_map(char *file_name, char **line, t_game_data **data);
int		read_map(int argc, char **argv, t_game_data **data);

int		is_rectangular(char **map, int height, int width);
int		is_wall_surrounded(char **map, int height, int width);
int		is_full(char **map, int height, int width, int cnt[3]);
int		check_valid_map(char **map, int height, int width);

#endif