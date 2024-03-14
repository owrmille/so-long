#include "../so_long.h"

void	fill(char **map, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[cur.y][cur.x] != to_fill)
		return ;

	map[cur.y][cur.x] = 'F';
	fill(map, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(map, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(map, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(map, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **map, t_point size, t_point begin)
{
	fill(map, size, begin, map[begin.y][begin.x]);
}

// int	find_path(t_game_data *data)
// {

// }
