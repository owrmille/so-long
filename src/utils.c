#include "../so_long.h"

int	find_symbol(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			count += 1;
		}
		i++;
	}
	return (count);
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

void	free_ptr(char *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

void	free_ptr_ptr(char **ptr)
{
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void free_data(t_game_data *data)
{
	if (data) {
		if (data->map) {
			for (int i = 0; i < data->height; i++) {
				if (data->map[i])
				{
					free(data->map[i]);
					data->map[i] = NULL;
				}
			}
			if (data->map)
			{
				free(data->map);
				data->map = NULL;
			}
		}
		free(data);
		data = NULL;
	}
}