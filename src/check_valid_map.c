#include "../so_long.h"

int	is_rectangular(char **map, int height, int width)
{
	if (ft_arrlen(map) != height)
		return (0);
	if (map_line_len(map, height) != width)
		return (0);
	return (1);
}

int	check_valid_map(char **map, int height, int width)
{
	if (!is_rectangular(map, height, width))
		return (0);
	return (1);
}
