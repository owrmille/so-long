#include "../so_long.h"

void	put_player(t_game_data **data, int col, int row)
{
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->textures[0], col * TILE_WIDTH, (row * TILE_WIDTH));
	(*data)->player_pos_x = col;
	(*data)->player_pos_y = row;
}

int	update_row(int row, char direction)
{
	int	r;

	r = row;
	if (direction == 'v')
		r = row - 1; 
	else if (direction == '^')
		r = row + 1;
	return (r);
}

int	update_col(int col, char direction)
{
	int	c;

	c = col;
	if (direction == '>')
		c = col - 1; 
	else if (direction == '<')
		c = col + 1;
	return (c);
}

void	make_movement(t_game_data **data, int col, int row, char direction)
{
	int	old_col;
	int	old_row;

	old_col = col;
	old_row = row;
	if ((*data)->map[row][col] == 'C')
		(*data)->current_score += 1;
	else if ((*data)->map[row][col] == 'E' 
		&& (*data)->required_score == (*data)->current_score)
	{
		ft_printf("Number of steps: %d\n", (*data)->steps + 1);
		end_game(data);
	}
	else if ((*data)->map[row][col] == 'E')
		return ;
	(*data)->steps += 1;
	ft_printf("Number of steps: %d\n", (*data)->steps);
	old_col = update_col(col, direction);
	old_row = update_row(row, direction);
	(*data)->map[old_row][old_col] = '0';
	mlx_put_image_to_window((*data)->mlx, (*data)->win,
		(*data)->textures[4], old_col * TILE_WIDTH, old_row * TILE_WIDTH);
	(*data)->map[row][col] = 'P';
	put_player(data, col, row);
}

void	move_player(t_game_data **data, int key)
{
	int		old_col;
	int		old_row;

	old_col = (*data)->player_pos_x;
	old_row = (*data)->player_pos_y;
	if (key == 100 && (*data)->map[old_row][old_col + 1] != '1')
	{
		make_movement(data, old_col + 1, old_row, '>');
	}
	if (key == 97 && (*data)->map[old_row][old_col - 1] != '1')
	{
		make_movement(data, old_col - 1, old_row, '<');
	}
	if (key == 119 && (*data)->map[old_row - 1][old_col] != '1')
	{
		make_movement(data, old_col, old_row - 1, '^');
	}
	if (key == 115 && (*data)->map[old_row + 1][old_col] != '1')
	{
		make_movement(data, old_col, old_row + 1, 'v');
	}
}
