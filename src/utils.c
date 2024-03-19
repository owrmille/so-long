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


void	free_map(t_game_data *data)
{
	int	i;

	i = 0;
	while (i < (data)->height)
	{
		if ((data)->map[i])
		{
			free((data)->map[i]);
		// free((data)->map[i]);
			(data)->map[i] = NULL;
		}
		i++;
	}
	if (data->map)
	{
		free(data->map);
		data->map = NULL;
	}
	//
	if (data->player)
	{
		free(data->player);
		data->player = NULL;
	}
	//
	if (data)
	{
		free(data);
		data = NULL;
	}
}
