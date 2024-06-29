#include "so_long.h"

void	init_data(t_game_data **data)
{
	(*data)->height = 0;
	(*data)->width = 0;
	(*data)->required_score = 0;
	(*data)->current_score = 0;
	(*data)->steps = 0;
	(*data)->exit_count = 0;
	(*data)->game_over = 0;
	(*data)->map = NULL;
	(*data)->mlx = NULL;
	(*data)->win = NULL;
}

int	main(int argc, char **argv)
{
	t_game_data	*data;

	data = (t_game_data *)malloc(sizeof(t_game_data));
	if (!data)
		return (0);
	init_data(&data);
	if (read_map(argc, argv, &data) == 0)
	{
		error_msg_1();
		return (map_error(&data));
	}
	if (check_valid_map(data->map, data->height, data->width) == 0)
	{
		error_msg_2();
		return (map_error(&data));
	}
	if (check_valid_path(data) == 0)
	{
		error_msg_3();
		return (map_error(&data));
	}
	start_game(&data);
	return (0);
}
