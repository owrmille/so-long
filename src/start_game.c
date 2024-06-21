#include "../so_long.h"

void	build_images(t_game_data **data)
{
	build_ground(data);
	build_wall(data);
	build_collectable(data);
	build_exit(data);
	build_player(data);
}

int	end_game(t_game_data **data)
{
	mlx_destroy_image((*data)->mlx, (*data)->textures[0]);
	mlx_destroy_image((*data)->mlx, (*data)->textures[1]);
	mlx_destroy_image((*data)->mlx, (*data)->textures[2]);
	mlx_destroy_image((*data)->mlx, (*data)->textures[3]);
	mlx_destroy_image((*data)->mlx, (*data)->textures[4]);

	mlx_destroy_window((*data)->mlx, (*data)->win);
	mlx_destroy_display((*data)->mlx);

	if ((*data)->mlx)
	{
		free((*data)->mlx);
		(*data)->mlx = NULL;
	}
	free_data(*data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_game_data **data)
{
	// ft_printf("Pressed key: %d\n", keycode);
	if (keycode == 119 || keycode == 115 || keycode == 100 || keycode == 97)
		move_player(data, keycode);
	if (keycode == 53 || keycode == 27 || keycode == 9 || keycode == 65307)
		end_game(data);
	return (0);
}

void	*get_figure(t_game_data **data, char img_type)
{
	void	*figure;

	if (img_type == 'P')
		figure = (*data)->textures[0];
	else if (img_type == 'C')
		figure = (*data)->textures[1];
	else if (img_type == '1')
		figure = (*data)->textures[2];
	else if (img_type == 'E')
		figure = (*data)->textures[3];
	else if (img_type == '0')
		figure = (*data)->textures[4];
	else
		figure = NULL;
	return (figure);
}

void	put_images(t_game_data **data) // here I should use **data or *data?
{
	int			i;
	int			j;
	void	*figure;

	i = 0;
	j = 0;

	while (i < (*data)->height)
	{
		while (j < (*data)->width)
		{
			figure = get_figure(data, (*data)->map[i][j]);
			if (figure)
				mlx_put_image_to_window((*data)->mlx, (*data)->win, 
					figure, j * TILE_WIDTH, i * TILE_WIDTH);
			j++;
		}
		j = 0;
		i++;
	}
}

int	start_game(t_game_data **data)
{
	int			w_width;
	int			w_height;

	(*data)->mlx = mlx_init();
	if (!(*data)->mlx)
		return (0);

	w_width = (*data)->width * TILE_WIDTH;
	w_height = (*data)->height * TILE_WIDTH;
	(*data)->win = mlx_new_window((*data)->mlx, w_width, w_height, "SO LONG: nap time!");

	if (!(*data)->win)
		return (free((*data)->mlx), 0);

	build_images(data);
	put_images(data);
	mlx_key_hook((*data)->win, key_hook, data); // using just data increase indirectly and definitely lost, but decrease still reachable
	mlx_hook((*data)->win, 17, 0, end_game, data); // same
	mlx_loop((*data)->mlx);
	return (0);
}
