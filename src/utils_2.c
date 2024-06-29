#include "../so_long.h"

int	map_line_len(char **map, int height)
{
	int	i;
	int	prev_len;

	i = 0;
	prev_len = ft_strlen(map[i]);
	while (i < height)
	{
		if (prev_len != ft_strlen(map[i]))
			return (-1);
		prev_len = ft_strlen(map[i]);
		i++;
	}
	return (prev_len);
}
