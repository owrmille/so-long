#include "../so_long.h"

// int	init_window(t_game_data *data, t_render_v **v)
// {
// 	int			w_width;
// 	int			w_height;

// 	(*v)->mlx = mlx_init();
// 	if (!(*v)->mlx)
// 		return (0);
// 	w_width = data->width * TILE_WIDTH;
// 	w_height = data->height * TILE_WIDTH;
// 	(*v)->win = mlx_new_window((*v)->mlx, w_width, w_height, "Time to go home");
// 	if (!(*v)->win)
// 		return (free((*v)->mlx), 0);
// 	mlx_destroy_window((*v)->mlx, (*v)->win);
// 	mlx_destroy_display((*v)->mlx);
// 	free((*v)->mlx);
// 	free((*v));
// 	return (0);
// }




// int on_destroy(t_render_v *var)
// {
// 	mlx_destroy_window(var->mlx, var->win);
// 	mlx_destroy_display(var->mlx);
// 	free(var->mlx);
// 	exit(0);
// 	return (0);
// }

// int on_keypress(int keysym, t_render_v *var)
// {
// 	(void)var;
// 	ft_printf("Pressed key: %d\\n", keysym);
// 	return (0);
// }

void	build_images(t_game_data **data, t_render_v **var)
{
	build_wall(data, var);
	build_collectable(data, var);
	build_exit(data, var);
	build_player(data, var);
}

// void	free_textures(t_game_data **data, t_render_v **var)
// {
// 	mlx_destroy_image((*var)->mlx, (*data)->player);
// 	mlx_destroy_image((*var)->mlx, (*data)->collectable);
// 	mlx_destroy_image((*var)->mlx, (*data)->wall);
// 	mlx_destroy_image((*var)->mlx, (*data)->exit);
// }

int	end_game(t_render_v **var)
{
	// mlx_destroy_image((*var)->mlx, (*data)->player);
	// mlx_destroy_image((*var)->mlx, (*data)->collectable);
	// mlx_destroy_image((*var)->mlx, (*data)->wall);
	// mlx_destroy_image((*var)->mlx, (*data)->exit);
	mlx_destroy_window((*var)->mlx, (*var)->win);
	mlx_destroy_display((*var)->mlx);
	// free_textures(data, var);
	// free_render_sructure(var):
	free((*var)->mlx);
	free(*var);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_render_v **var)
{
	ft_printf("Pressed key: %d\\n", keycode);
	if (keycode == 53 || keycode == 27 || keycode == 9 || keycode == 65307)
		end_game(var);
	// move_player(keycode, game);
	return (0);
}

void	*get_figure(t_game_data *data, char img_type)
{
	void	*figure;

	if (img_type == 'P')
		figure = data->player;
	else if (img_type == 'C')
		figure = data->collectable;
	else if (img_type == '1')
		figure = data->wall;
	else if (img_type == 'E')
		figure = data->exit;
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

	while (i < data->height)
	{
		while (j < data->width)
		{
			figure = get_figure(data, data->map[i][j]);
			if (figure)
				mlx_put_image_to_window(var->mlx, var->win, 
					figure, j * TILE_WIDTH, i * TILE_WIDTH);
			j++;
		}
		j = 0;
		i++;
	}
}

int	start_game(t_game_data *data)
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

	w_width = data->width * TILE_WIDTH;
	w_height = data->height * TILE_WIDTH;
	var->win = mlx_new_window(var->mlx, w_width, w_height, "SO LONG: nap time!");

	if (!var->win)
		return (free(var->mlx), 0);

	build_images(&data, &var);
	put_images(data, var);
	mlx_key_hook(var->win,  key_hook, &var);
	mlx_hook(var->win, 17, 0, end_game, &var);
	mlx_loop(var->mlx);
	return (0);
}





// int	start_game(t_game_data *data)
// {
// 	t_render_v	*v;
// 	int			w_width;
// 	int			w_height;

// 	v = malloc(sizeof(t_render_v));
// 	if (!v)
// 		return (0);
// 	v->mlx = mlx_init();
// 	if (!v->mlx)
// 		return (0);
// 	w_width = data->width * TILE_WIDTH;
// 	w_height = data->height * TILE_WIDTH;
// 	v->win = mlx_new_window(v->mlx, w_width, w_height, "SO LONG: nap time!");
// 	if (!v->win)
// 		return (free(v->mlx), 0);
// 	// mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
 
// 	build_images(&data, &v);
// 	mlx_put_image_to_window(v->mlx, v->win, data->player, data->player_pos_x * TILE_WIDTH, data->player_pos_y * TILE_WIDTH);
// 	mlx_loop(v->mlx);
// 	// mlx_loop_hook(v->mlx, )
// 	// if (data->exit)
// 	// {
// 	// 	free(data->exit);
// 	// 	data->exit = NULL;
// 	// }

// 	// mlx_loop(v->mlx);
	
// 	// free(v->win);
// 	// free(v);
// 	// init_window(data, &v);
// 	// build_figures();
// 	// if (v->mlx)
// 	// {
// 	// 	free(v->mlx);
// 	// 	v->mlx = NULL;
// 	// }
// 	// if (v)
// 	// {
// 	// 	free(v);
// 	// 	v = NULL;
// 	// }
// 	// free(v->mlx);
// 	// free(v->win);
// 	// free(v->textures[0]);
// 	// free(v->textures);
// 	// free(v);
// 	// mlx_destroy_window((v)->mlx, (v)->win);
// 	mlx_destroy_display((v)->mlx);
// 	free(v->mlx);
// 	free(v);
// 	// exit(0);
// 	return (0);
// }
