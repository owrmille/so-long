#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_data	*data;
	int	success_flg = 0;
	int i;
	

	data = (t_game_data *)malloc(sizeof(t_game_data));
	if (!data)
		return (0);
	data->required_score = 0;
	data->current_score = 0;
	data->height = 0;
	data->width = 0;
	data->map = NULL;

	// ft_printf("%d\n", data->required_score);

	success_flg = read_map(argc, argv, &data);
	if (success_flg == 0)
		// map_error(&data);
	{
		ft_printf("ERROR");
		free_map(data);
		return (0);
	}
	success_flg = check_valid_map(data->map, data->height, data->width);
	if (success_flg == 0)
		// map_error(&data);
	{
		ft_printf("ERROR");
		free_map(data);
		return (0);
	}

	// ---just for me, delete later:
	i = 0;
	while (i < data->height)
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	ft_printf("%d %d", (data)->height, (data)->width);
	// ft_printf("\n%d\n", data->required_score);
	// ---just for me, delete later.

	free_map(data);
	return (0);
}
