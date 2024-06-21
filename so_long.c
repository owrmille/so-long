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
	data->mlx = NULL;

	if (read_map(argc, argv, &data) == 0)
	{
		ft_printf("Check that you \n- pass two arguments: an executed file and a map\n"
					"- use .ber format for a map\n- use a non-empty map\n");
		return (map_error(&data));
	}
	if (check_valid_map(data->map, data->height, data->width) == 0)
	{
		ft_printf("Check that your map is \n- rectangular \n- surrounded by walls "
				"\n- contains 1x P, 1x E and at least 1x C"
				"\n- contains only symbols 0, 1, P, E, C\n");
		return (map_error(&data));
	}
	if (check_valid_path(data) == 0)
	{
		ft_printf("Check that there is a possible route in the map\n");
		return (map_error(&data));
	}

	start_game(&data);

	// ---just for me, delete later:
	// ft_printf("(*data)->player_pos (x,y): %d, %d\n", data->player_pos_x, data->player_pos_y);
	// print_map(data);
	// ft_printf("height: %d width: %d items: %d player_x: %d player_y: %d\n", (data)->height, (data)->width, data->required_score, data->player_pos_x, data->player_pos_y);
	// ---just for me, delete later.

	// free_map(data);
	return (0);
}
