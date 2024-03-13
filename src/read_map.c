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
	// - 1 because of '\n' in every line
	while (*line)
	{
		// (*data)->required_score += find_symbol(*line, 'C');
		free_ptr_ptr(line);
		*line = get_next_line(fd);
		i++;
		// exits += find_symbol(*line, 'E');
		// players += find_symbol(*line, 'P');
	}
	free_ptr_ptr(line);
	(*data)->height = i;
}

void	store_map(char *file_name, char **line, t_game_data **data)
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

		if ((*data)->map[i][(*data)->width] == '\n')
		{
			(*data)->map[i][(*data)->width] = '\0';
		}
		free_ptr_ptr(line);
		*line = get_next_line(fd);
		i++;
		// exits += find_symbol(*line, 'E');
		// players += find_symbol(*line, 'P');
	}
	free_ptr_ptr(line);
	(*data)->map[i] = NULL;
}

int	read_map(int argc, char **argv, t_game_data **data)
{
	int		fd;
	char	*line;
	char	*map;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);

	calculate_size(fd, &line, data);
	(*data)->map = (char **)malloc(sizeof(char *) * ((*data)->height + 1));
	store_map(argv[1], &line, data);
	// check_valid_map();
	// ft_printf("LEN %d", ft_strlen((*data)->map[0]));

	close(fd);

	return (0);
}
