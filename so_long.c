#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_data	*data;
	int i;

	data = (t_game_data *)malloc(sizeof(t_game_data));
	if (!data)
		return (0);
	data->required_score = 0;
	data->current_score = 0;
	data->height = 0;
	data->width = 0;
	data->map = NULL;
	if (read_map(argc, argv, &data) == 0)
		return (map_error(&data));
	if (check_valid_map(data->map, data->height, data->width) == 0)
		return (map_error(&data));

	// ---just for me, delete later:
	i = 0;
	while (i < data->height)
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	ft_printf("height: %d width: %d items: %d", (data)->height, (data)->width, data->required_score);
	// ---just for me, delete later.
	free_map(data);
	return (0);
}
