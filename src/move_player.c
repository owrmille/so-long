#include "../so_long.h"

void	put_player(t_game_data **data, int col, int row)
{
	mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->textures[0], col * TILE_WIDTH, (row * TILE_WIDTH));
	(*data)->player_pos_x = col;
	(*data)->player_pos_y = row;
}

void	make_movement(t_game_data **data, int col, int row, char direction)
{
	int	old_col;
	int old_row;

	old_col = col;
	old_row = row;
	if ((*data)->map[row][col] == 'C') // if it is a coin, update score
		(*data)->current_score += 1;
	else if ((*data)->map[row][col] == 'E' && (*data)->required_score == (*data)->current_score) // if it is an exit and the player collected all coins
		end_game(data);
	else if ((*data)->map[row][col] == 'E') // if it is an exit and player did not collect every coin
		return ;
	(*data)->steps += 1; // update moves counter

	if (direction == '>')
		old_col = col - 1;
	else if (direction == '<')
		old_col = col + 1;
	else if (direction == 'v')
		old_row = row - 1; 
	else if (direction == '^')
		old_row = row + 1;
	(*data)->map[old_row][old_col] = '0'; // update map
	mlx_put_image_to_window((*data)->mlx, (*data)->win, (*data)->textures[4], old_col * TILE_WIDTH, old_row * TILE_WIDTH);

	(*data)->map[row][col] = 'P'; // update map
	put_player(data, col, row); // render player on the screen
}

void	move_player(t_game_data **data, int key)
{
	int		old_col;
	int		old_row;
	int		new_col;
	int		new_row;
	char	direction;

	old_col = (*data)->player_pos_x; // get player current position
	old_row = (*data)->player_pos_y; // get player current position
	if (key == 100 && (*data)->map[old_row][old_col + 1] != '1') // if d is pressed and next tile is not a wall
		{	
			make_movement(data, old_col + 1, old_row, '>');
        }
	if (key == 97 && (*data)->map[old_row][old_col - 1] != '1') // if a is pressed and previous tile is not a wall
		{	
			make_movement(data, old_col - 1, old_row, '<');
        }
	if (key == 119 && (*data)->map[old_row - 1][old_col] != '1') // if w is pressed and previous tile is not a wall
		{	
			make_movement(data, old_col, old_row - 1, '^');
        }
	if (key == 115 && (*data)->map[old_row + 1][old_col] != '1') // if s is pressed and next tile is not a wall
		{	
			make_movement(data, old_col, old_row + 1, 'v');
        }
}
