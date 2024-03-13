#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game_data	*data;
	int i;

	data = (t_game_data *)malloc(sizeof(t_game_data));
	if (!data)
		return (NULL);
	data->required_score = 0;
	data->current_score = 0;

	// ft_printf("%d\n", data->required_score);

	read_map(argc, argv, &data);


	i = 0;
	while (i < data->height)
	{
		ft_printf("%s\n", data->map[i]);
		i++;
	}
	ft_printf("%d %d", (data)->height, (data)->width);
	// ft_printf("\n%d\n", data->required_score);

	free_ptr(data);
	return (0);
}
