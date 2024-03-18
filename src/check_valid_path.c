#include "../so_long.h"

// void	fill(char **map, t_point size, t_point cur)
// {
// 	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
// 		|| map[cur.y][cur.x] != '0' || map[cur.y][cur.x] != 'C')
// 		return ;

// 	map[cur.y][cur.x] = '1';
// 	fill(map, size, (t_point){cur.x - 1, cur.y});
// 	fill(map, size, (t_point){cur.x + 1, cur.y});
// 	fill(map, size, (t_point){cur.x, cur.y - 1});
// 	fill(map, size, (t_point){cur.x, cur.y + 1});
// }

// void	flood_fill(char **map, t_point size, t_point begin)
// {
// 	fill(map, size, begin);
// }

int	find_directions(t_game_data *data_copy, int cur_x, int cur_y)
{
	if (find_path(data_copy, cur_x + 1, cur_y))
		return (1);
	if (find_path(data_copy, cur_x - 1, cur_y))
		return (1);
	if (find_path(data_copy, cur_x, cur_y + 1))
		return (1);
	if (find_path(data_copy, cur_x, cur_y - 1))
		return (1);
	return (0);
}

int	find_path(t_game_data *data_copy, int cur_x, int cur_y)
{
	(data_copy)->player_pos_x = cur_x;
	(data_copy)->player_pos_y = cur_y;
	ft_printf("\npl_x:%d pl_y: %d\n", (data_copy)->player_pos_x, (data_copy)->player_pos_y);
	ft_printf("\ncur_x:%d cur_y: %d\n\n", cur_x, cur_y);
	if ((data_copy)->current_score == (data_copy)->required_score 
		&& (data_copy)->exit_count == 1)
	{
		// ft_printf("1");
		return (1);
	}
	
	if ((data_copy)->player_pos_y < 0 || (data_copy)->player_pos_y >= (data_copy)->height 
		|| (data_copy)->player_pos_x < 0 || (data_copy)->player_pos_x >= (data_copy)->width
		|| (data_copy)->map[(data_copy)->player_pos_y][(data_copy)->player_pos_x] == '1')
		// || ((data_copy)->map[(data_copy)->player_pos_y][(data_copy)->player_pos_x] != '0' 
		// && (data_copy)->map[(data_copy)->player_pos_y][(data_copy)->player_pos_x] != 'C'
		// && (data_copy)->map[(data_copy)->player_pos_y][(data_copy)->player_pos_x] != 'P'))
	{
		ft_printf("\nSymbol: %c\n", (data_copy)->map[(data_copy)->player_pos_y][(data_copy)->player_pos_x]);
		// ft_printf("2");
		return (0);
	}

	if ((data_copy)->map[(data_copy)->player_pos_y][(data_copy)->player_pos_x] == 'C')
		(data_copy)->current_score++;
	if ((data_copy)->map[(data_copy)->player_pos_y][(data_copy)->player_pos_x] == 'E')
		(data_copy)->exit_count++;
	(data_copy)->map[(data_copy)->player_pos_y][(data_copy)->player_pos_x] = '1';
	if (find_directions(data_copy, (data_copy)->player_pos_x, (data_copy)->player_pos_y))
	{
		// ft_printf("3");
		return (1);
	}
	// ft_printf("4");
	return (0);
}

// int	check_valid_path(t_game_data_copy *data_copy)
// {
// 	if (find_path(data_copy, data_copy->player_pos_x, data_copy->player_pos_y))
// 		return (1);
// 	return (0);
// }

int	check_valid_path(t_game_data *data)
{
	t_game_data	*data_copy;
	// int i;

	data_copy = (t_game_data *)malloc(sizeof(t_game_data));
	if (data_copy == NULL)
		return (0);
	(data_copy)->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if (data_copy->map == NULL)
		return (0);
	ft_memcpy(data_copy->map, data->map, data->height * data->width * sizeof(char));
	data_copy->height = data->height;
	data_copy->width = data->width;
	data_copy->player_pos_x = data->player_pos_x;
	data_copy->player_pos_y = data->player_pos_y;
	data_copy->required_score = data->required_score;
	data_copy->current_score = data->current_score;
	data_copy->steps = data->steps;
	data_copy->exit_count = data->exit_count;
	data_copy->game_over = data->game_over;
	ft_printf("\nData: %p \nData_copy: %p\n", data, data_copy);
	if (find_path(data_copy, data_copy->player_pos_x, data_copy->player_pos_y))
	{
		// i = 0;
		// while (i < data_copy->height)
		// {
		// 	ft_printf("%s\n", data_copy->map[i]);
		// 	i++;
		// }
		return (1);
	}
	return (0);
}

// int	check_valid_path(t_game_data *data) {
// 	t_game_data *data_copy;
// 	int i;

// 	// Allocate memory for data_copy
// 	data_copy = (t_game_data *)malloc(sizeof(t_game_data));
// 	if (data_copy == NULL)
// 		return (0);

// 	// Copy the contents of data into data_copy
// 	ft_memcpy(data_copy, data, sizeof(t_game_data));
// 	ft_memcpy(data_copy->map, data->map, sizeof(data->map));

// 	// Print memory addresses of data and data_copy for debugging
// 	ft_printf("\nData: %p \nData_copy: %p\n", data, data_copy);

// 	// Print map data from data for debugging
// 	ft_printf("Map data in data:\n");
// 	for (i = 0; i < data->height; i++) {
// 		ft_printf("%s\n", data->map[i]);
// 	}

// 	// Check if find_path works with data_copy
// 	if (find_path(data_copy, data_copy->player_pos_x, data_copy->player_pos_y)) {
// 		// Print map data from data after find_path for debugging
// 		ft_printf("Map data in data after find_path:\n");
// 		for (i = 0; i < data->height; i++) {
// 			ft_printf("%s\n", data->map[i]);
// 		}
// 		return (1);
// 	}

// 	// Free the memory allocated for data_copy
// 	free(data_copy);

// 	return (0);
// }

