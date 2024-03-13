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
int		find_symbol(char *s, char c);

void	calculate_size(int fd, char **line, t_game_data **data);
void	store_map(char *file_name, char **line, t_game_data **data);
int		read_map(int argc, char **argv, t_game_data **data);

#endif