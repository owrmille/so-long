#include "../so_long.h"

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
	int	x;
	int	y;

	data_copy->player_pos_x = cur_x;
	data_copy->player_pos_y = cur_y;
	if (data_copy->current_score == data_copy->required_score 
		&& data_copy->exit_count == 1)
		return (1);
	x = data_copy->player_pos_x;
	y = data_copy->player_pos_y;
	if (y < 0 || y >= (data_copy)->height || x < 0 || x >= (data_copy)->width
		|| (data_copy)->map[y][x] == '1')
		return (0);
	if ((data_copy)->map[y][x] == 'C')
		(data_copy)->current_score++;
	if ((data_copy)->map[y][x] == 'E')
		(data_copy)->exit_count++;
	(data_copy)->map[y][x] = '1';
	if (find_directions(data_copy, x, y))
		return (1);
	return (0);
}

void	copy_plain_data(t_game_data *data, t_game_data **data_copy)
{
	(*data_copy)->height = data->height;
	(*data_copy)->width = data->width;
	(*data_copy)->player_pos_x = data->player_pos_x;
	(*data_copy)->player_pos_y = data->player_pos_y;
	(*data_copy)->required_score = data->required_score;
	(*data_copy)->current_score = data->current_score;
	(*data_copy)->steps = data->steps;
	(*data_copy)->exit_count = data->exit_count;
	(*data_copy)->game_over = data->game_over;
}

int	copy_structure(t_game_data *data, t_game_data **data_copy)
{
	int	i;

	*data_copy = (t_game_data *)malloc(sizeof(t_game_data));
	if (data_copy == NULL)
		return (0);
	(*data_copy)->map = (char **)malloc(sizeof(char *) * (data->height + 1));
	if ((*data_copy)->map == NULL)
		return (0);
	memcpy((*data_copy)->map, data->map, (sizeof(char *) * (data->height + 1)));
	i = 0;
	while (i < data->height)
	{
		(*data_copy)->map[i] = ft_strdup(data->map[i]);
		if ((*data_copy)->map[i] == NULL)
			return (0);
		i++;
	}
	copy_plain_data(data, data_copy);
	return (1);
}

int	check_valid_path(t_game_data *data)
{
	t_game_data	*data_copy;

	if (copy_structure(data, &data_copy) == 0)
		return (0);
	if (find_path(data_copy, data_copy->player_pos_x, data_copy->player_pos_y))
	{
		free_data(data_copy);
		return (1);
	}
	free_data(data_copy);
	return (0);
}
