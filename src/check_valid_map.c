#include "../so_long.h"

int	is_rectangular(char **map, int height, int width)
{
	if (ft_arrlen(map) != height)
		return (0);
	if (map_line_len(map, height) != width)
		return (0);
	return (1);
}

int	is_wall_surrounded(char **map, int height, int width)
{
	int	j;

	j = 0;
	while (j < width)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
		{
			return (0);
		}
		j++;
	}
	j = 1;
	while (j < height - 1)
	{
		if (map[j][0] != '1' || map[j][width - 1] != '1')
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	is_full(char **map, int height, int width, int cnt[3])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < height)
	{
		while (j < width)
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'E'
				&& map[i][j] != 'P' && map[i][j] != 'C')
				return (0);
			if (map[i][j] == 'E')
				cnt[0] += 1;
			else if (map[i][j] == 'P')
				cnt[1] += 1;
			else if (map[i][j] == 'C')
				cnt[2] += 1;
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	check_valid_map(char **map, int height, int width)
{
	int	cnt[3];

	cnt [0] = 0;
	cnt [1] = 0;
	cnt [2] = 0;
	if (!is_rectangular(map, height, width)
		|| !is_wall_surrounded(map, height, width)
		|| !is_full(map, height, width, cnt))
		return (0);
	if (cnt[0] != 1 || cnt[1] != 1 || cnt[2] < 1)
	{
		return (0);
	}
	return (1);
}
