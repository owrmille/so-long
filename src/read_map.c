#include "../so_long.h"

void	calculate_size(int fd, char **line, t_game_data **data)
{
	int	i;

	i = 0;
	*line = get_next_line(fd);
	if (*line)
	{
		(*data)->width = ft_strlen(*line) - 1; 
	}
	while (*line)
	{
		free_ptr_ptr(line);
		*line = get_next_line(fd);
		i++;
	}
	free_ptr_ptr(line);
	(*data)->height = i;
}

void	store_player_coordinates(int i, char *line, t_game_data **data)
{
	int	j;

	j = 0;
	while (j < ft_strlen(line))
	{
		if (line[j] == 'P')
		{
			(*data)->player_pos_x = j;
			(*data)->player_pos_y = i;
		}
		j++;
	}
}

int	store_map(char *file_name, char **line, t_game_data **data)
{
	int	i;
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	*line = get_next_line(fd);
	i = 0;
	while (*line)
	{
		(*data)->map[i] = strdup(*line);
		(*data)->required_score += find_symbol(*line, 'C');
		if (find_symbol(*line, 'P'))
			store_player_coordinates(i, *line, data);
		if ((*data)->map[i][ft_strlen(*line) - 1] == '\n')
		{
			(*data)->map[i][ft_strlen(*line) - 1] = '\0';
		}
		free_ptr_ptr(line);
		*line = get_next_line(fd);
		i++;
	}
	free_ptr_ptr(line);
	(*data)->map[i] = NULL;
	return (1);
}

int	read_map(int argc, char **argv, t_game_data **data)
{
	int		fd;
	char	*line;

	if (argc != 2 
		|| !ft_strrchr(argv[1], '.') 
		|| ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4))
	{
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		return (0);
	}
	calculate_size(fd, &line, data);
	if ((*data)->height == 0)
		return (0);
	(*data)->map = (char **)malloc(sizeof(char *) * ((*data)->height + 1));
	store_map(argv[1], &line, data);
	close(fd);
	return (1);
}
