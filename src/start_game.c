#include "../so_long.h"
void free_data(t_game_data *data) {
	if (data) {
		// Free the map
		if (data->map) {
			for (int i = 0; i < data->height; i++) {
				free(data->map[i]);
			}
			free(data->map);
			data->map = NULL;
		}

		// Free other dynamically allocated resources
		// Example:
		// if (data->background) {
		//     mlx_destroy_image(data->mlx, data->background);
		//     data->background = NULL;
		// }

		// Free the data structure itself
		free(data);
	}
}
void	build_images(t_render_v **var)
{
	build_wall(var);
	build_collectable(var);
	build_exit(var);
	build_player(var);
}

int	end_game(t_render_v **var, t_game_data **data)
{
	int	i;

	mlx_destroy_image((*var)->mlx, (*var)->textures[0]);
	// (*var)->textures[0] = NULL;
	mlx_destroy_image((*var)->mlx, (*var)->textures[1]);
	mlx_destroy_image((*var)->mlx, (*var)->textures[2]);
	mlx_destroy_image((*var)->mlx, (*var)->textures[3]);

	mlx_destroy_window((*var)->mlx, (*var)->win);
	mlx_destroy_display((*var)->mlx);

	if ((*var)->mlx)
	{
		free((*var)->mlx);
		(*var)->mlx = NULL;
	}

	if (*var)
	{
		free(*var);
		*var = NULL;
	}
	free_data(*data);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_render_v **var, t_game_data **data)
{
	ft_printf("Pressed key: %d\\n", keycode);
	if (keycode == 53 || keycode == 27 || keycode == 9 || keycode == 65307)
		end_game(var, data);
	// move_player(keycode, game);
	return (0);
}

void	*get_figure(t_render_v *var, char img_type)
{
	void	*figure;

	if (img_type == 'P')
		figure = var->textures[0];
	else if (img_type == 'C')
		figure = var->textures[1];
	else if (img_type == '1')
		figure = var->textures[2];
	else if (img_type == 'E')
		figure = var->textures[3];
	else
		figure = NULL;
	return (figure);
}

void	put_images(t_game_data *data, t_render_v *var)
{
	int			i;
	int			j;
	void	*figure;

	i = 0;
	j = 0;

	while (i < (data)->height)
	{
		while (j < (data)->width)
		{
			figure = get_figure(var, (data)->map[i][j]);
			if (figure)
				mlx_put_image_to_window(var->mlx, var->win, 
					figure, j * TILE_WIDTH, i * TILE_WIDTH);
			j++;
		}
		j = 0;
		i++;
	}
}

int	start_game(t_game_data **data)
{
	t_render_v	*var;
	int			w_width;
	int			w_height;

	var = malloc(sizeof(t_render_v));
	if (!var)
		return (0);

	var->mlx = mlx_init();
	if (!var->mlx)
		return (0);

	w_width = (*data)->width * TILE_WIDTH;
	w_height = (*data)->height * TILE_WIDTH;
	var->win = mlx_new_window(var->mlx, w_width, w_height, "SO LONG: nap time!");

	if (!var->win)
		return (free(var->mlx), 0);

	build_images(&var);
	put_images(*data, var);
	mlx_key_hook(var->win, key_hook, &var);
	mlx_hook(var->win, 17, 0, end_game, &var);
	mlx_loop(var->mlx);
	return (0);
}
