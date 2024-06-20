#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_data	*data;

	data = (t_game_data *)malloc(sizeof(t_game_data));
	if (!data)
		return (0);
	data->height = 0;
	data->width = 0;
	data->required_score = 0;
	data->current_score = 0;
	data->steps = 0;
	data->exit_count = 0;
	data->game_over = 0;
	data->map = NULL;
	// data->background = NULL;
	// data->wall = NULL;
	// data->collectable = NULL;
	// data->exit = NULL;
	// data->player = NULL;
	// data->mlx = NULL;
	// data->win = NULL;

	if (read_map(argc, argv, &data) == 0)
		return (map_error(&data));
	if (check_valid_map(data->map, data->height, data->width) == 0)
		return (map_error(&data));
	if (check_valid_path(data) == 0)
	{
		return (map_error(&data));
	}

	// print_map(data);
	start_game(&data);
	// ---just for me, delete later:
	ft_printf("(*game)->player_pos (x,y): %d, %d\n", data->player_pos_x, data->player_pos_y);
	print_map(data);
	ft_printf("height: %d width: %d items: %d player_x: %d player_y: %d\n", (data)->height, (data)->width, data->required_score, data->player_pos_x, data->player_pos_y);
	// ---just for me, delete later.

	// free_map(data);
	return (0);
}
