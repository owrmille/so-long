#include "../so_long.h"

void	put_player(t_game_data **game, t_render_v **var, int width, int height, char direction)
{
    char *file;

    file = CHICKEN;
	if (direction == '>')
    {
        ft_printf("INSIDE put_player");
		mlx_put_image_to_window((*var)->mlx, (*var)->win, (*var)->textures[0], 0 + width * 32, 0 + (height * 32));
    }
	(*game)->player_pos_x = width;
	(*game)->player_pos_y = height;
}

void	move_right(t_game_data **game, t_render_v **var, int i, int j)
{
	if ((*game)->map[j][i + 1] == 'C') // if it is a coin, update score
		(*game)->current_score += 1;
	else if ((*game)->map[j][i + 1] == 'E' && (*game)->required_score == (*game)->current_score) // if it is an exit and the player collected all coins
		end_game(var, game);
	else if ((*game)->map[j][i + 1] == 'E') // if it is an exit and player did not collect every coin
		return ;
	(*game)->steps += 1; // update moves counter
	(*game)->map[j][i] = '0'; // update map
	(*game)->map[j][i + 1] = 'P'; // update map
	put_player((*game), var, i + 1, j, '>'); // render player on the screen
	mlx_put_image_to_window((*var)->mlx, (*var)->win, (*var)->textures[4], 0 + i * 32, 0 + (j * 32)); // render ground on the screen
}

void	move_player(t_game_data **game, t_render_v **var, int key)
{
	int		i;
	int		j;

    if (game == NULL || *game == NULL) {
        ft_printf("move_player, Error: game pointer is NULL\n");
        return;
    }

    ft_printf("(*game)->player_pos_x: %d", (*game)->player_pos_x);
	i = (*game)->player_pos_x; // get player current position
	j = (*game)->player_pos_y; // get player current position
	if (key == 100 && (*game)->map[j][i + 1] != '1') // if d is pressed and next tile is not a wall
		{
            move_right(game, var, i, j);
        }
}
